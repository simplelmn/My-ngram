#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int contain(char *arr , char c)
    {
        for(int i=0; i < strlen(arr); i++){
            if(arr[i] == c){
                return 1;
            }
        }
        return 0;

    }

int main(int ac, char** av){
    int sonlar[128] = {0};
    char joy[128];
    int ind = 0;

    for(int i = 1; i < ac; i++){
        for(int j = 0 ; j < strlen(av[i]); j++){
            sonlar[av[i][j]]++;
            
            if(contain( joy ,av[i][j])==0){
                joy[ind]= av[i][j];
                ind++;
            }
        }
    }

    for(int i = 0; i < strlen(joy)-1; i++){
        for(int j=i+1; j < strlen(joy); j++){
            if(joy[i] >   joy[j]){
            char x = joy[i];
            joy[i] = joy[j];
            joy[j] = x;
            }
        }
    }
    
    for(int i = 0 ; i < strlen(joy); i++){
    if(joy[i] != '"')
    printf("%c:%d\n", joy[i] , sonlar[joy[i]]);
    }
}
