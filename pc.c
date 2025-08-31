#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OPERATIONS 20

int main() {
    srand(time(NULL)); // Seed random number generator
    int count = 0; // Current number of items in the buffer

    for (int i = 0; i < NUM_OPERATIONS; i++) {
        int decision = rand() % 2; // 0: produce, 1: consume

        if (decision == 0) {
            // Attempt to produce
            count++;
            printf("Produced an item. ");
        } else {
            // Attempt to consume
            if (count > 0) {
                count--;
                printf("Consumed an item. ");
            } else {
                printf("Buffer empty, cannot consume. ");
            }
        }

        // Show current number after every loop
        printf("Current number of items in buffer: %d\n", count);
    }

    return 0;
}
