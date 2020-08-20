//Federico Baron
//9/7/18
//If statement pitfalls


/*

if pitfalls in C:

1) errant ;
2) missing parenthesis 
3) = instead of ==
4) a < b < c instead of a < b && b < c
5) matching else problem

Ex for 1):
if(age>=16);
	printf(“You can drive”);

*/

int main(void){


	//if errants
	int age;
	printf("Enter your age\n");
	scanf("%d",&age);

	if(age >= 21);
		printf("Great, lets go to happy hour and have a beer");

	//missing {}
	if(age >= 21)
		printf("This time you can actually go to happy hour!");
		printf("Shots on me!");
	//compile error because else without matching if
	else
		printf("Sorry, lets wait a few years\n");

	//missing {}

	if(age >= 21)
		printf("You are an adult\n");
	else
		printf("You are a child\n");
		printf("Do you want a lollipop?\n");


	//single = sign turns age into 21 and triggers printf ex: age = 19 it turns into 21 and statement is true
	if(age = 21){
		printf("Woohoo! time to party!\n");
		printf("You are %d years old\n", &age);
	}

	//single = issue 
	if(age = 0)
		printf("I was just born!");
	printf("Now i am %d years old at the end of the day.\n", &age);

	//gets age again
	printf("To test this pls re-enter age\n");
	scanf("%d", &age);

	//matching else problem - else always matches innermost unmatched if | add brackets to fix
	if(age >= 21)
		if(age >= 60)
			printf("You are a senior citizen\n");
	else
		printf("The lollipop is waiting for you\n");

	return 0;
}




