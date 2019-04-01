//Federico Baron
//10/24/2018
//Reads in set of words, scrambles them and outputs them to stdout

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LEN 20
#define MAX_NUM_WORDS 200

int main(void){

	//read in the number of words
	int i, n;
	scanf("%d", &n);

	//define array of strings and read in words
	char words[][];
	for(i = 0; i < n; i++){
		scanf("%s", words[i]);
	}

	for(i = 0; i < 10 * n; i++){

		int idx1 = rand()%n;
		int idx2 = rand()%n;
		swap(words, idx1, idx2);
		
	}

	
}

void swap(char words[][MAX_LEN + 1], int i, int j){
	
	char tmp[MAX_LEN + 1];
	strcpy(tmp, words[i]);
	strcpy(words[i], words[j]);
	strcpy(words[j], tmp);

}