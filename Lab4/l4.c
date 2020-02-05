#include <stdio.h>

int main(void) {
  int raw[3];
  char str[100];
  int i;
  int sumNeg = 0;
  int sumPos = 0;
  scanf("%[^\n]", str);
  sscanf( str, "%d %d %d", &raw[0], &raw[1], &raw[2]);
  for(i = 0; i < 3; i++){
    if (raw[i] < 0)
      sumNeg = sumNeg + (raw[i] * -1);
    else
      sumPos = sumPos + raw[i];
  }
  // printf("%d %d\n", sumNeg, sumPos);
  if (sumPos==0)
    printf("All Negative\n");
  else if (sumNeg==0)
    printf("All Positive\n");
  else
    if (sumPos > sumNeg)
      printf("Positive wins\n");
    else
      printf("Negative wins\n");

  // printf("%d, %d, %d\n", raw[0], raw[1], raw[2]);

}







