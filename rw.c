#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int read_count = 0;
int data = 0;
pthread_mutex_t mutex; // for read_count
sem_t wrt;
// for writing access
void* reader(void* arg) {
int id = *((int*)arg);
pthread_mutex_lock(&mutex);read_count++;
if(read_count == 1)
sem_wait(&wrt); // First reader locks writer
pthread_mutex_unlock(&mutex);
// Reading
printf("Reader %d is reading data = %d\n", id, data);
sleep(1);
pthread_mutex_lock(&mutex);
read_count--;
if(read_count == 0)
sem_post(&wrt); // Last reader unlocks writer
pthread_mutex_unlock(&mutex);
free(arg);
return NULL;
}
void* writer(void* arg) {
int id = *((int*)arg);
sem_wait(&wrt); // Wait for exclusive access
// Writing
data++;
printf("Writer %d wrote data = %d\n", id, data);
sleep(2);
sem_post(&wrt); // Release access
free(arg);
return NULL;
}
int main() {
int choice, id = 1;
pthread_t tid[100]; // Store threads
int t_index = 0;
// Initialize synchronization primitives
pthread_mutex_init(&mutex, NULL);
sem_init(&wrt, 0, 1);
printf("\n--- Readers-Writers Problem ---\n");
printf("1: Create Reader\n2: Create Writer\n0: Exit\n");while(1) {
printf("\nEnter choice: ");
scanf("%d", &choice);
if (choice == 1) {
int *arg = malloc(sizeof(*arg));
*arg = id;
pthread_create(&tid[t_index++], NULL, reader, arg);
id++;
}
else if (choice == 2) {
int *arg = malloc(sizeof(*arg));
*arg = id;
pthread_create(&tid[t_index++], NULL, writer, arg);
id++;
}
else if (choice == 0) {
printf("Exiting...\n");
break;
}
else {
printf("Invalid choice.\n");
}
}
// Join all threads before exiting
for (int i = 0; i < t_index; i++) {
pthread_join(tid[i], NULL);
}
pthread_mutex_destroy(&mutex);
sem_destroy(&wrt);
return 0;
}
