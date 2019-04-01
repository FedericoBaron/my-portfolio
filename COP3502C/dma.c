//DMA 

#include <stdio.h>
#include <stdlib.h> //must for malloc!!! 

int main(void)
{
	//static
	int i = 52;
	int *p = &i;
	int *array;
	int n;

	array = malloc(sizeof(int) * n);

	//dynamic


	printf("%d\n", *p); //prints number 
	printf("%p\n", &p); //prints address of p
	printf("%p\n", p) //prints address of i

	//variable declarations should be at top of function 
	int j;
	p = &j;


	//don't hard code number 4 because of bytes for diff systems
	//it also doesn't allow the person reading the code to know what 4 means
	//what if we wanna change the size
	//hey malloc i need an address with this much memory!!!!!
	//p now points to new memory space sizeof(int)
	p = malloc(sizeof(int));

	*p = 88;

	//pops balloon 
	free(p);

	p = malloc(sizeof(int));

	*p = 99;

	free(p);

	//you cant access the 88 anymore bc only p had access to it and the memory wasn't freed 
	//you cannot free things that were statically allocated
	//for every call to malloc hava a call to free! 



	//pointer arithmetic!!!!!! 
	//potential exam question about arithmetic (question: remove brackets in this for loop!)
	return 0;
}