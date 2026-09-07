#include<iostream>
using namespace std; 
bool calculate(int number , int n ){
    if(n==0){
        return true;
    }
    return (number%n!=0)? false:calculate(number,n-1);

}
int main(){
    int number = 20;
    int result = number ;
    while(!calculate(result,number)){
        result+=10;
    }
    cout<<result<<endl;
}