#include <iostream>
#include <vector>

// Find length of the recurring cycle in the decimal fraction part of 1/x
unsigned int cyclelength(unsigned int x) {
    if (x == 0) {
        return 0;
    }

    const unsigned int NotSeenYet = 0;
    std::vector<unsigned int> lastPos(x, NotSeenYet);
    
    unsigned int position = 1; 
    unsigned int dividend = 1;

    while (true) {
        unsigned int remainder = dividend % x; 
        
        if (remainder == 0) {
            return 0;
        }

        // If we have seen this remainder before, we found a cycle
        if (lastPos[remainder] != NotSeenYet) {
            return position - lastPos[remainder];
        }

        // Record the position where this remainder was seen
        lastPos[remainder] = position;
        position++;
        dividend = remainder * 10;
    }
}

int main() {
    // Optimize standard I/O operations for HackerRank performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // HackerRank's upper limit is typically 10000
    const unsigned int MaxDenominator = 10000;
    
    // cache[N] will store the denominator < N that produces the longest cycle
    std::vector<unsigned int> cache;
    cache.push_back(0); // For N = 0
    cache.push_back(0); // For N = 1 (no denominator < 1)

    unsigned int longestDenominator = 0;
    unsigned int longestCycle = 0;

    // Precompute up to MaxDenominator
    for (unsigned int denominator = 1; denominator <= MaxDenominator; denominator++) {
        unsigned int length = cyclelength(denominator);
        if (length > longestCycle) {
            longestCycle = length;
            longestDenominator = denominator;
        }
        // Cache the best denominator found *so far*
        cache.push_back(longestDenominator);
    }

    unsigned int tests;
    if (std::cin >> tests) {
        while (tests--) {
            unsigned int x;
            std::cin >> x;
            // HackerRank requires strictly less than x, so we look up x - 1
            std::cout << cache[x - 1] << "\n";
        }
    }

    return 0;
}
