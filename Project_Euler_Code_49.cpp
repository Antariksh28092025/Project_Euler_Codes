#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Helper function to check if two integers are permutations of each other
bool isPermutation(int a, int b) {
    std::string strA = std::to_string(a);
    std::string strB = std::to_string(b);
    std::sort(strA.begin(), strA.end());
    std::sort(strB.begin(), strB.end());
    return strA == strB;
}

int main() {
    const int LIMIT = 10000;
    std::vector<bool> is_prime(LIMIT, true);
    
    // Sieve of Eratosthenes to precompute primes up to 9999
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < LIMIT; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < LIMIT; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // Iterate through all possible 4-digit starting values
    for (int a = 1000; a < LIMIT - 6660; ++a) {
        int b = a + 3330;
        int c = b + 3330;

        // Skip the sequence already given in the problem statement
        if (a == 1487) continue;

        // Verify if all three terms are prime
        if (is_prime[a] && is_prime[b] && is_prime[c]) {
            // Verify if they are permutations of each other
            if (isPermutation(a, b) && isPermutation(b, c)) {
                std::cout << "The three terms are: " << a << ", " << b << ", " << c << "\n";
                std::cout << "Concatenated 12-digit number: " << a << b << c << std::endl;
                return 0;
            }
        }
    }

    return 0;
}
