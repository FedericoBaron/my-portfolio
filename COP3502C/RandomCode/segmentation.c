//segmentation faults (CRASHING CRASH COURSE)
 
 #include <stdio.h>

int main(void)
{
	//seg fault bc it's a garbage address
	int *p;
	*p = 52;

	//coding defensively is checking for potential errors 
	//%d is a conversion code
	return 0;

	//deferncing null pointer
	//deferncing uninitialized pointer
	//setting values outside the allocated memory 
	//out of bounds array 

	//Shittiest way of wrecking yourself
	//corrupted pointer (out of bounds in array and corrupt pointer)

	//fflush(stdout)

	//how to spot seg fault
	//look at pointers and arrays
}