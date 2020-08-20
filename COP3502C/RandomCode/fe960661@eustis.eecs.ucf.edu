// Sean Szumlanski
// COP 3502, Spring 2019 - Week #2 Lab Instruction
//
// =============================================================================
// INTRODUCTION TO GDB
// =============================================================================
//
// This program is used to show you how you can use gdb to track down the exact
// line where a program is crashing, without having to use tons of tedious
// printf() statements. If we had more time in class or in labs, we'd also show
// you how to set breakpoints in your code and use gdb to step through your
// program, as well as how to use the CodeBlocks debugger. We encourage you to
// read up on those things on your own time.
//
// For links to resources on these topics, see this week's recitation page in
// Webcourses.
//
// =============================================================================
//
// Tracking down a crash with gdb:
//
// 1. When using gdb to track down the cause of a crash, first, it's important
//    that you compile your code with the -g flag, like so:
//
//       gcc gdb_basics.c -g
//
// 2. Next, run the program (using "./a.out") to verify that it's crashing.
//
// 3. To track down the source of the crash, run the program through gdb:
//
//       gdb ./a.out
//
// 4. That will load gdb. It's now ready to run your program, which you do by
//    typing the following command:
//
//       run
//
// 5. You should see the output of this program, and information about it
//    crashing. You should still be in gdb at this point. You can perform what's
//    called a "backtrace" to show the exact sequence of function calls (with
//    line numbers from your source code) to show the sequence of events that
//    led to the program's crash. Type the following command in gdb to perform a
//    backtrace:
//
//       bt
//
//    Notice that the backtrace tells you not only that you crashed after
//    calling bar(), but it tells you explicitly that the crash occurred when
//    you called bar(2) from foo()!
//
// 6. Okay, so you know what line you crashed on, and you know i=2, but how do
//    you figure out what value of j caused the crash? (Here, it's obvious
//    because of how the code was written, but in the assignments you work on
//    this semester, there will be a lot of variables in play, and it won't
//    always be obvious what values are causing you to crash.)
//
//    You *could* put a bunch of printf() and fflush() statements inside of
//    bar's for-loop to help you figure out what value of j is causing the
//    crash, but gdb lets you inspect the values of any variable you want at the
//    time crash occurred. You can print them out with a "print" command in gdb,
//    like so:
//
//       print i
//       print j
//
//    ...and so on. The output of those two commands should be:
//
//       $1 = 2
//       $2 = 3
//
//    (Instead of printing the variable name you requested, the print command
//    uses "$1", "$2", "$3", and so on, incrementally. The value it's printing
//    on the right-hand side of that equal sign is the value you want, though.)
//
//    You can also use "p" instead of "print," like so:
//
//       p i
//       p j
//
//    By default, the "print" command prints variables inside the function where
//    you crashed. If you want to know the value of some variable in a different
//    function, you can use the function::variable syntax, like so:
//
//       print foo::i
//       print foo::t
//
// 7. When you're all finished, type "quit" to quit out of gdb. If it says a
//    process will be killed when you exit, that's fine; just type "y" and hit
//    enter.
//
// =============================================================================


#include <stdio.h>

void bar(int i)
{
	int j, *ptr = NULL;

	for (j = 0; j < 5; j++)
	{
		if (i == 2 && j == 3)
			*ptr = 23;  // lol
	}
}

void foo(void)
{
	int i, t = 88;

	for (i = 0; i < 5; i++)
		bar(i);
}

int main(void)
{
	foo();
	return 0;
}
