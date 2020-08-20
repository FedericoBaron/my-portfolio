#include <stdio.h>
#include <stdlib.h>

int *array(int m, int n);

int main()
{
	return 0;	
}

int *array(int m, int n)
{
	int **2d = malloc(sizeof(int*) * n)

	for (int i = 0; i < n; i++)
	{
		array[i] = malloc(sizeof(int) * m);
	}

	return 2d;
}