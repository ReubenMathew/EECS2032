#include <stdio.h>
#include <string.h>

int main(void) {
  char str[128];
  int i;
  scanf("%s %d", str, &i);

  int j,k,temp;
  int len = strlen(str)-i+1;
  
  for(j=0; j<len;j++){
    temp = 1;
    for(k=0; k < i-1; k++)
      if(str[k+j+1] != str[k+j]+1)
        temp = 0;
    if(temp==1){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}
