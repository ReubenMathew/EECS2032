#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void eight_bit(int n){
	int c, k;
	for (c = 7; c >= 0; c--)
  {
    k = n >> c;

    if (k & 1)
      printf("1");
    else
      printf("0");
  }

  printf("\n");
}

void bin(int n){
	int c, k;
	for (c = 16; c >= 0; c--)
  {
    k = n >> c;

    if (k & 1)
      printf("1");
    else
      printf("0");
  }

  printf("\n");
}

int main(void) {

	FILE *fptr;
	if ((fptr = fopen("results.txt", "r")) == NULL) {
			printf("Error! file not found");
			// Program exits if file pointer returns NULL.
			exit(1);
	}

	fseek(fptr, 0, SEEK_END);
	int size = ftell(fptr);
	fseek(fptr,0,SEEK_SET);
	char c[size];

	// reads text until newline is encountered
	fscanf(fptr, "%[^\n]", c);
    fclose(fptr);
	printf("Data from the file:\n%s\nSize: %d\n", c, size);

	c[size] = '\n';
    c[size+1] = '\0';
    int k;
	for(k = 0; k < size; k++){
		printf("%d %c %u\n",k,c[k],c[k]);
	}

	return 0;
}

//checksum needs to be 39069 for test case

