// Method-1// 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int target = 200;
    const int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};

    vector<long long> ways(target + 1, 0);
    ways[0] = 1;

    for (int coin : coins) {
        for (int a = coin; a <= target; ++a) {
            ways[a] += ways[a - coin];
        }
    }

    cout << ways[target] << endl;  // 73682
    return 0;
}
//Method-2//
#include <iostream>
#include <vector>
using namespace std;

const int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
long long memo[8][201];

// Ways to make `rem` using coins from index `i` onward
long long count(int i, int rem) {
    if (rem == 0) return 1;
    if (i == 8 || rem < 0) return 0;
    long long &res = memo[i][rem];
    if (res != -1) return res;
    // Either use coin i again, or move on to the next coin
    return res = count(i, rem - coins[i]) + count(i + 1, rem);
}

int main() {
    for (auto &row : memo) for (auto &x : row) x = -1;
    cout << count(0, 200) << endl;  // 73682
}