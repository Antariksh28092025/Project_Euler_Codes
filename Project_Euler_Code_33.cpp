#include <iostream>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int final_numerator = 1;
    int final_denominator = 1;

    // Loop through all possible 2-digit numerators and denominators
    for (int d = 11; d < 100; d++) {
        for (int n = 10; n < d; n++) {
            // Exclude trivial multiples of 10
            if (n % 10 == 0 && d % 10 == 0) {
                continue;
            }

            int n_tens = n / 10;
            int n_ones = n % 10;
            int d_tens = d / 10;
            int d_ones = d % 10;

            // Case 1: The ones digit of numerator matches the tens digit of denominator
            // Check if: n / d == n_tens / d_ones
            // To avoid floating-point issues, use cross-multiplication: n * d_ones == d * n_tens
            if (n_ones == d_tens && n_ones != 0) {
                if (n * d_ones == d * n_tens) {
                    final_numerator *= n;
                    final_denominator *= d;
                }
            }

            // Case 2: The tens digit of numerator matches the ones digit of denominator
            // Check if: n / d == n_ones / d_tens
            // Equivalent to: n * d_tens == d * n_ones
            if (n_tens == d_ones && n_tens != 0) {
                if (n * d_tens == d * n_ones) {
                    final_numerator *= n;
                    final_denominator *= d;
                }
            }
        }
    }

    // Simplify the product fraction to its lowest terms
    int common_divisor = gcd(final_numerator, final_denominator);
    int simplified_denominator = final_denominator / common_divisor;

    std::cout << "The value of the denominator in lowest common terms is: " 
              << simplified_denominator << std::endl;

    return 0;
}
