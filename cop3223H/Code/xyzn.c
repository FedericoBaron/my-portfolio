//Federico Baron
//9/16/18
//x+y+z=n 

#include <stdio.h>

int main(void){
	
	int x, y, n, numsols;

	printf("Please enter n.\n");
	scanf("%d", &n);

	//go thru all possible x's
	for(x = 1; x < n; x++){

		//and y's
		for(y = x + 1; y < n; y++){

			//no third loop needed i know z!
			int z = n - x - y;

			//no point needed in looking for further z's
			if(z <= y)
				break;
		}

		//print and update counter
		printf("x = %d, y = %d, z = %d\n", x, y, z);
		numsols++;
	}

	printf("%d\n", numsols);
	return 0;
}