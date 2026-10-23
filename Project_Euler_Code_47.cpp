#include <iostream>
#include <vector>

const int LIMIT = 1000000; // Search limit large enough to contain the answer

int main() {
    std::vector<int> prime_factors_count(LIMIT, 0);

    // Modified Sieve of Eratosthenes to count distinct prime factors
    for (int i = 2; i < LIMIT; ++i) {
        if (prime_factors_count[i] == 0) { // i is prime
            for (int j = i; j < LIMIT; j += i) {
                prime_factors_count[j]++;
            }
        }
    }

    // Scan for 4 consecutive numbers with exactly 4 distinct prime factors
    int consecutive_count = 0;
    for (int i = 2; i < LIMIT; ++i) {
        if (prime_factors_count[i] == 4) {
            consecutive_count++;
            if (consecutive_count == 4) {
                int first_num = i - 3;
                std::cout << "The four consecutive numbers are:\n";
                std::cout << first_num << ", " << first_num + 1 << ", " 
                          << first_num + 2 << ", " << first_num + 3 << "\n\n";
                std::cout << "The first of these numbers is: " << first_num << std::endl;
                return 0;
            }
        } else {
            consecutive_count = 0; // Reset counter if the streak breaks
        }
    }

    std::cout << "Increase LIMIT to find the solution." << std::endl;
    return 0;
}
