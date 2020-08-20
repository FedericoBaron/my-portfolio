//Federico Baron
//9/10/18
//guessing game

#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){

	srand(time(0));

	//Generate a random number in between 1 and MAX, inclusive.
	int secretnum = 1 + rand() %MAX;
	int guess = -1, numguess=0;

	//keep on playing until the guess is correct
	while(guess != secretnum){

		//get the next guess
		printf("what is your guess\n");
		scanf("%d", &guess);
		numguess++;

		if(guess < secretnum){
			printf("Sorry, your guess is too low, guess higher\n");
		}
		else if(guess > secretnum){
			printf("Sorry, your guess is too low, guess higher\n");
		}
	}

	//end timer
	int end = time(0);

	//winner
	printf("You won! it took you %d guesses to guess %d", guess, numguess);
	printf("it took you %d seconds\n", end-start);

	//turn minutes to seconds is a common test question !!!!

	return 0;
}