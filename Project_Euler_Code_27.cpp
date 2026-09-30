#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// Check whether n is prime
bool isPrime(int n) {
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int bestA = 0;
    int bestB = 0;
    int maxPrimes = 0;

    // |a| < 1000  => -999 <= a <= 999
    // |b| <= 1000 => -1000 <= b <= 1000
    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {

            // At n = 0, the expression is simply b.
            // Therefore b must be prime.
            if (!isPrime(b))
                continue;

            int count = 0;

            // Count consecutive primes starting from n = 0
            for (int n = 0; ; n++) {
                int value = n * n + a * n + b;

                if (!isPrime(value))
                    break;

                count++;
            }

            if (count > maxPrimes) {
                maxPrimes = count;
                bestA = a;
                bestB = b;
            }
        }
    }

    cout << "Best a = " << bestA << '\n';
    cout << "Best b = " << bestB << '\n';
    cout << "Number of consecutive primes = " << maxPrimes << '\n';
    cout << "Product a * b = " << bestA * bestB << '\n';

    return 0;
}