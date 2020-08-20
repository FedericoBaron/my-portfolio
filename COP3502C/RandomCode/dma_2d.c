// Sean Szumlanski
// COP 3502, Spring 2019

// dma_2d.c
// ========
// Dynamic allocation of a 2D array. This is intense stuff.
//
// NOTE: You should probably check for invalid input (non-positive integers for
// array sizes) and NULL pointers from malloc(). I eliminated those checks to
// keep the code a bit more compact.


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, num_students, num_grades;

	// We saw that a dynamically allocated 1D integer array requires an int
	// pointer (i.e., int *array). With a 2D integer array, we need a double
	// integer pointer (i.e., int **array).
	//
	// In this example, I'll use this array to hold all the numeric grades for
	// all the students in a class. I'll need a 2D array for that. The first
	// dimension will be the number of students in the class, and the second
	// dimension will be the number of grades I have for each student (exam
	// grades, assignment grades, etc.).
	int **array;

	printf("How many students are in the class? ");
	scanf("%d", &num_students);

	// For each student in the class, I want an array. That is, for each student,
	// I need an (int *). If I create a whole array of (int *), then the base
	// address for that array is a pointer to the first (int *). That's why
	// the variable 'array' is of type (int **).
	array = malloc(sizeof(int *) * num_students);
	                    // ^ Get ready to create an array for each student,
	                    //   where we'll hold their grades for the course!

	// Now I have an array of addresses that I want to use to points to a bunch
	// of different arrays -- one for each student in the class. Assuming there
	// are just 5 students in my class, this is what memory looks like so far:
	//
	// array        0x1ef
	// +-------+    +-------+
	// | 0x1ef |    |       |
	// +-------+    +-------+
	//              |       |
	//              +-------+
	//              |       |
	//              +-------+
	//              |       |
	//              +-------+
	//              |       |
	//              +-------+

	printf("How many grades does each student have? ");
	scanf("%d", &num_grades);

	// Create the individual arrays for storing assignment/exam scores.
	for (i = 0; i < num_students; i++)
		array[i] = malloc(sizeof(int) * num_grades);

	// At this point, I have five arrays of length 'num_grades' in memory. Assuming
	// each students has, say, 8 grades this semester, memory now looks like this:
	//
	// array        0x1ef
	// +-------+    +-------+
	// | 0x1ef |    | 0x144 |  <-- this array (this first dimension of array) contains
	// +-------+    +-------+      pointers to integer arrays (i.e., each cell is of
	//              | 0x198 |      type (int *)). This, 'array' itself holds a pointer
	//              +-------+      to that first (int *), and so 'array' must hold an
	//              | 0x278 |      (int **) -- a pointer to an integer pointer.
	//              +-------+
	//              | 0x092 |
	//              +-------+
	//              | 0x554 |
	//              +-------+
	//
	// 0x144
	// +----+----+----+----+----+----+----+----+
	// |    |    |    |    |    |    |    |    |
	// +----+----+----+----+----+----+----+----+
	// 0x198
	// +----+----+----+----+----+----+----+----+
	// |    |    |    | ** |    |    |    |    |
	// +----+----+----+----+----+----+----+----+
	// 0x278
	// +----+----+----+----+----+----+----+----+
	// |    |    |    |    |    |    |    |    |
	// +----+----+----+----+----+----+----+----+
	// 0x092
	// +----+----+----+----+----+----+----+----+
	// |    |    |    |    |    |    |    |    |
	// +----+----+----+----+----+----+----+----+
	// 0x554
	// +----+----+----+----+----+----+----+----+
	// |    |    |    |    |    |    |    |    |
	// +----+----+----+----+----+----+----+----+
	//
	//  ^ Individual grade arrays, one per student.


	// Suppose we access array[1][3] at this point. The bracketed indices are
	// evaluated from left to right. So first, we evaluate array[1]. Recall
	// that the "[1]" tells us to go to array (which is the address 0x1ef in
	// this example) and skip forward 1 place (i.e., skip forward in memory
	// by however big an integer pointer is, since that's what the array holds).
	//
	// At array[1], we find the address 0x198. So, to C, array[1][3] looks a
	// lot like (0x198)[3] in this particular example. (There, I've just
	// replaced array[1] with (0x198), since that's what array[1] is.)
	//
	// We then apply the "[3]" to that memory address (0x198), which effectively
	// tells C to go to address 0x198 and then skip forward 3 places (i.e., skip
	// forward in memory by however much space three integers take up, since
	// that's what the 0x198 array is holding: integers).
	//
	// That gets us to the cell marked with an asterisks (**) in the 0x198 array
	// above.

	// Now, of course, we could fill up the arrays with grades and do some
	// processing.
	// ...
	// ... (do whatever you want with the 2D array here) ...
	// ...
	for (int i = 0; i < num_students; i++)
	{
		for (int j = 0; j < num_grades; j++)
		{
			array[i][j] = j * 10;
			printf("%d\n", array[i][j]);
		}
	}

	// Before we can free 'array', we have to free the individual arrays it's
	// pointing to. (Otherwise, we'll lose those memory addresses!) Two good
	// rules of thumb for avoiding memory leaks are:
	//
	//    1. Generally, free nested dynamically allocated memory in the opposite
	//       order from which it was allocated. (See below.)
	//
	//    2. For every call to malloc(), you (usually) want a corresponding call
	//       to free() somewhere in your program.

	// Free the individual arrays that hold student grades.
	for (i = 0; i < num_students; i++)
		free(array[i]);

	// Free the array that held the pointers to all those other arrays.
	free(array);

	return 0;
}