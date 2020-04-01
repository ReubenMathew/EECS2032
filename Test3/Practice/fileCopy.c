#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>



int main(void) {

	FILE *fptr;
	if ((fptr = fopen("sample.txt", "r")) == NULL) {
			printf("Error! file not found\n");
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


    printf("%s",c);
	fclose(fptr);


    FILE *f = fopen("modified.txt", "w+");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
    int i;
    while(i<strlen(c)){
        if(c[i] != '\n')
            fprintf(f, "%c", c[i]);
        i++;
    }
    fclose(f);


    return 0;

}