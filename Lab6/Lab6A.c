#include <stdio.h>

int main(void){

	char mainstring[100];	
	char substring[100];

	scanf("%s",substring);
	scanf("%s",mainstring);
	
	int mainlen,sublen = 0;
	
	while (mainstring[mainlen] != '\0')
		mainlen++;

	while (substring[sublen] != '\0')
		sublen++;

	//printf("%s %d\n",mainstring,mainlen); 	
	//printf("%s %d\n",substring,sublen);

	int i, j, foo;
	

	for(i = 0; i < mainlen-sublen+1; i++){
		foo = 0;
		for (j = 0; j < sublen; j++){
			if (mainstring[i+j] == substring[j]){
				foo++;
			}
			//printf("%c",mainstring[i+j]);
		}
		if (foo == sublen){
			printf("YES\n");
			return 0;
		}
	}
	
	printf("NO\n");

	return 0;

}
