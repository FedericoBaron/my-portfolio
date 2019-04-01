//Federico Baron
//9/12/18
//forLoop

#include<stdio.h>

int main(void){

	int i;

	for(i = 0; i < 10; i++){
		printf("%d i will not skip school and go to the beach!\n", i + 1);
	}

	int sum = 0;
	int low, high;
	printf("What are the bounds you want to sum in between?\n");
	scanf("%d%d", &low, &high);

	for(i = low; i <= high; i++){
		sum = sum + i;
		printf("After adding %d, our current sum is %d.\n", i, sum);
	} 

	printf("The final sum is %d\n", sum);

	int j;

	for(i = 1, j = 0; j < 20; i *= 2, j++){
		printf("%d\t%d\n", j + 1, i);
	}

	return 0;
}