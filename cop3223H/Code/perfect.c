//Federico Baron
//9/12/18
//perfect

#include<stdio.h>

int main(void){

	int n;
	printf("Please enter a positive integer greater than 1.\n");
	scanf("%d", &n);

	int sumdiv = 0, i;

	//loop thru all potential divisors
	for(i = 0; i < n / 2; i++){
		if(n % i == 0){
			sumdiv += i;
		}
	}

	if(sumdiv < n)
		printf("%d is deficient, its sum of proper divisors in only %d\n", n, sumdiv);
	else if(sumdiv > n)
		printf("%d is abundant, its sum of proper divisors is %d\n", n, sumdiv);
	else
		printf("Wonderful, %d is perfect!\n", n);
	
	return 0;

}