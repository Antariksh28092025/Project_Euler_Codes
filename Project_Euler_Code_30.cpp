#include <iostream>

// Helper function to calculate the 5th power of a digit
int fifthPower(int digit) {
    return digit * digit * digit * digit * digit;
}

int main() {
    int totalSum = 0;
    
    // Upper limit established by 6 * 9^5 = 354294
    int upperBound = 6 * 59049; 
    
    std::cout << "Numbers matching the criteria:\n";
    
    // Start from 2 because 1 is not a sum
    for (int i = 2; i <= upperBound; ++i) {
        int temp = i;
        int sumOfPowers = 0;
        
        while (temp > 0) {
            int digit = temp % 10;
            sumOfPowers += fifthPower(digit);
            temp /= 10;
        }
        
        // If the sum matches the number, include it
        if (sumOfPowers == i) {
            std::cout << i << "\n";
            totalSum += i;
        }
    }
    
    std::cout << "\nThe sum of all these numbers is: " << totalSum << std::endl;
    
    return 0;
}
