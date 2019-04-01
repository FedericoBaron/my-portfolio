//Federico Baron
//9/10/18
//for loop practice

#include <stdio.h>

int main(){
	
	int choice = -1;

	while (choice < 1 || choice > 4) {
		printf("Please enter a number between 1 and 4\n");
		scanf("%d", &choice);
	}
	printf("You finally chose %d.\n", choice);

	return 0;
}