#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

// Function to check if a number is prime
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    long long limit = std::sqrt(n);
    for (long long i = 5; i <= limit; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    // Start with the largest possible 7-digit pandigital arrangement
    std::string digits = "7654321";
    
    // std::prev_permutation automatically cycles through arrangements in descending order
    do {
        long long current_num = std::stoll(digits);
        
        if (isPrime(current_num)) {
            std::cout << "The largest n-digit pandigital prime is: " << current_num << std::endl;
            return 0; // Terminate early since the first one found is the largest
        }
    } while (std::prev_permutation(digits.begin(), digits.end()));
    
    std::cout << "No pandigital prime found in the 7-digit range." << std::endl;
    return 0;
}
