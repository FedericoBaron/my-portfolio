#include <stdio.h>

int main(void){
	int n = 5;
	int mid, edge, len;
	len = n*2-1;
	mid = n-1;
	for(int i=0;i<mid;i++){
		edge = len-1-i;
		for(int j=0;j<len;j++){
			if(j==i||j==edge)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}