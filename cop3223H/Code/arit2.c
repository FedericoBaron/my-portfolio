//Federico Baron
//9/10/18
//arithmetic game #2 - player can choose operation for each problem

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void){

	srand(time(0));

	//my accumulators
	int total = 0, correct = 0;

	//keep on going until user doesnt want problems
	while(choice != "QUIT"){

		printf("What would you like to do?\n");
		printf("1. Addition.\n");
		printf("2. Subtraction.\n");
		printf("3. Multiplication.\n");
		printf("4. Quit.\n");
		scanf("%d", &choice);

		if(choice == ADD){

			int num1 = rand()%10 + 1;
			int num2 = rand()%10 +1;
			printf("what is %d + %d\n", num1, num2);
			scanf("%d", &ans);

			//they got it!
			if(ans == num1 + num2){
				printf("You got it!\n");
				correct++;
			}
			else
				printf("Sorry the correct answer was %d", num1 + num2);

			total++;
		}

		else if(choice == SUB){

			int num1 = rand()%10 + 1;
			int num2 = rand()%10 +1;
			printf("what is %d - %d\n", num1, num2);
			scanf("%d", &ans);

			//they got it!
			if(ans == num1 - num2){
				printf("You got it!\n");
				correct++;
			}
			else
				printf("Sorry the correct answer was %d", num1 + num2);

			total++;

		else if(choice == MULT){

			int num1 = rand()%10 + 1;
			int num2 = rand()%10 +1;
			printf("what is %d * %d\n", num1, num2);
			scanf("%d", &ans);

			//they got it!
			if(ans == num1 * num2){
				printf("You got it!\n");
				correct++;
			}
			else
				printf("Sorry the correct answer was %d", num1 + num2);

			total++;
	}

	printf("You got %.2lf percent of your questions correct.\n", 100.0 * correct / total);

}