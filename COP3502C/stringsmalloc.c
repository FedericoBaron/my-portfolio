#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct T
{
   int gl;
   char name[1];
} T;

struct T *create_a_struct(void);

int main(void)
{
   T *test = create_a_struct();

   printf("%d gl and %s name\n", test->gl, test->name);

   return 0;
}

struct T *create_a_struct(void)
{
   T *t = malloc(sizeof(T));

   // Initialize 'gl' to zero and 'name' to the empty string.
   t -> gl = 0;
   strcpy(t -> name, "");

   return t;
}