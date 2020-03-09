#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/*
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

}

void bin(int n){
	int c, k;
	for (c = 15; c >= 0; c--)
  {
    k = n >> c;

    if (k & 1)
      printf("1");
    else
      printf("0");
  }

  printf("\n");
}
*/


int main(void) {

	FILE *fptr;
	if ((fptr = fopen("dat.txt", "r")) == NULL) {
			printf("Error! file not found");
			// Program exits if file pointer returns NULL.
			exit(1);
	}

	int size;
	char *c;
	

	// reads text until newline is encountered
	// fscanf(fptr, "%[^\n]", c);
	// printf("Data from the file (Size: %d):\n%s\n", size, c);
	
	fseek( fptr , 0L , SEEK_END);
	size = ftell( fptr );
	rewind( fptr );

	/* allocate memory for entire content */
	c = calloc( 1, size+1 );
	if( !c ) fclose(fptr),fputs("memory alloc fails",stderr),exit(1);

	/* copy the file into the buffer */
	if( 1!=fread( c , size, 1 , fptr) )
	  fclose(fptr),free(c),fputs("entire read fails",stderr),exit(1);

	fclose(fptr);
	//printf("%c\n",c);
	int checksum = 0;
	int SizeOfArray = size;
	int even_length = SizeOfArray - SizeOfArray%2;

	int x;
	for( x = 0; x < even_length; x += 2)
	{
		unsigned int sum = ((c[x]<<8) + (c[x+1]))
		+checksum;

		/*
		printf("\nRaw Sum:\n");
		bin(sum);
		printf("\nChunk: %c %c %u %u %u\n",c[x],c[x+1],c[x] & 0xFF,c[x+1] & 0xFF,sum & 0xFFFF);
		printf("Sum: %u\n", (c[x]<<8) + (c[x+1]) & 0xFFFF);
		eight_bit(c[x]);
		eight_bit(c[x+1]);
		printf("\n");
		*/
		
		if (sum > 0xFFFF){
			// printf("Before Complement:\n");
			// bin(sum);
			sum=sum-65536;
			sum++;
			// printf("After Complement:\n");
			// bin(sum);
		}
		//printf("Sum: ");
		//bin(sum);
		//printf("\n");
		checksum = sum;
	}
	//printf("Sum of the bytes for MyArray is: %d\n", checksum);

	//printf("The checksum integer: \n");
	checksum= (~checksum) & 0xFFFF; 
	//printf("%u\n",checksum);


	FILE *f = fopen("results.txt", "w+");
	if (f == NULL)
	{
		//printf("Error opening file!\n");
		exit(1);
	}else{
		//printf("Writing to file...\n");
	}
	/* write to file */
	int first = checksum >> 8;
	int second = checksum & 0xFF;
	/*eight_bit(first);
	printf("\n");
	eight_bit(second);
	printf("\n");
	printf("Writing: %d %d\n",first,second);*/
	fprintf(f, "%s%c%c", c, first,second);
	fclose(f);

	return 0;
}
