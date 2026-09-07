// method 1 // 
 
// #include<iostream>
// using namespace std;


// bool isPrime(int number){
//     if (number<2){
//         return false;
//     }
//     for(int i =2 ; i*i<=number;i++){
//         if(number%i == 0 ){
//             return false;
//         }
//     }
//     return true;

// }
// int main(){
//     int limit;
//     cout<<"Enter the upper limit :" ; 
//     cin>>limit;
//     int rank = 0 ;
//     for (int number =2 ; number<=limit ; number++){
//         if (isPrime(number) ){
//             rank++;
//             cout<<rank<<"The prime number : "<<number<<'\n';
//         }
//     }
//     return 0;
// }


// Method 2 (more efficient method)//
#include <iostream>
using namespace std;

bool isPrime(int number) {
    if (number < 2) return false;

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }

    return true;
}

int main() {
    int rank;
    cout << "Enter prime rank: ";
    cin >> rank;

    if (rank <= 0) {
        cout << "Rank must be at least 1.\n";
        return 0;
    }

    int count = 0;
    int number = 1;

    while (count < rank) {
        number++;

        if (isPrime(number)) {
            count++;
        }
    }

    cout << "The " << rank << "th prime number is: " << number << '\n';

    return 0;
}