#include <iostream>
using namespace std;
int main(){
    int limit = 1000;
    int sum = 0;
    for (int i = 1; i < limit ; i++){
        if ((i%3==0)||(i%5==0)){
            sum += i;
        }
    }
    cout<< "The Sum of all the integers satisfying the condition given: " << sum <<endl;
    return 0;
}
