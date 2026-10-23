
#include <iostream>
#include <vector>
using namespace std;

// Greatest common divisor
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    while (a != 0)
    {
        unsigned long long c = a;
        a = b % a;
        b = c;
    }
    return b;
}

int main()
{
    const unsigned int MaxPerimeter = 5000000;

    // count[p] stores the number of Pythagorean triplets
    // having perimeter p.
    vector<unsigned int> count(MaxPerimeter + 1, 0);

    // Step 1: Generate primitive Pythagorean triplets
    // and count all their multiples.
    for (unsigned long long m = 2;
         2ULL * m * m < MaxPerimeter; m++)
    {
        for (unsigned long long n = 1; n < m; n++)
        {
            // m and n must have opposite parity.
            if (m % 2 == 1 && n % 2 == 1)
                continue;

            // Primitive triplets require gcd(m,n) = 1.
            if (gcd(m, n) != 1)
                continue;

            // Perimeter of the primitive triplet:
            // P = 2*m*(m+n)
            unsigned long long primitivePerimeter =
                2ULL * m * (m + n);

            // Count all multiples of this triplet.
            for (unsigned long long k = 1; ; k++)
            {
                unsigned long long perimeter =
                    k * primitivePerimeter;

                if (perimeter > MaxPerimeter)
                    break;

                count[perimeter]++;
            }
        }
    }

    // Step 2: Precompute the best perimeter for every limit.
    vector<unsigned int> bestPerimeter(MaxPerimeter + 1, 0);

    unsigned int bestCount = 0;
    unsigned int best = 0;

    for (unsigned int p = 1; p <= MaxPerimeter; p++)
    {
        // Update only when a strictly larger count is found.
        if (count[p] > bestCount)
        {
            bestCount = count[p];
            best = p;
        }

        bestPerimeter[p] = best;
    }

    // Step 3: Answer test cases.
    unsigned int tests;

    if (!(cin >> tests))
        return 0;

    while (tests--)
    {
        unsigned int maxPerimeter;
        cin >> maxPerimeter;

        // Protect against limits outside the precomputed range.
        if (maxPerimeter > MaxPerimeter)
            maxPerimeter = MaxPerimeter;

        cout << bestPerimeter[maxPerimeter] << '\n';
    }

    return 0;
}
