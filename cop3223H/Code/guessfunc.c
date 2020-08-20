//Federico Baron
//9/28/18
//Guess game with functions

#include<stdio.h>
#include<stdlib.h>

int guessgame(int low, int high);

int main(void){

	//initializes variables for guessing game
	int n, low, high, numguess;

	//gets number of times they want to play
	printf("How many times do you want to play?");
	scanf("%d", &n);

	//calls guessgame function which plays guessgame
	for(int i = 0; i < n; i++){
		//gets low boundary
		printf("What is the low boundary?\n");
		scanf("%d", &low);

		//gets high boundary 
		printf("What is the high boundary?\n");
		scanf("%d", &high);

		//increases number of guesses and runs guessgame function
		numguess += guessgame(low, high);
	}

	//prints avg number of guesses for all games
	printf("The avg amount of guesses was %.2lf\n", numguess/(double)n);

	return 0;

}


//Pre-condition:low and high are non-negative integers
//Post-condition: 
int guessgame(int low, int high){

	//initializes guess variable
	int guess;

	//declares variable to count number of guesses in this game
	int numguess = 0;

	//generate random number between low and high
	int random = rand() % (high-low+1) + low;

	//goes through loop while true, break out of loop when user guess = secret number
	while(1){

		//increases number of guesses in this game
		numguess++;

		//gets guess from user
		printf("Guess a number between %d and %d\n", low, high);
		scanf("%d", &guess);

		//checks if guess is equal to random
		if(guess == random){
			printf("You guessed correctly! it only took you %d tries\n", numguess);
			return numguess;
		}
		else if(guess > random){
			printf("You guessed too high! try again!\n");
		}
		else
			printf("you guessed too low! try again!\n");
	}
	return numguess;
}
