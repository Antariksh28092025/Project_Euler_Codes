#include <iostream>
#include <string>

// Function to find the n-th digit of Champernowne's constant
int getDigitAt(long long n) {
    long long digits_in_bucket = 1;
    long long count_of_numbers = 9;
    long long start_number = 1;

    // Determine the range/bucket the n-th digit falls into
    while (n > digits_in_bucket * count_of_numbers) {
        n -= digits_in_bucket * count_of_numbers;
        digits_in_bucket++;
        count_of_numbers *= 10;
        start_number *= 10;
    }

    // Identify the specific number containing the target digit
    long long target_number = start_number + (n - 1) / digits_in_bucket;

    // Identify the specific index within that number (0-indexed from the left)
    int digit_index = (n - 1) % digits_in_bucket;

    // Extract the digit
    std::string num_str = std::to_string(target_number);
    return num_str[digit_index] - '0';
}

int main() {
    // Array of the target indices given in the expression
    long long targets[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
    long long product = 1;

    std::cout << "Extracted digits:\n";
    for (long long target : targets) {
        int digit = getDigitAt(target);
        std::cout << "d_" << target << " = " << digit << "\n";
        product *= digit;
    }

    std::cout << "\nFinal Product: " << product << std::endl;

    return 0;
}
