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

// int main(void) {

// 	FILE *fptr;
// 	if ((fptr = fopen("results.txt", "r")) == NULL) {
// 			printf("Error! file not found");
// 			// Program exits if file pointer returns NULL.
// 			exit(1);
// 	}

// 	fseek(fptr, 0, SEEK_END);
// 	int size = ftell(fptr);
// 	fseek(fptr,0,SEEK_SET);
// 	char c[size];

// 	// reads text until newline is encountered
// 	fscanf(fptr, "%[^\n]", c);
// 	printf("Data from the file:\n%s\n", c);
// 	c[size] = '\n';
// 	for(int k = 0; k < size; k++){
// 		printf("%d %c %d\n",k,c[k],c[k]);
// 		if(c[k]=='\n')
// 			printf("NEWLINE\n");
// 	}

// 	return 0;
// }

	//checksum needs to be 39069 for test case

int main(void) {

	FILE *fptr;
	if ((fptr = fopen("dat.txt", "r")) == NULL) {
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
	printf("Data from the file:\n%s\n", c);
	c[size] = '\n';
	fclose(fptr);
	// for(int k = 0; k < size+1; k++){
	// 	printf("%d \%c\n",k,c[k]);
	// 	if(c[k]=='\n')
	// 		printf("NEWLINE\n");
	// }
	int checksum = 0;
	int SizeOfArray = size;
	int even_length = SizeOfArray - SizeOfArray%2;

	int x;
	for( x = 0; x < even_length; x += 2)
	{
		unsigned int sum = (c[x] + (c[x+1]<<8))+checksum;
		printf("\nRaw Sum:\n");
		bin(sum);
		if (sum > (2<<15)){
			printf("Before Complement:\n");
			bin(sum);
			sum=sum-0xFFFF;
			printf("After Complement:\n");
			bin(sum);
		}
		checksum = sum;
	}
	printf("Sum of the bytes for MyArray is: %d\n", checksum);

	printf("The checksum integer: \n");
	// checksum &= 0xff;
	checksum= ~checksum & 0xFFFF; 
	// checksum=checksum>>8;
	// checksum++;
	printf("%u\n",checksum);

	FILE *f = fopen("results.txt", "w+");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}else{
		printf("Writing to file...\n");
	}
	/* write to file */
	int first = checksum & 0xFF;
	int second = checksum >> 8;
	eight_bit(first);
	eight_bit(second);
	// printf("Writing: %c %c\n",first,second);
	fprintf(f, "%s\n%c%c\n", c, first, second);
	fclose(f);

	fprintf("%d\n",strlen(c)+2);
	
	return 0;
}