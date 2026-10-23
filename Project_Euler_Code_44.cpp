#include <iostream>
#include <cmath>
#include <vector>

// Function to check if a number is pentagonal
bool isPentagonal(long long x) {
    if (x < 1) return false;
    long long val = 24 * x + 1;
    long long root = std::round(std::sqrt(val));
    
    // Check if it's a perfect square and satisfies the quadratic inverse condition
    return (root * root == val) && ((root + 1) % 6 == 0);
}

int main() {
    std::vector<long long> pentagonal;
    pentagonal.push_back(0); // 0-index placeholder

    bool found = false;
    long long k = 1;

    while (!found) {
        long long pk = k * (3 * k - 1) / 2;
        pentagonal.push_back(pk);

        // Iterate backwards through previously calculated pentagonal numbers
        for (long long j = k - 1; j > 0; --j) {
            long long pj = pentagonal[j];
            long long diff = pk - pj;
            long long sum = pk + pj;

            if (isPentagonal(diff) && isPentagonal(sum)) {
                std::cout << "Found pair: P_" << k << " (" << pk << ") and P_" << j << " (" << pj << ")\n";
                std::cout << "Difference D = " << diff << std::endl;
                found = true;
                break;
            }
        }
        k++;
    }

    return 0;
}
