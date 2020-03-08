#include <stdio.h>
#include <string.h>

void substring(char [], char[], int, int);

int main(void) {
  char str1[1000], str2[1000];
	scanf("%s\n%s",str1,str2);

	//find string lengths
	int s1_len = strlen(str1), s2_len = strlen(str2);

	//find minimum length between the two strings
	int trav_len = s1_len <= s2_len ? s1_len : s2_len;
	// output variable
	int overlap = 0;

	int i;
	char s1[trav_len], s2[trav_len];


	for (i = 0; i <= trav_len; i++) {
		substring(str1,s1,s1_len-i,s1_len);
		substring(str2,s2,0,i);
		if (strcmp(s1, s2)==0)
			overlap = overlap >= i ? overlap : i;
	}

	//reverse the strings and recompare
	for (i = 0; i <= trav_len; i++) {
		substring(str2,s2,s2_len-i,s2_len);
		substring(str1,s1,0,i);
		if (strcmp(s1, s2)==0)
			overlap = overlap >= i ? overlap : i;
	}
	printf("%d\n",overlap);
	return 0;
}
//substring helper
void substring(char str[], char dest[], int start, int end){
	int i = 0;
	while( i < end){
		dest[i] = str[i+start]; i++;
	}
	dest[i] = '\0';
}

