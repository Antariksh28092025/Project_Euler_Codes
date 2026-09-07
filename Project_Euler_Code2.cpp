#include <iostream>
#include <math.h>

using namespace std;
int main(){
    int Limit = 4*pow(10,6);
    int sum = 2;
    int prev = 1 , curr = 2;
    while(curr <= Limit){
        curr = prev + curr;
        prev = curr - prev;
        if(curr%2==0){
            sum += curr;
        }

    }
    cout<<"The sum of Even number of Fibonaci series is : "<<sum << endl;
    return 0;
}