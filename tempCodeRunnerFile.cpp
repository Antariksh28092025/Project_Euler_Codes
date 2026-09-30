#include <iostream>
using namespace std;

int main() {
    long long sum = 1; // Center of the spiral

    // Each layer increases the side length by 2:
    // 3x3, 5x5, 7x7, ..., 1001x1001
    for (int size = 3; size <= 1001; size += 2) {

        // The largest number in this layer
        long long topRight = 1LL * size * size;

        // Other three corners
        long long topLeft = topRight - (size - 1);
        long long bottomLeft = topRight - 2 * (size - 1);
        long long bottomRight = topRight - 3 * (size - 1);

        // Add the four corners
        sum += topRight + topLeft + bottomLeft + bottomRight;
    }

    cout << "Sum of diagonals = " << sum << endl;

    return 0;
}
