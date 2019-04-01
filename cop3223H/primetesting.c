//Federico Baron
//prime testing to illustrate the use of the break statement
//9/17/18

#include <stdio.h>

int main(void){

	//get the user input
	int n;
	printf("please enter a positive integer greater than 1.\n");
	scanf("%d",n)

	//initially we assume n is prime
	int i, isPrime = 1;
	//try each divisor
	for(i = 2; i < n; i++){

		//check if i divides into n evenly
		if(n % i == 0){
			isPrime = 0;

			//No point in continuing, stop immediately
			break;
		}
	}

	//print out if n is prime or not
	if(isPrime)
		printf("It is prime");
	else
		printf("It is not");

	return 0;

}