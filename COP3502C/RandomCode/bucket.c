#include<stdio.h>

int find_max(int *array, int n)
{
	int i, max = 0;

	for(i = 0; i < n; i++)
	{
		if(array[i] > max)
			max = array[i];
	}

	return max;
}

void bucket_sort(int *array, int n)
{
	int max, *buckets

	max = find_max(array, n);
	buckets = calloc((max+1), sizeof(int));

	//throw everything into buckets
	for(i = 0; i < n; i++)
	{
		buckets[array[i]]++;
	}

	for(i = j = 0; i < max; i++)
	{
		if(buckets[i] > 0)
		{
			array[j++] = i;
			buckets[i]--;
		}
	}
}

int main(void)
{
	return 0;
}