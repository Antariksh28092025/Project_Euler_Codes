#include <iostream>
#include <array>

int main() {
    constexpr int factorial[] = {
        1,       // 0!
        1,       // 1!
        2,       // 2!
        6,       // 3!
        24,      // 4!
        120,     // 5!
        720,     // 6!
        5040,    // 7!
        40320,   // 8!
        362880   // 9!
    };

    int sum = 0;

    // 1! and 2! are excluded by the problem statement.
    for (int n = 3; n <= 7 * factorial[9]; ++n) {
        int digitFactorialSum = 0;

        for (int remaining = n; remaining > 0; remaining /= 10) {
            digitFactorialSum += factorial[remaining % 10];
        }

        if (digitFactorialSum == n) {
            std::cout << n << '\n';
            sum += n;
        }
    }

    std::cout << "Sum: " << sum << '\n';
}