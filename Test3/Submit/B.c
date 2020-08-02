#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

int main(void) {

    char c[1000];
    scanf("%s",c);
    int i;

    for (i = 0; i < strlen(c); i++){
        if (c[i]=='.')
            break;
    }
    printf("%d\n",i);
    return 0;
}
