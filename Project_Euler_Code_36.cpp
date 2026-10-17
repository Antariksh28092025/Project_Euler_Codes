#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& s) {
    return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

std::string toBinary(int n) {
    std::string bits;

    while (n > 0) {
        bits.push_back((n % 2) + '0');
        n /= 2;
    }

    std::reverse(bits.begin(), bits.end());
    return bits;
}

int main() {
    int sum = 0;

    for (int n = 1; n < 1'000'000; ++n) {
        const std::string decimal = std::to_string(n);
        const std::string binary = toBinary(n);

        if (isPalindrome(decimal) && isPalindrome(binary)) {
            sum += n;
        }
    }

    std::cout << sum << '\n';
}