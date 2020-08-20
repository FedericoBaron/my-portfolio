//Federico Baron
//8/24/18
//Converts height in inches to feet and inches.

#include <stdio.h>

int main(){
	
	//Gets height in inches from user
	int heightInches;
	printf("How many inches tall are you?\n");
	scanf("%d", &heightInches);

	//Calculate height in feet and inches
	double feet = heightInches/12.0;
	int inches = heightInches%12;
	printf("you are %lf feet and %d inches tall.\n", feet, inches);

	return 0;
}

//NOTES

//int/int=int
//int/real=real
//real/real=real

//%d for int
//%lf for double
//%f for float