#include <iostream>
#include <string>

// Function to get the letter count of a number from 1 to 999
int get_letter_count(int n) {
    // Arrays representing the lengths of the words
    // ones[0] = 0 (empty string for 0)
    int ones[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4}; // one(3), two(3), three(5), four(4), five(4), six(3), seven(5), eight(5), nine(4)
    int teens[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8}; // ten(3), eleven(6), twelve(6), thirteen(8), fourteen(8), fifteen(7), sixteen(7), seventeen(9), eighteen(8), nineteen(8)
    int tens[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6}; // twenty(6), thirty(6), forty(5), fifty(5), sixty(5), seventy(7), eighty(6), ninety(6)

    int count = 0;

    // Handle hundreds place
    if (n >= 100) {
        count += ones[n / 100]; // "one", "two", etc.
        count += 7;             // "hundred" (7 letters)
        if (n % 100 != 0) {
            count += 3;         // "and" (3 letters)
        }
        n %= 100;               // Reduce to the last two digits
    }

    // Handle tens and ones places
    if (n >= 10 && n < 20) {
        count += teens[n - 10];
    } else {
        count += tens[n / 10];  // Tens digit
        count += ones[n % 10];  // Ones digit
    }

    return count;
}

int main() {
    int total_letters = 0;

    // Loop through numbers 1 to 999
    for (int i = 1; i <= 999; ++i) {
        total_letters += get_letter_count(i);
    }

    // Add the letters for 1000 ("one thousand")
    // "one" (3) + "thousand" (8) = 11 letters
    total_letters += 11;

    std::cout << "Total letters used from 1 to 1000: " << total_letters << std::endl;

    return 0;
}
