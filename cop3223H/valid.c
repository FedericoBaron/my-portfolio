#include <string.h>
#include <ctype.h>
#include <stdio.h>

int isValidPassword(char pswd[]);

int main(void){
	string s = ge);
	return 0;
}

int isValidPassword(char pswd[]){
	int upp = 0;
	int low = 0;
	int ch = 0;
	for(int i = 0; i < strlen(pswd); i++){
		if(islower(pswd[i]))
			low = 1;
		else if(isupper(pswd[i]))
			upp = 1;
		else
			ch = 1;
	}
	return(upp + low + ch == 3);
}