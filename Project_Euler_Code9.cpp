#include <iostream>

int main() {
    constexpr int target_sum = 1000;
    int loop_count = 0;

    for (int a = 1; a < target_sum / 3; ++a) {
        for (int b = a + 1; b < (target_sum - a) / 2; ++b) {
            ++loop_count;

            int c = target_sum - a - b;

            if (a * a + b * b == c * c) {
                std::cout << "a = " << a
                          << ", b = " << b
                          << ", c = " << c << '\n';

                std::cout << "a * b * c = " << a * b * c << '\n';
                std::cout << "Loop count: " << loop_count << '\n';

                return 0;
            }
        }
    }

    std::cout << "No triplet found.\n";
    return 0;
}