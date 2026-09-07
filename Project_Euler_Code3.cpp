#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include <cstdint>
using namespace std;
int main(){
    std::int64_t Num = 600851475143LL;
    std::int64_t i = 2;
    while(i*i <=Num ) {
        if((Num%i)==0){
            Num /= i ;
            continue;
        
        }
        ++i;
    }
    cout<<"Largest prime divisor is = "<<Num << endl;
    return 0 ;  
}