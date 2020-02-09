#include <stdio.h>
#include <string.h>

int main(void) {
  char str[128];
  int i;
  scanf("%s %d", str, &i);

  if (i==1){
    printf("YES\n");
    return 0;
  }

  int j,k,temp;
  int len = strlen(str)-i+1;

  for(j=0; j<len;j++){
    temp = 1;

    for(k=0; k < i-1; k++){
      // printf("%c %c\n", str[k+j+1], str[k+j]-'a'+'A'+1);
      // printf("%c %c\n", str[k+j+1], str[k+j]-'A'+'a'+1);
      if(str[k+j+1] != str[k+j]+1)
        if ((str[k+j+1] != str[k+j]-'a'+'A'+1) && (str[k+j+1] != str[k+j]-'A'+'a'+1))
          temp = 0;
    }
    if(temp==1){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}
