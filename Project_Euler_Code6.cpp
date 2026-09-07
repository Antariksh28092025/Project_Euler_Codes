#include<iostream>
using namespace std;
int main(){
    //int i = 1 , j =1 ;
    int n = 100; 
    int m = (n*(n+1)*(2*n+1))/6;
    int l = ((n*(n+1)/2)*(n*(n+1)/2));
    cout<<"The Sum of the Square of numbers from 1 to 100 is: "<<m<<endl;
    cout<<"The Square of the sum of number from 1 to 100 is : "<<l<<endl;
    cout<<"The Difference between the Square of numbers and Square of the sum of number from 1 to 100: "<< l-m <<endl;
}