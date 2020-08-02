#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int root(int x) 
{   
    int i, foo = 1; 

    if (x <= 1) 
        return x; 

    while (foo <= x) { 
      i++; 
      foo = i * i; 
    } 
    return i - 1; 
} 

int main() 
{ 
    int n,pInt;

    char out[1000];

    scanf("%d",&n);

    while (n%2 == 0) { 
        // printf("%d ", 2);
        pInt = 2;
        char temp[10];
        sprintf(temp, "%d,", pInt);
        strcat(out,temp);
        n = n/2; 
    } 
  
    int i;
    for (i = 3; i <= root(n); i = i+2) { 
        while (n%i == 0) {
            char temp[100];
            sprintf(temp, "%d,", i);
            strcat(out,temp); 
            n = n/i; 
        }
    }

    if (n > 2) {
        char temp[100];
        sprintf(temp, "%d,", n);
        strcat(out,temp);   
    }
    out[strlen(out)-1] = '\0';
    printf("%s\n",out);
    return 0; 
} 