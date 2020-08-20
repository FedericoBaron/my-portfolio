// Sorting Algorithms

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[i+1];
	arr[i+1] = tmp;
}

// Best O(n)
// Worst O(n^2)
void bubble_sort(int *arr, int n)
{
	int i, swapped = 1;

	while(swapped)
	{
		swapped = 0;

		for(i=0; i<n-1; i++)
		{
			if(arr[i] > arr[i+1]){
				swap(arr, i, i+1);
				swapped = 1;
			}
		}
	}

}

// Best O(n^2)
// Worst O(n^2)
void selection_sort(int *arr, int n)
{
	int i, start, idxOfSmallest;

	for(start = 0; start < n-1; start++){
		// Single pass
		idxOfSmallest = arr[start];

		for(i=start+1; i<n; i++)
			if(arr[i] < arr[idxOfSmallest])
				idxOfSmallest = i;
			
		swap(arr, start, idxOfSmallest);
	}
}

// Best O(n)
// Worst O(n^2)
void insertion_sort(int *arr, int n)
{
	int start, peach, gap;

	for(start = 1; start<n; start++)
	{
		peach = arr[start];
		for(gap = start; gap > 0 && arr[gap-1] > peach; gap--)
			arr[gap] = arr[gap-1];

		arr[gap] = peach;
	}
}

void print(int *arr, int n)
{
	int i;

	for(i=0; i<n; i++){
		printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
	}
}

void bucket(int *arr, int n, int range)
{
	int i, j, idx;
	int* buckets = calloc(range + 1, sizeof(int));

	for(i=0; i<n; i++)
		buckets[arr[i]]++;

	// for(i=0; i<range; i++){
	// 	for(j=0; j<buckets[i]; j++){
	// 		arr[idx] = i;
	// 		idx++;
	// 	}
	// }

	for(i=j=0; i<range; i++){
		while(buckets[i] --> 0)
			arr[j++] = i;
	}

	free(buckets);

}

// O(???)
void radix_sort()
{
	
}

void merge_sort_for_real(int* arr, int lo, int hi)
{
	int mid, *aux, i, j, idx;

	if(lo >= hi)
		return;

	mid = lo + (hi - lo)/2;

	merge_sort_for_real(arr, lo, mid);
	merge_sort_for_real(arr, mid + 1, hi);

	// Merge
	aux = malloc(sizeof(int) * (hi - lo + 1));

	i = lo;
	j = mid + 1;
	idx  = 0;

	while(i <= mid || j<=hi)
	{
		if(i > mid || (j <= hi && arr[j] <= arr[i]))
			aux[idx++] = arr[j++];
		else
			aux[idx++] = arr[i++];
	}

	for(i=lo; i<=hi; i++)
		arr[i] = aux[i-lo];
	
	free(aux);
}

// O(nlog(n))
void merge_sort(int *arr, int n)
{
	merge_sort_for_real(arr, 0, n - 1);

}

// Quicksort:
// 1. Perform our partitioning operation O(n)
// 2. Quicksort everything to the left of the pivot 
// 3. Quicksort everything to the right of the pivot 

// Recurrence relation: (if pivot ends up in middle of array)
// T(0) = T(1) = c1
// T(n) = c*n + 2T(n/2) + c0 for n > 1
// O(nlogn)

// Worst case: O(n^2)
// Best case: O(nlogn)
// Average case: O(nlogn)

// Real-world optimizations for quicksort
// 1. Median of Three Pivot Selection
// 2. Median of Five Pivot Selection (really good for large arrays)
// 3. When you hit a sub-array of length 10 to 20, stop making recursive
//    calls to quicksort and just call any old garden variety O(n^2) sort.

void quick_sort(int *arr, int n)
{

}

int main(void){

	int i, n = 10, array[10];

	srand(time(NULL));

	for(i=0; i<10; i++)
		array[i] = rand() % 100 + 1;

	print(array, 10);

	quick_sort(array, 10);

	print(array, 10);

	return 0;
}