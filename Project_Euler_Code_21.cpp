#include <iostream>
#include <stdio.h>
#define MAXIMUM 10000
int main(void){
    int i , j;
    int tempSum1 , tempSum2 ;
    int answer = 0;
    int numArray[5] = {0} ;
    int arrCnt ; 
    int skip ;
    for (i = 2 ; i<MAXIMUM ; i++ ){
        tempSum1 = tempSum2 = 0;
        skip = 0;
        // Get all Divisor under the current number , and add them all up ;
        for(j = 1 ; j < i ; j++){
            if (i%j ==0){
                tempSum1+= j;
            }
        //Get all the divisor under that sum , and add them all of these up ; 
        if(tempSum1!=i){
            for(j = 1 ;j <tempSum1; j++){
                if(tempSum1%j ==0){
                    tempSum2+=j;
                }
            //if Second sum of divisors = original number (i), then we have an amicable numbers of divisors 
            //add both the numbers and tempSum1 to answer 
            if(tempSum2 == i ){
                for(j=0;j<arrCnt;j++){
                    if(i==numArray[j]|| tempSum1==numArray[j]){
                        skip = 1 ;
                    }
                if(skip==0){
                    answer +=(i+tempSum1);
                    numArray[arrCnt] = tempSum1;
                    arrCnt++;
                    printf("i: %d, sum1: %d, Answer :%d\n",i , tempSum1, answer );
                }
                }
            }
            }
        }
        }
    }
    //print out final answer 
    printf("\nFinal Answer :%d\n ", answer);

}