#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// Helper to quickly convert 3 characters into an integer value
inline int getSubValue(const std::string& s, int start) {
    return (s[start] - '0') * 100 + (s[start + 1] - '0') * 10 + (s[start + 2] - '0');
}

int main() {
    // 0 to 9 pandigital digits sorted in ascending order
    std::string s = "0123456789";
    long long total_sum = 0;

    do {
        // Prune early using the most restrictive rules:
        // d6 (index 5) must be 5 or 0. Since 5 is highly restrictive, check it.
        if (s[5] != '5' && s[5] != '0') continue;
        
        // d4 (index 3) must be even
        if ((s[3] - '0') % 2 != 0) continue;

        // Check the remaining prime divisibility rules sequentially
        if (getSubValue(s, 1) % 2 != 0)  continue; // d2 d3 d4
        if (getSubValue(s, 2) % 3 != 0)  continue; // d3 d4 d5
        if (getSubValue(s, 3) % 5 != 0)  continue; // d4 d5 d6
        if (getSubValue(s, 4) % 7 != 0)  continue; // d5 d6 d7
        if (getSubValue(s, 5) % 11 != 0) continue; // d6 d7 d8
        if (getSubValue(s, 6) % 13 != 0) continue; // d7 d8 d9
        if (getSubValue(s, 7) % 17 != 0) continue; // d8 d9 d10

        // If all conditions are met, convert the full string to a 64-bit integer
        long long valid_pandigital = std::stoll(s);
        total_sum += valid_pandigital;

    } while (std::next_permutation(s.begin(), s.end()));

    std::cout << "The sum of all 0 to 9 pandigital numbers with this property is: " 
              << total_sum << std::endl;

    return 0;
}
