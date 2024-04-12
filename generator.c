#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define RANGE_MIN -2147483648
#define RANGE_MAX 2147483647

void generateUniqueRandomNumbers(int *arr, int size) {
    srand(time(NULL)); // Seed the random number generator
    int i, j, exists;

    for (i = 0; i < size; ++i) {
        int num;
        do {
            exists = 0;
            num = (rand() % (RANGE_MAX - RANGE_MIN + 1)) + RANGE_MIN;
            for (j = 0; j < i; ++j) {
                if (arr[j] == num) {
                    exists = 1;
                    break;
                }
            }
        } while (exists); // Generate until unique
        arr[i] = num;
    }
}

int main() {
    int numbers[MAX_NUMBERS];
    generateUniqueRandomNumbers(numbers, MAX_NUMBERS);

    // Print the generated numbers
    for (int i = 0; i < MAX_NUMBERS; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
