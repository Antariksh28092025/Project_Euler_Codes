    #include <iostream>
#include <set>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int main() {
    set<cpp_int> terms;

    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {

            cpp_int result = 1;

            // Calculate a^b
            for (int i = 0; i < b; i++) {
                result *= a;
            }

            // set automatically removes duplicates
            terms.insert(result);
        }
    }

    cout << "Number of distinct terms = " << terms.size() << endl;

    return 0;
}
