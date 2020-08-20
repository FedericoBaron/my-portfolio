//Federico Baron
//Fibonacci dp

#include<stdio.h>

int fib(int n);

int main(void){

	printf("%d\n", fib(9));

	return 0;
}

int fib(int n){

	int fibo[n + 2];

	fibo[0] = 0;
	fibo[1] = 1;

	for(int i = 2; i <= n; i++){
		fibo[i] = fibo[i-1] + fibo[i-2];
	}

	return fibo[n];

} 