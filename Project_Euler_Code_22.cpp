#include<iostream>
#include<stdio.h>
#include<math.h>
#include <string.h>
#define NAMELEN 12
int main(void){
    //char c ; 
    int c;
    char tempName[NAMELEN];
    char namesArr[5200][NAMELEN];//hold names from files 
    int numNames =0;//number of names in files
    int i = 0 , j; // loop/array indeces
    int sorted ;
    int tempScore;
    int finalScore = 0;
    //FILE *fp = fopen("Project_Euler_Text22.txt","r");  
    FILE *fp = fopen("Project_Euler_Text22.txt", "r");//open file for reading
    // Read all comma sepearated names  from the files into list
    while((c = fgetc(fp))!=EOF){
        if(c==','){//if between names
            namesArr[numNames][i] = '\0';
            i=0;
            numNames++;
        }
        else if(c!='"'){//on current names
            namesArr[numNames][i] = c;
            i++;
        }
    }//End last names from EOP with null;
    namesArr[numNames][i] = '\0';
    //close file for cleanup;
    fclose(fp);
    // Sort names into alphabetical order 
    sorted = 1 ; 
    while(sorted == 1){
        sorted = 0;
        for(i = 0; i < numNames; i++){
            if (strcmp(namesArr[i], namesArr[i+1]) > 0){
                strcpy(tempName, namesArr[i]);
                strcpy(namesArr[i], namesArr[i+1]);
                strcpy(namesArr[i+1], tempName);
                sorted = 1;
            }
        }
    }
    // Add up scores for each names to get final answer , using ASCII int values
    //Subtract letter in name from "A"(65) and add 1 to it to get alphabetic score 
    for(i=0;i<=numNames; i++){
        tempScore = 0;
        for(j=0;j<NAMELEN ; j++){
            if(namesArr[i][j] != '\0'){
                tempScore +=((namesArr[i][j]- 'A')+1);
            }
            else
            break;//end early;reach enf of name
        }
        finalScore +=(tempScore*(i+1));//Multiply by position in list
        printf("Name: %s,Score: %d\n",namesArr[i],tempScore*(i+1));
    }
    //Print out Final Score
    printf("\nFinal Score:%d\n",finalScore);
}