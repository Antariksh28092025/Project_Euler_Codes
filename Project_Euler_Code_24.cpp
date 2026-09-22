#include <iostream>
#include <stdio.h>
#include <stdint.h>

#define LEN 10

int main(void) {
    uint8_t i, j, temp;
    char arr[11] = "0123456789";

    for (uint32_t count = 1; count < 1000000; count++) {

        // Find the rightmost element that is greater than its previous element
        // i - 1 will be the 1st pivot
        for (i = LEN - 1; i > 0 && arr[i - 1] >= arr[i]; i--) {
        }

        // Find the smallest rightmost element that is greater than the 1st pivot
        // this will be the 2nd pivot
        for (j = LEN - 1; arr[j] <= arr[i - 1]; j--) {
        }

        temp = arr[i - 1];
        arr[i - 1] = arr[j];
        arr[j] = temp;

        // Sorting the substring/subarray to the right of the 1st pivot position
        // in ascending order
        // by swapping both ends of the substring, then squeezing the ends
        // until they meet/cross
        for (j = LEN - 1; i < j; i++, j--) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    puts(arr);

    return 0;
}