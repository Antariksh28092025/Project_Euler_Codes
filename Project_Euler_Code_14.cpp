// #include<stdio.h>
// int main(){
//     long startNumber , answer;
//     long long  number ;
//     int terms ;
//     int saveTerms;
//     for (startNumber=2; startNumber < 1000000 ; startNumber++){
//         terms = 1 ; 
//         number = startNumber;
//         while(number){
//             while(number%2 == 0 ){
//                 number/=2;
//                 terms;
//             }
//             if(number>1){
//                 number = (number*3)+1;
//                 terms++;
//             }

//         }
//         if(terms>saveTerms){
//             saveTerms = terms;
//             answer = startNumber;
//         }
//     }
//     printf("\nlongest chain: %d,starting number :%ld", saveTerms, answer);
//     return 0;
// }
#include <stdio.h>

int main() {
    long startNumber, answer = 0;
    long long number;
    int terms;
    int saveTerms = 0;

    for (startNumber = 2; startNumber < 1000000; startNumber++) {
        terms = 1;
        number = startNumber;

        while (number != 1) {
            if (number % 2 == 0) {
                number /= 2;
            } else {
                number = number * 3 + 1;
            }

            terms++;
        }

        if (terms > saveTerms) {
            saveTerms = terms;
            answer = startNumber;
        }
    }

    printf("Longest chain: %d, starting number: %ld\n", saveTerms, answer);

    return 0;
}