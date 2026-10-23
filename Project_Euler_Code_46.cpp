#include <iostream>
#include <vector>
#include <cmath>

const int LIMIT = 10000;
std::vector<bool> is_prime(LIMIT, true);

// Initialize Sieve of Eratosthenes
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < LIMIT; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < LIMIT; i += p)
                is_prime[i] = false;
        }
    }
}

// Check if Goldbach's conjecture holds for a given odd composite number
bool satisfiesConjecture(int n) {
    for (int k = 1; 2 * k * k < n; ++k) {
        int remainder = n - 2 * k * k;
        if (is_prime[remainder]) {
            return true; // Found a valid prime + 2*k^2 representation
        }
    }
    return false;
}

int main() {
    sieve();

    // Loop through odd numbers starting from 9
    for (int n = 9; n < LIMIT; n += 2) {
        // Skip prime numbers to only test composite numbers
        if (is_prime[n]) continue;

        if (!satisfiesConjecture(n)) {
            std::cout << "The smallest odd composite counterexample is: " << n << std::endl;
            break;
        }
    }

    return 0;
}
