#include <stdio.h>

#define MAXFACT 100
#define ARRAYLEN 160

int main(void) {
    int i, j, k;
    int carry;
    int numArray[ARRAYLEN] = {0};
    int tempArray[2][ARRAYLEN] = {0};
    int temp;
    int sum = 0;

    /* Put MAXFACT into numArray, backwards. */
    for (i = MAXFACT, j = 0; i > 0; i /= 10, j++) {
        numArray[j] = i % 10;
    }

    /* MAXFACT! = MAXFACT * (MAXFACT - 1) * ... * 2 */
    for (i = MAXFACT - 1; i > 1; i--) {
        carry = 0;

        /* Clear the temporary result array. */
        for (j = 0; j < ARRAYLEN; j++) {
            tempArray[1][j] = 0;
        }

        /* Multiply numArray by i. */
        for (j = 0; j < ARRAYLEN; j++) {
            temp = (numArray[j] * i) + carry;

            tempArray[1][j] = temp % 10;
            carry = temp / 10;
        }

        /* Copy the temporary result back to numArray. */
        for (k = 0; k < ARRAYLEN; k++) {
            numArray[k] = tempArray[1][k];
        }
    }

    /* Find the first non-zero digit. */
    for (i = ARRAYLEN - 1; i > 0 && numArray[i] == 0; i--) {
    }

    /* Print factorial and calculate digit sum. */
    for (; i >= 0; i--) {
        printf("%d", numArray[i]);
        sum += numArray[i];
    }

    printf("\nSum: %d\n", sum);

    return 0;
} 

////Method 2 
// #include <stdio.h>

// #define MAXFACT 100
// #define ARRAYLEN 160

// int main(void) {
//     int i, j;
//     int carry;
//     int numArray[ARRAYLEN] = {0};
//     int temp;
//     int sum = 0;

//     /* Start with 1. */
//     numArray[0] = 1;

//     /* Multiply the stored number by every integer from 2 through 100. */
//     for (i = 2; i <= MAXFACT; i++) {
//         carry = 0;

//         for (j = 0; j < ARRAYLEN; j++) {
//             temp = numArray[j] * i + carry;

//             numArray[j] = temp % 10;
//             carry = temp / 10;
//         }
//     }

//     /* Print without leading zeroes and add the digits. */
//     for (i = ARRAYLEN - 1; i >= 0; i--) {
//         if (numArray[i] != 0) {
//             break;
//         }
//     }

//     for (; i >= 0; i--) {
//         printf("%d", numArray[i]);
//         sum += numArray[i];
//     }

//     printf("\nSum: %d\n", sum);

//     return 0;
// }