#include <iostream>
#include <vector>

int main() {
    const int limit = 2000000;

    std::vector<bool> isPrime(limit, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i < limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    unsigned long long sum = 0;

    for (int i = 2; i < limit; i++) {
        if (isPrime[i]) {
            sum += i;
        }
    }

    std::cout << sum << '\n';

    return 0;
}
