#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct T
{
   int gl;
   char name[5];
} T;

struct T *create_a_struct(void)
{
  T *t = malloc(sizeof(T));

   // Initialize 'gl' to zero and 'name' to the empty string.
   t->gl = 0;
   strcpy(t->name, "");

   return t;
}

int main(void)
{
   T *data = malloc(sizeof(T));

   data->gl = 597;
   strcpy(data -> name, "chri");

   printf("%s (%d)\n", data->name, data->gl);
   T *hello = create_a_struct();

   free(data);
   free(hello);

   return 0;
}