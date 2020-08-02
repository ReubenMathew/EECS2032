#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

// I AM ASSUMING THE RANGE IS INCLUSIVE
// so if the input is '3 13'
// then the output will be 
// 3,5,7,11,13

int isPrime(int num){
    int i;
    int prime = TRUE;
    if (num == 1){
        return FALSE;
    }

    for(i = 2; i < num; i++){
        if((num%i)==0)
            prime = FALSE;
    }   
    return prime;
}

int main(void) {

    int a,b;
    scanf("%d %d",&a,&b);
    int i;
    char out[1000];

    for (i = a; i <= b; i++){
        if(isPrime(i)){
            char temp[100];
            sprintf(temp, "%d,", i);
            strcat(out,temp);
        }
            // printf("%d,",i);
    }
    out[strlen(out)-1] = '\0';
    printf("%s\n",out);

    return 0;
}
