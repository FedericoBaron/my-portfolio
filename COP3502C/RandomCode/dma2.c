// Sean Szumlanski
// COP 3502, Spring 2019

// dma_part2.c
// ===========
// Dynamic allocation of 1D arrays.


#include <stdio.h>
#include <stdlib.h>

// This is a bit tongue-in-cheek. You'll see me use it throughout the semester.
void panic(char *err_msg)
{
	fprintf(stderr, "%s", err_msg);
	exit(1);
}

int main(void)
{
	// static declarations
	int i, n, *array = NULL;

	printf("How many integers do you want to store? ");
	scanf("%d", &n);

	// We saw that malloc() wants to know how big of a block to find in memory.
	// For arrays, which are contiguous in memory, we can tell malloc() how big
	// the block needs to be by supplying two pieces of information:
	//
	// a) the size of the data type we're storing in the array.
	// b) the number of elements we'll be storing in the array.
	// ^ multiply these two to get the overall amount of memory to set aside

	// So, to allocate an array that can hold n integers, we use:
	array = malloc(sizeof(int) * n);

	// Check whether malloc() was successful.
	if (array == NULL)
		panic("ERROR! Could not allocate enough memory in main()!\n");

	// Now you can access the individual elements in 'array' as if it were any
	// other array you've ever messed around with. Here, I'm just storing
	// multiples of 10:
	for (i = 0; i < n; i++)
		array[i] = i * 10;

	// Let's print those out for posterity:
	for (i = 0; i < n; i++)
		printf("array[%d]: %d\n", i, array[i]);
	printf("\n");

	// NOTE: When you call free() on a dynamically allocated array, the ENTIRE
	// block of memory associated with that array is wiped out. You do NOT have
	// to free each element individually.
	free(array);
	
	// NOTE: One interesting thing is, if we had just allocated space for a
	// single integer, this would still work! Check it out:
	array = malloc(sizeof(int));

	// Now, we can just dereference 'array' like we dereferenced 'p' in the
	// previous DMA source file (dma_part1.c), --or-- we can use our array
	// notation. These two lines are equivalent:
	*array = 52;
	array[0] = 53;

	// Similarly, we can print the value in that single integer cell using
	// either notation:
	printf("*array: %d\n", *array);
	printf("array[0]: %d\n\n", array[0]);

	// So, what we start to see is that there's a strong relationship between
	// pointers and arrays. In particular, what a[i] means in C is: 'array' is
	// the base of an array (whose type is declared and known), so GO to the
	// base of that array, then skip forward 'i' spaces. (If we're dealing with
	// integers, skipping forward a single space means skipping forward to the
	// next integer -- 4 bytes (or 32 bits) on most systems, although YMMV.)

	// For more on this, see my notes on pointer arithmetic.

	return 0;
}