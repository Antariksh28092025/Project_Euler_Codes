#include <iostream>
#include <string>
#include <array>

bool isPandigital(const std::string& s) {
    if (s.size() != 9) return false;

    std::array<bool, 10> seen{};

    for (char c : s) {
        if (c == '0' || seen[c - '0']) return false;
        seen[c - '0'] = true;
    }

    return true;
}

int main() {
    int largest = 0;

    // n must be greater than 1, so the concatenation needs at least
    // two products. A base below 10000 keeps the first product under 5 digits;
    // larger bases cannot fit two products into a 9-digit result.
    for (int base = 1; base < 10'000; ++base) {
        std::string concatenated;

        for (int multiplier = 1; concatenated.size() < 9; ++multiplier) {
            concatenated += std::to_string(base * multiplier);
        }

        if (isPandigital(concatenated)) {
            int value = std::stoi(concatenated);
            if (value > largest) largest = value;
        }
    }

    std::cout << largest << '\n';
}