
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	
}

int getTriNum(int x, int y)
{
	//base case
	if(x == 1 && y == 1)
		return 1;

	if(x == 1)
	{
		return 1 + getTriNum(y-1, x);
	}
	return(1 + getTriNum(x-1, y+1));
}