#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	srand(time(0));

	int aroll1 = rand() %6 + 1;
	int aroll2 = rand() %6 + 1;
	int broll1 = rand() %6 + 1;
	int broll2 = rand() %6 + 1;

	printf("%d %d %d %d\n", );

	if(aroll1 < aroll2){
		int temp = aroll2;
		aroll2 = aroll1;
		aroll1 = temp;
	}
	if(broll1 < broll2){
		int temp = broll2;
		broll2 = broll1;
		broll1 = temp;
	}


}