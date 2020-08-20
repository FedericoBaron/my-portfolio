
#include <stdio.h>

int fact(int n)
{
	if(n == 0)
		return 1;
	return fact(n)*fact(n-1);
}

int main()
{
	int a = fact(5)
	printf("%d\n", a);
}