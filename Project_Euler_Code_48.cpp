
#include <iostream>

// Helper function to multiply two numbers modulo 'mod' without overflow
unsigned long long mulMod(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long res = 0;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res + a) % mod;
        }
        a = (a + a) % mod; // 2 * 10^10 fits easily in unsigned long long
        b /= 2;
    }
    return res;
}

// Function to compute (base^exp) % mod safely
unsigned long long powerMod(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base %= mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = mulMod(result, base, mod);
        }
        exp /= 2;
        base = mulMod(base, base, mod);
    }
    return result;
}

int main() {
    unsigned long long total_sum = 0;
    unsigned long long mod = 10000000000ULL; // 10^10

    for (unsigned long long i = 1; i <= 1000; ++i) {
        total_sum = (total_sum + powerMod(i, i, mod)) % mod;
    }

    std::cout << "The last ten digits are: " << total_sum << std::endl;

    return 0;
}
