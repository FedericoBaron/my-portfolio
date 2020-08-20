#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct T 
{
   int gl;
   char name[6];
} T;

struct T *create_a_struct(void)
{
   struct T *t = ((T*)malloc(sizeof(T)));

   // Initialize 'gl' to zero and 'name' to the empty string.
   t -> gl = 5;
   strcpy(t -> name, "hello");

   return t;
}

int main(void)
{
   T *data;

   data -> gl = 597;
   //data->name = "Vince";
   strcpy(data -> name, "Vince");
   printf("%s (%d)\n", data->name, data -> gl);

   T *test = malloc(sizeof(create_a_struct()));

   printf("%s (%d)\n", test->name, test->gl);

   return 0;
}