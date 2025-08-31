#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>#define THINKING 0
#define HUNGRY 1
#define EATING 2
int *state;
pthread_mutex_t *mutex;
pthread_cond_t *cond;
int num_philosophers;
void test(int i) {
// Check if philosopher can eat
int left = (i + num_philosophers - 1) % num_philosophers;
int right = (i + 1) % num_philosophers;
if (state[i] == HUNGRY && state[left] != EATING && state[right] != EATING) {
state[i] = EATING;
printf("Philosopher %d is eating.\n", i + 1);
pthread_cond_signal(&cond[i]); // Notify philosopher to eat
}
}
void take_forks(int i) {
pthread_mutex_lock(&mutex[i]);
state[i] = HUNGRY;
printf("Philosopher %d is hungry.\n", i + 1);
test(i); // Try to eat immediately
while (state[i] != EATING) {
pthread_cond_wait(&cond[i], &mutex[i]); // Wait until philosopher can eat
}
pthread_mutex_unlock(&mutex[i]);
}
void put_forks(int i) {
pthread_mutex_lock(&mutex[i]);
state[i] = THINKING;
printf("Philosopher %d is thinking.\n", i + 1);
int left = (i + num_philosophers - 1) % num_philosophers;
int right = (i + 1) % num_philosophers;// Test neighbors if they can eat
test(left);
test(right);
pthread_mutex_unlock(&mutex[i]);
}
void* philosopher(void* num) {
int i = *((int*)num);
while (1) {
sleep(rand() % 5 + 1); // Thinking
take_forks(i);
// Hungry -> Eat
sleep(rand() % 5 + 1); // Eating
put_forks(i);
// Finished eating -> Thinking
}
return NULL;
}
int main() {
printf("Enter the number of philosophers: ");
scanf("%d", &num_philosophers);
state = (int*)malloc(num_philosophers * sizeof(int));
mutex = (pthread_mutex_t*)malloc(num_philosophers * sizeof(pthread_mutex_t));
cond = (pthread_cond_t*)malloc(num_philosophers * sizeof(pthread_cond_t));
pthread_t *threads = (pthread_t*)malloc(num_philosophers * sizeof(pthread_t));
// Initialize the states, mutexes, and condition variables
for (int i = 0; i < num_philosophers; i++) {
state[i] = THINKING;
pthread_mutex_init(&mutex[i], NULL);
pthread_cond_init(&cond[i], NULL);
}
// Create philosopher threads
for (int i = 0; i < num_philosophers; i++) {
int *arg = malloc(sizeof(*arg));
*arg = i;
pthread_create(&threads[i], NULL, philosopher, arg);
}
// Join all threads
for (int i = 0; i < num_philosophers; i++) {
pthread_join(threads[i], NULL);}
// Clean up resources
free(state);
free(mutex);
free(cond);
free(threads);
return 0;
}
