#include <iostream>
#include <string>
#include <vector>

int main() {
    constexpr int limit = 1'000'000;

    // Sieve of Eratosthenes
    std::vector<bool> isPrime(limit, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p < limit; ++p) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple < limit; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    int count = 0;

    for (int n = 2; n < limit; ++n) {
        if (!isPrime[n]) continue;

        std::string digits = std::to_string(n);
        bool circular = true;

        for (std::size_t i = 0; i < digits.size(); ++i) {
            int rotation = std::stoi(digits);

            if (!isPrime[rotation]) {
                circular = false;
                break;
            }

            // Move the first digit to the end.
            digits = digits.substr(1) + digits[0];
        }

        if (circular) {
            ++count;
        }
    }

    std::cout << count << '\n';
}