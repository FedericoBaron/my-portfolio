//Federico Baron
//9/10/18
//adds up the digits in a number

#include <stdio.h>

int main(void){

	int n;
	printf("Please enter a positive integer.\n");
	scanf("%d", &n);

	int sumdigits = 0;
	int rev = 0;
	//go thru each digit one by one
	while(n > 0){

		//add in the last digits
		sumdigits += n%10;

		//peels off the last digit
		n /= 10;

		//update rev (reverse)
		rev = 10 * rev + n % 10;
	}

	printf("The sum of the digits of %d is %d\n", n, sumdigits);
	printf("The reverse number is %d\n", rev);
}

