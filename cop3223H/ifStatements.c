//Federico Baron
//9/5/18
//if statement example with multiple clauses
#include <stdio.h>
int main(){
	int grade=0;
	printf("What is your percentage grade?\n");
	scanf("%d",&grade);

	if(grade >= 90){
		printf("You got an A\n");
	}
	else if(grade >= 80){
		printf("You got a B\n");
	}
	else if(grade >= 70){
		printf("You got a C\n");
	}
	else if(grade >= 60){
		printf("You got a D\n");
	}
	else{
		printf("You got an F\n");
	}
	return 0;
}