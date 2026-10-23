#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

// Function to check if a word value is a triangle number
bool isTriangleNumber(int value) {
    if (value <= 0) return false;
    
    // Using the quadratic formula check: 8*x + 1 must be a perfect square
    long long discriminant = 8LL * value + 1;
    long long root = std::round(std::sqrt(discriminant));
    
    return (root * root == discriminant) && ((root - 1) % 2 == 0);
}

// Function to calculate the word value (A=1, B=2, ..., Z=26)
int getWordValue(const std::string& word) {
    int value = 0;
    for (char c : word) {
        if (std::isalpha(c)) {
            value += (std::toupper(c) - 'A' + 1);
        }
    }
    return value;
}

int main() {
    // Paste the raw comma-separated word sequence inside the string stream
    std::string raw_data = R"(0042_words.txt)"; // Word list truncated for brevity; refer to Project Euler Problem 42 for the full dataset.

    std::stringstream ss(raw_data);
    std::string token;
    int triangle_word_count = 0;

    // Parse out words split by commas
    while (std::getline(ss, token, ',')) {
        // Strip out the quote characters
        std::string word = "";
        for (char c : token) {
            if (c != '"') {
                word += c;
            }
        }
        
        int value = getWordValue(word);
        if (isTriangleNumber(value)) {
            triangle_word_count++;
        }
    }

    std::cout << "Number of triangle words in this segment: " << triangle_word_count << std::endl;
    return 0;
}
