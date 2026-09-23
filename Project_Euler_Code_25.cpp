#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> prev = {1};
    vector<int> curr = {1};
    int index = 2;

    while (curr.size() < 1000) {
        vector<int> next;
        int carry = 0;
        int max_size = max(prev.size(), curr.size());

        for (int i = 0; i < max_size || carry; ++i) {
            int sum = carry;
            if (i < prev.size()) sum += prev[i];
            if (i < curr.size()) sum += curr[i];
            next.push_back(sum % 10);
            carry = sum / 10;
        }

        prev = curr;
        curr = next;
        index++;
    }

    cout << "Index: " << index << endl;
    return 0;
}
