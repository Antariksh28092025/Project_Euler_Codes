#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Vector to store individual digits in reverse order.
    // Start with 2^0 = 1
    std::vector<int> digits;
    digits.push_back(1);

    // Multiply by 2 exactly 1000 times
    for (int i = 0; i < 1000; ++i) {
        int carry = 0;
        
        // Multiply each existing digit by 2 and add the carry
        for (size_t j = 0; j < digits.size(); ++j) {
            int product = digits[j] * 2 + carry;
            digits[j] = product % 10;  // Keep the single digit
            carry = product / 10;      // Move the remainder to the carry
        }
        
        // If there's a leftover carry at the end, append it as new digits
        while (carry > 0) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Sum all the digits stored in our vector
    int sum = 0;
    for (int digit : digits) {
        sum += digit;
    }

    // Output the final result
    std::cout << "The sum of the digits of 2^1000 is: " << sum << std::endl;

    return 0;
}
