#include <iostream>
using namespace std;

int countDivisors(long long n) {
    int divisors = 1;

    for (long long i = 2; i * i <= n; i++) {
        int power = 0;

        while (n % i == 0) {
            n /= i;
            power++;
        }
        

        if (power > 0) {
            divisors *= (power + 1);
        }
    }

    // If n itself is a prime number left over
    if (n > 1) {
        divisors *= 2;
    }

    return divisors;
}

int main() {

    long long n = 1;
    long long triangle = 1;

    while (countDivisors(triangle) <= 500) {

        n++;

        triangle = n * (n + 1) / 2;
    }

    cout << "Triangle number = " << triangle << endl;
    cout << "Position = " << n << endl;
    cout << "Number of divisors = "
         << countDivisors(triangle) << endl;

    return 0;
}