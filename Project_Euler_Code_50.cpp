#include <iostream>
#include <vector>

const int LIMIT = 1000000;

int main() {
    // 1. Sieve of Eratosthenes to find all primes up to 1,000,000
    std::vector<bool> is_prime(LIMIT, true);
    is_prime[0] = is_prime[1] = false; // Fixed typo here
    
    std::vector<int> primes;
    for (int p = 2; p < LIMIT; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
            for (int i = 2 * p; i < LIMIT; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // 2. Precompute consecutive prefix sums of primes
    std::vector<long long> prefix_sum;
    prefix_sum.push_back(0);
    for (int prime : primes) {
        long long next_sum = prefix_sum.back() + prime;
        if (next_sum > LIMIT) break; // No need to track sums exceeding 1 million
        prefix_sum.push_back(next_sum);
    }

    int max_terms = 0;
    long long max_prime = 0;
    int num_tracked_sums = prefix_sum.size();

    // 3. Sliding window to find the longest sequence adding up to a prime
    for (int i = 0; i < num_tracked_sums; ++i) {
        for (int j = i + max_terms + 1; j < num_tracked_sums; ++j) {
            long long current_sum = prefix_sum[j] - prefix_sum[i];
            
            if (current_sum >= LIMIT) break;
            
            if (is_prime[current_sum]) {
                max_terms = j - i;
                max_prime = current_sum;
            }
        }
    }

    std::cout << "The prime below one-million with the most consecutive primes is: " << max_prime << "\n";
    std::cout << "It is a sum of " << max_terms << " consecutive primes." << std::endl;

    return 0;
}
