//Federico Baron
//9/10/18
//for loop practice game

#include <stdio.h>

#define GAMECOST 100

int main(void){

	//My accumulator variable.
	int myMoney = 0, week = 1;

	//keep on doing chores until we can buy the game
	while (myMoney < GAMECOST){

		//get amt of money made this week
		int thisweek;
		printf("How much money did you make in week %d?\n", week);
		scanf("%d", &thisweek);

		//update variables
		myMoney = myMoney + thisweek;
		week++;

	}

	//print out final status
	printf("Great it took you %d weeks to get your game.\n", week-1);
	printf("You have $%d money left over.\n", myMoney - GAMECOST);

	return 0;
}