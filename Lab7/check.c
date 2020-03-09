#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>



int main(void) {

	FILE *fptr;
	if ((fptr = fopen("results.txt", "r")) == NULL) {
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

	int checksum = 0;
	int SizeOfArray = size;
	int even_length = SizeOfArray - SizeOfArray%2;

	int x,first,second;
	for( x = 0; x < even_length; x += 2)
	{
		first = (c[x] << 8) & 0xFFFF;
		second = c[x+1] & 0xFF;
		
		unsigned int sum = (first+second)
		+checksum;
		/*
		printf("\nRaw Sum:\n");
		bin(sum);
		eight_bit(first>>8);
		eight_bit(second);
		printf("\n");
		*/
		
		if (sum > 0xFFFF){
			// printf("Before Complement:\n");
			// bin(sum);
			sum=sum-0xF0000;
			sum++;
			sum &= 0xFFFF;
			// printf("After Complement:\n");
			// bin(sum);
		}
		
		/*
		printf("\nChunk: %c %c %u %u %u\n",first>>8,second,(first>>8) & 0xFF,second,sum & 0xFFFFF);
		bin((first));
		bin((first+second) & 0xFFFF);
		printf("Sum: %u\n", (first) + (second) & 0xFFFF);
		bin(sum);
		printf("\n");
		*/
		checksum = sum;
	}
	//printf("Sum of the bytes for MyArray is: %u\n", checksum&0xFFFF);

	//printf("The check integer: \n");
	//printf("%u\n",checksum&0xFFFF);
	if (checksum==0xFFFF){
		printf("Valid\n");
	}else{
		printf("Invalid\n");
	}

	return 0;
}
