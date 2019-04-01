#include <ctype.h>
#include <string.h>
void put_in_spaces(char word[]);
int main(void){
	put_in_spaces("hello");
}
void put_in_spaces(char word[]){
	for(int i = 0; i < sizeof(word[100])/sizeof(char); i++){
		getchar(word[i]);
		if(getchar(isalpha(word[i])))
			putchar(toupper(word[i]));
		else if(getchar(!isalpha(word[i])))
			putchar(word[i], '*');
		}
}