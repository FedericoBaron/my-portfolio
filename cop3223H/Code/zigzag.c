//Federico Baron
//zig zag checker

#include <stdio.h>
#include <stdlib.h>

int isZigZag(int array[], int length);

int main(void){
	int arr[] = {2,2,2,2,2,2,2,2,2};
	printf("%d\n", isZigZag(arr, 9));
	return 0;
}


int isZigZag(int array[], int length){
	int checkEven = 1;
	int checkOdd = 1;

	for(int i = 0; i<length -2; i = i + 2){
		if(!(array[i]>array[i+1]) && !(array[i+1]<array[i+2]))
			checkOdd = 0;
		if(!(array[i]<array[i+1]) && !(array[i+1]>array[i+2]))
			checkEven = 0;
	}

	if(checkEven == 0 && checkOdd == 0){
		return 0;
	}
	return 1;
}