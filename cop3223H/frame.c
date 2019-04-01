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

	//defines inner and outer frames
	int outarea = blen * bwidth;
	int inarea = slen * swidth;

	//The difference is the frame area
	int framearea = outarea - inarea;

	//Present
	printf("The area of the frame is %d.\n", framearea);

	return 0;
}
