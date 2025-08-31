#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define MAX_WAITING_CUSTOMERS 5
// Shared resources
int waiting_customers = 0; // Number of waiting customers
pthread_mutex_t mutex;
pthread_cond_t barber_ready, customer_ready;
void* barber(void* arg) {
while (1) {
pthread_mutex_lock(&mutex);
// If there are no customers, barber sleeps
while (waiting_customers == 0) {
printf("Barber is sleeping...\n");
pthread_cond_wait(&customer_ready, &mutex);
}
// Cutting hair
waiting_customers--;
printf("Barber is cutting hair. %d customers left in the waiting area.\n",
waiting_customers);
pthread_cond_signal(&barber_ready); // Signal the customer to sit in the chair
pthread_mutex_unlock(&mutex);
// Simulate cutting hair time
sleep(3); // Barber cuts hair for 3 seconds
}return NULL;
}
void* customer(void* arg) {
pthread_mutex_lock(&mutex);
if (waiting_customers < MAX_WAITING_CUSTOMERS) {
waiting_customers++;
printf("Customer arrived and is waiting. %d customers in the waiting area.\n",
waiting_customers);
pthread_cond_signal(&customer_ready); // Wake up the barber if necessary
pthread_cond_wait(&barber_ready, &mutex); // Wait until the barber is ready
printf("Customer is getting a haircut.\n");
} else {
printf("Customer leaves because there are no available seats.\n");
}
pthread_mutex_unlock(&mutex);
return NULL;
}
int main() {
pthread_t barber_thread, customer_thread[10];
// Initialize the mutex and condition variables
pthread_mutex_init(&mutex, NULL);
pthread_cond_init(&barber_ready, NULL);
pthread_cond_init(&customer_ready, NULL);
// Create the barber thread
pthread_create(&barber_thread, NULL, barber, NULL);
// Simulate customers arriving at different times
for (int i = 0; i < 10; i++) {
sleep(rand() % 2); // Random delay between customer arrivals
pthread_create(&customer_thread[i], NULL, customer, NULL);
}
// Wait for customer threads to finish
for (int i = 0; i < 10; i++) {
pthread_join(customer_thread[i], NULL);
}
// Join the barber threadpthread_join(barber_thread, NULL);
// Cleanup
pthread_mutex_destroy(&mutex);
pthread_cond_destroy(&barber_ready);
pthread_cond_destroy(&customer_ready);
return 0;
}
