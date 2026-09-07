#include <iostream>
using namespace std;

int largestPalindrome(int n) {
    int upperLimit = 1;
    for (int k = 0; k < n; k++) upperLimit *= 10;
    upperLimit -= 1;

    int lowerLimit = 1;
    for (int k = 1; k < n; k++) lowerLimit *= 10;

    int maxProduct = 0;

    for (int i = upperLimit; i >= lowerLimit; i--) {
        // No later product can beat the current answer.
        if (i * i < maxProduct) break;

        for (int j = i; j >= lowerLimit; j--) {
            int product = i * j;

            if (product < maxProduct) break;

            int number = product;
            int reverse = 0;

            while (number != 0) {
                reverse = reverse * 10 + number % 10;
                number /= 10;
            }

            if (product == reverse) {
                maxProduct = product;
            }
        }
    }

    return maxProduct;
}

int main() {
    cout << largestPalindrome(3) << '\n';
}