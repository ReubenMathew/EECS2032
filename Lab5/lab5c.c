#include <stdio.h>
#include <string.h>

int main(void) {
  char str[128];
  scanf("%s", str);

  int j,k,temp;
  int len = strlen(str);
  int max = 1;
  for(j=0; j<len;j++){
    temp = 1;
    for(k=j; k < len; k++){
      // printf("%c", str[k]);
      if(str[k+1] == str[k]+1)
        temp++;
      else
        break;
    }
    // printf("\n%d\n",temp);
    max = (max > temp)? max : temp;
  }
  printf("%d\n",max);
}
