//Federico Baron
//9/12/18
//Draws a diamond with stars!

#include<stdio.h>

int main(void){

	//get the size from the user	
	int n;
	printf("How many carats are in your diamond?\n");
	scanf("%d", &n);

	int nspace, nstar;
	for(nstar = 2 * n - 3, nspace = n - 1; nstar > 0; nstar -= 2, nspace++){
		//print nspace # of spaces.
		for(int i = 0; i < nspace; i++)
			printf(" ");

		//print nstar # of stars
		for(int i = 0; i < nstar; i++)
			printf("*");

		//advance to the next line
		printf("\n");
	}

	return 0;

}