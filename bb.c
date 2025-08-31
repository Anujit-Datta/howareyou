#include <stdio.h>
#include <stdlib.h>
int *buffer;
int size;
int in = 0, out = 0;int count = 0;
void produce() {
if(count == size) {
printf("Buffer is full! Cannot produce more.\n");
return;
}
int item;
printf("Enter item to produce: ");
scanf("%d", &item);
buffer[in] = item;
printf("Produced: %d\n", item);
in = (in + 1) % size;
count++;
}
void consume() {
if(count == 0) {
printf("Buffer is empty! Nothing to consume.\n");
return;
}
int item = buffer[out];
printf("Consumed: %d\n", item);
out = (out + 1) % size;
count--;
}
int main() {
int choice;
printf("Enter buffer size: ");
scanf("%d", &size);
buffer = (int*)malloc(size * sizeof(int));
if(buffer == NULL) {
perror("Buffer allocation failed");
exit(1);
}printf("\n--- Producer-Consumer Menu ---\n");
printf("1: Produce\n2: Consume\n0: Exit\n");
while(1) {
printf("\nEnter choice: ");
scanf("%d", &choice);
switch(choice) {
case 1:
produce();
break;
case 2:
consume();
break;
case 0:
printf("Exiting...\n");
free(buffer);
exit(0);
default:
printf("Invalid choice. Try again.\n");
}
}
return 0;
}
