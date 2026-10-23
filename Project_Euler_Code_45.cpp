#include <iostream>
#include <cmath>

// Function to check if a number is pentagonal
bool isPentagonal(long long x) {
    long long val = 24 * x + 1;
    long long root = std::round(std::sqrt(val));
    
    return (root * root == val) && ((root + 1) % 6 == 0);
}

int main() {
    // Start searching from the next hexagonal index after 143
    long long n = 144; 
    
    while (true) {
        long long hn = n * (2 * n - 1);
        
        if (isPentagonal(hn)) {
            long long triangle_index = 2 * n - 1;
            long long pentagonal_index = (std::round(std::sqrt(24 * hn + 1)) + 1) / 6;

            std::cout << "Found matching number: " << hn << "\n";
            std::cout << "Indices: T_" << triangle_index 
                      << " = P_" << pentagonal_index 
                      << " = H_" << n << std::endl;
            break;
        }
        n++;
    }
    
    return 0;
}
