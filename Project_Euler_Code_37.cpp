#include <iostream>
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

    int sum = 0;
    int count = 0;

    for (int n = 11; n < limit; ++n) {
        if (!isPrime[n]) continue;

        bool truncatable = true;

        // Remove digits from the right: 3797 -> 379 -> 37 -> 3
        for (int x = n / 10; x > 0; x /= 10) {
            if (!isPrime[x]) {
                truncatable = false;
                break;
            }
        }

        // Remove digits from the left: 3797 -> 797 -> 97 -> 7
        int divisor = 1;
        while (divisor <= n / 10) {
            divisor *= 10;
        }

        for (int x = n % divisor; x > 0; divisor /= 10, x %= divisor) {
            if (!isPrime[x]) {
                truncatable = false;
                break;
            }
        }

        if (truncatable) {
            sum += n;
            ++count;
        }
    }

    std::cout << "Count: " << count << '\n';
    std::cout << "Sum: " << sum << '\n';
}