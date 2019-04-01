// Sean Szumlanski
// COP 3502, Spring 2019

// struct-pointers.c
// =================
// This file covers pointers to structs, dynamic allocation of structs, and
// functions that take pointers to structs.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// See structs.c (also posted today) for notes on structs and typedef.
typedef struct student_info
{
	char *fName;
	char *lName;
	int id;
} student_info;

// This is a pass-by-reference version of the function we saw in structs.c.
// Notice that when we have a pointer to a struct, we have two options for
// accessing its members:
//
//    1. Dereference the pointer, then access the members as normal, with the
//       dot operator (.):
//
//       (*s).lName
//
//    2. Use the arrow operator (->) which takes care of the dereferencing for
//       you:
//
//       s->lName
//
// Now that we're using a pass-by-reference argument, here's a diagram of what's
// happening in memory when print_student() is called. Notice that within
// print_student(), s is just a tiny memory address, rather than a whole copy
// of the struct from main():
//
// main()                   print_student()
// +-----------------+      +-----------------+
// | s        0x8942 |      | s               |
// | +-------------+ |      | +--------+      |
// | | fName       | |      | | 0x8942 |      |
// | | +------+    | |      | +--------+      |
// | | | 0x86 |    | |      +-----------------+
// | | +------+    | |
// | |             | |
// | | lName       | |
// | | +------+    | |
// | | | 0x98 |    | |
// | | +------+    | |
// | |             | |
// | | id          | |
// | | +---------+ | |
// | | | 1234567 | | |
// | | +---------+ | |
// | +-------------+ |
// +-----------------+
//
//  0x86                    0x98
//  +---+---+---+---+---+   +---+---+---+---+---+---+---+---+---+---+---+
//  | S | e | a | n |\0 |   | S | z | u | m | l | a | n | s | k | i |\0 |
//  +---+---+---+---+---+   +---+---+---+---+---+---+---+---+---+---+---+
//
//   NOTE: Memory boxes not drawn to scale. ;)
//
void print_student(student_info *s)
{
	// The following lines are two ways of achieving the same result:
	printf("%s, %s (ID: %07d)\n", (*s).lName, (*s).fName, (*s).id);
	printf("%s, %s (ID: %07d)\n", s->lName, s->fName, s->id);

	// Since we're dealing with a pointer this time, notice how this changes
	// the output of main() after we return from this function. Compare this to
	// the result of structs.c.
	s->fName[0] = '\0';
	strcpy(s->lName, "lulhaxxedlololol");
	s->id = 6543210;
}

int main(void)
{
	int n;

	// This time, we'll allocate the struct dynamically.
	student_info *s = malloc(sizeof(student_info));
	//                                 ^ student is the datatype
	// Get length of first name.
	printf("How many letters are in your first name? ");
	scanf("%d", &n);

	// Allocate space for that name and scan it in. Notice the use of the arrow
	// operator (->) instead of the dot (.) since s is a *pointer* to a struct.
	s->fName = malloc(sizeof(char) * (n + 1));
	printf("Enter your first name: ");
	scanf("%s", s->fName);

	// Get length of last name.
	printf("How many letters are in your last name? ");
	scanf("%d", &n);

	// Allocate space for that name and scan it in.
	s->lName = malloc(sizeof(char) * (n + 1));
	printf("Enter your last name: ");
	scanf("%s", s->lName);

	// Allocate space for that name and scan it in. Notice that I want the
	// address of s's "id" field, so I got the field with s->id, and then took
	// the address of the *whole thing*, wrapped in parentheses.
	printf("What is the numeric portion of your student ID? ");
	scanf("%d", &(s->id));

	printf("\n");
	print_student(s);

	// Notice what happens when we return from the print_student() function.
	printf("\nMeanwhile, back in main()...\n\n");
	printf("%s, %s (ID: %07d)\n", s->lName, s->fName, s->id);

	// Notice that it wouldn't make sense to free s first, because then we
	// couldn't safely go back into s to free the lName and fName pointers. When
	// dealing with nested dynamic memory allocation, you generally want to free
	// things in the reverse order from which you allocated them. (However, it
	// doesn't matter whether we free s->lName or s->fName first, as long as we
	// free both of them before s itself.)
	free(s->lName);
	free(s->fName);
	free(s);

	// It's not strictly necessary to free any of that stuff since we're about
	// to return from main(), but I'm doing it anyway so you can see how it would
	// be done if we *weren't* about to exit the program, but still needed to
	// free the memory in order to avoid memory leaks.
 
	return 0;
}