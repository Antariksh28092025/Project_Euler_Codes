#include <iostream>
#include <string>
#include <set>
using namespace std;

bool isPandigital(int a, int b, int product)
{
    string s = to_string(a) + to_string(b) + to_string(product);

    // Must contain exactly 9 digits
    if (s.length() != 9)
        return false;

    bool used[10] = {false};

    for (char c : s)
    {
        int digit = c - '0';

        // 0 is not allowed
        if (digit == 0)
            return false;

        // Digit already used
        if (used[digit])
            return false;

        used[digit] = true;
    }

    return true;
}

int main()
{
    set<int> products;

    // Case 1:
    // 1-digit × 4-digit = 4-digit
    for (int a = 1; a <= 9; a++)
    {
        for (int b = 1000; b <= 9999; b++)
        {
            int product = a * b;

            if (isPandigital(a, b, product))
            {
                cout << a << " × " << b
                     << " = " << product << endl;

                products.insert(product);
            }
        }
    }

    // Case 2:
    // 2-digit × 3-digit = 4-digit
    for (int a = 10; a <= 99; a++)
    {
        for (int b = 100; b <= 999; b++)
        {
            int product = a * b;

            if (isPandigital(a, b, product))
            {
                cout << a << " × " << b
                     << " = " << product << endl;

                products.insert(product);
            }
        }
    }

    int sum = 0;

    for (int product : products)
    {
        sum += product;
    }

    cout << "\nSum = " << sum << endl;

    return 0;
}