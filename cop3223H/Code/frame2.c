//Federico Baron
//8/24/18
//Calculates the area of a picture frame.

#include <stdio.h>
int main(){

	//prompts user for frame dimensions and saves them as integers
	int blen, bwidth, slen, swidth;
	printf("Enter the dimensions of the outside of the frame.\n");
	scanf("%d%d", &blen, &bwidth);
	printf("Enter the dimensions of the inside of the frame\n");
	scanf("%d%d", &slen, &swidth);

	//Calculates and prints area of frame
	printf("The area of the frame is %d.\n", blen*bwidth-slen*swidth);
	return 0;
}

//Federicos-MacBook-Pro:desktop federico$ gcc frame2.c
//Federicos-MacBook-Pro:desktop federico$ ./a.out