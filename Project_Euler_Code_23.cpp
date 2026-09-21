#include<iostream>
#include<stdio.h>
#include<stdint.h>
#define LIMIT 28123
int main(void){
    //variables and there size
    uint32_t sum_of_divisors;
    uint16_t abundant_numbers[7000];
    uint16_t ab_idx = 0;
    //Arrays specifications
    uint8_t  sum_of_two_ab_nums[LIMIT+1]={0};
    uint32_t sum_of_array_elems = 0;
    uint32_t answer = 0;
    // Finding Factors
    for(uint16_t i = 12 ; i<= LIMIT ; i++){
        sum_of_divisors = 1;
        //Get the sum of divisors for number
        for(uint16_t j = 2 ; j*j<=i; j++){
            if(i%j ==0){
                sum_of_divisors += j;
                if(j != i/j){
                    sum_of_divisors += i/j;
                }
            }
            //Found Abundant Number
            if(sum_of_divisors>i){
                abundant_numbers[ab_idx]=i;
                ab_idx++;
                break;
            }
        }
    }
//Set any number that is the sum of 2 abundant numbers 
for(uint16_t i = 0; i<ab_idx; i++){
    for (uint16_t j = 0; j<ab_idx; j++){
        uint32_t sum = abundant_numbers[i] + abundant_numbers[j];
        if(sum <= LIMIT){
            sum_of_two_ab_nums[sum]=1;
        }
    }
}
//Sum up all numbers that are not the sum of 2 abundant numbers
for(uint32_t k = 0; k< LIMIT+1 ; k++){
    if(sum_of_two_ab_nums[k] == 0 ){
        answer +=k;
    }
}
printf("%u\n", answer);
}