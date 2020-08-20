#include <stdio.h>

int main(void)
{
	int i = ~((84 ^ 116) << 2);
	printf("%d\n", i);
	return 0;
}