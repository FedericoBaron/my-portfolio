// Sean Szumlanski
// COP 3502, Spring 2019

// structs.c
// =========
// Basic intro to structs, which allow us to package together related pieces
// of information. The structs we created had some pointers within them. Check
// out the effect this has on memory when we try to change values within the
// struct from a pass-by-value function.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct is basically a new data type that bundles up all kinds of individual
// pieces of data (called "fields" or "members" of the struct) into a neat
// little package. This makes it really easy to keep together strongly
// associated pieces of data, and also helps reduce the number of arguments
// we have to pass to some of our functions.
//
// Notice the typedef syntax. We are taking the struct student_info { ... }
// definition and making 'student_info' a synonym for it. Now, instead of typing
// "struct student_info" to create a variable of this type, we can just type
// "student_info".
typedef struct student_info
{
	char *fName;
	char *lName;
	int id;
} student_info; // Just because we have "struct student_info" doesn't mean we
                // had to use "student_info" here. We could have typedef'ed this
                // as something crazy like "my_fave_struct".


// The print_student() function below is a pass-by-value function. It creates a
// new copy of s in memory. All the contents of main's student_info struct are
// copied into this new student_info struct. Because we're copying some string
// addresses into here, we're able to use them to modify the strings held in
// main's student_info struct. However, we are not able to change the ID that
// resides back in main's student_info struct.
//
// More clearly (perhaps), here's a diagram of what's happening in memory when
// print_student() is called initially:
//
// main()                   print_student()
// +-----------------+      +-----------------+
// | s               |      | s               |
// | +-------------+ |      | +-------------+ |
// | | fName       | |      | | fName       | |
// | | +------+    | |      | | +------+    | |
// | | | 0x86 |    | |      | | | 0x86 |    | |
// | | +------+    | |      | | +------+    | |
// | |             | |      | |             | |
// | | lName       | |      | | lName       | |
// | | +------+    | |      | | +------+    | |
// | | | 0x98 |    | |      | | | 0x98 |    | |
// | | +------+    | |      | | +------+    | |
// | |             | |      | |             | |
// | | id          | |      | | id          | |
// | | +---------+ | |      | | +---------+ | |
// | | | 1234567 | | |      | | | 1234567 | | |
// | | +---------+ | |      | | +---------+ | |
// | +-------------+ |      | +-------------+ |
// +-----------------+      +-----------------+
//
//  0x86                    0x98
//  +---+---+---+---+---+   +---+---+---+---+---+---+---+---+---+---+---+
//  | S | e | a | n |\0 |   | S | z | u | m | l | a | n | s | k | i |\0 |
//  +---+---+---+---+---+   +---+---+---+---+---+---+---+---+---+---+---+
//
//   NOTE: Memory boxes not drawn to scale. ;)
//
//
// Then, AFTER the last three lines of the function, right before returning to
// main(), we have this:
//
// main()                   print_student()
// +-----------------+      +-----------------+
// | s               |      | s               |
// | +-------------+ |      | +-------------+ |
// | | fName       | |      | | fName       | |
// | | +------+    | |      | | +------+    | |
// | | | 0x86 |    | |      | | | 0x86 |    | |
// | | +------+    | |      | | +------+    | |
// | |             | |      | |             | |
// | | lName       | |      | | lName       | |
// | | +------+    | |      | | +------+    | |
// | | | 0x98 |    | |      | | | 0x98 |    | |
// | | +------+    | |      | | +------+    | |
// | |             | |      | |             | |
// | | id          | |      | | id          | |
// | | +---------+ | |      | | +---------+ | |
// | | | 1234567 | | |      | | | 6543210 | | |
// | | +---------+ | |      | | +---------+ | |
// | +-------------+ |      | +-------------+ |
// +-----------------+      +-----------------+
//
//  0x86                    0x98
//  +---+---+---+---+---+   +---+---+---+---+---+---+---+---+---+---+---+
//  |\0 | e | a | n |\0 |   | l | u | l | h | a | x | x | e | d | l | o | l o l o l \0
//  +---+---+---+---+---+   +---+---+---+---+---+---+---+---+---+---+---+
//                                                                             ^ LOL!
//                                                           You're in big trouble now!
//
// Notice that the string addresses within the struct allowed print_student()
// to modify the strings! However, the ID in main's copy of the struct was
// *not* modified, since we don't have a pointer to it.
//
void print_student(student_info s)
{
	// We use the dot operator (.) to access individual members of a struct.
	printf("%s, %s (ID: %07d)\n", s.lName, s.fName, s.id);

	s.fName[0] = '\0';
	strcpy(s.lName, "lulhaxxedlololol");
	s.id = 6543210;
}

int main(void)
{
	int n;
	student_info s;

	// Get length of first name.
	printf("How many letters are in your first name? ");
	scanf("%d", &n);

	// Allocate space for that name and scan it in.
	s.fName = malloc(sizeof(char) * (n + 1));
	printf("Enter your first name: ");
	scanf("%s", s.fName);

	// Get length of last name.
	printf("How many letters are in your last name? ");
	scanf("%d", &n);

	// Allocate space for that name and scan it in.
	s.lName = malloc(sizeof(char) * (n + 1));
	printf("Enter your last name: ");
	scanf("%s", s.lName);

	// Read in user's ID.
	printf("What is the numeric portion of your student ID? ");
	scanf("%d", &(s.id));

	// We can now pass all the student's information to the print_student()
	// function with a single variable.
	printf("\n");
	print_student(s);

	// Notice what happens when we return from the print_student() function.
	printf("\n");
	printf("%s, %s (ID: %07d)\n", s.lName, s.fName, s.id);
	printf("\nNotice the ID did not change, but the first and last name did!");
	printf("\nWhy is that?\n");

	free(s.fName);
	free(s.lName);
	return 0;
}