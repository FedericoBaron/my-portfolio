//Federico Baron
//9/16/18
//read test scores and avg them

#include <stdio.h>

int main(void){

	printf("please enter in some test scores. end your list with -1\n");

	int numscores = 0, sumscores = 0;

	//loop until we get our sentinel value
	while(1){
		int score;
		scanf("%d", &score);

		//we are done
		if(score == -1)
			break;

		//not done but we can't count this score
		if(score < 0 || score > 100)
			continue;

		//updates our accum
		numscores++;
		sumscores += score;
	}

	if(numscores == 0)
		printf("sorry no valid scores\n");
	else
		printf("you avg was %.2lf.\n", (double)sumscores/numscores);
	

}