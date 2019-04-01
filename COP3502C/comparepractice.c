#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int strcmp_i(const char *str1, const char *str2);

int main(void)
{
   char *name = NULL;
   char *name2 = NULL;

   // length of the dynamically allocated string
   int array_size = -1;

   // length of the user's name
   int length = -1;

   while (1)
   {
      printf("How many letters are in your name? (0 to quit) ");

      // Note: scanf() always wants the address
      // where it should store the input it's reading.
      scanf("%d", &length);

      if (length == 0)
         break;

      if (length + 1 > array_size)
      {
         // Finish this line
         name = malloc(sizeof(char) * (length + 1));
         name2 = malloc(sizeof(char) * (length + 1));
         array_size = length + 1;
      }

      // Check your understanding: Why do we
      // use name instead of &name in this
      // scanf() statement?
      scanf("%s", name);
      printf("You entered: **%s**\n\n", name);
      scanf("%s", name2);
      printf("You entered: **%s**\n\n", name2);

      printf("%d\n", strcmp_i(name, name2));

      printf("%s\n", name);
      printf("%s\n", name2);


      free(name);
      free(name2);
      array_size = -1;
   }

   return 0;
}

int strcmp_i(const char *str1, const char *str2)
{
   char str3[sizeof(str1) + 1], str4[sizeof(str2) + 1];

   for(int i = 0; i < sizeof(str1); i++)
   {
      if(isupper(str1[i]))
         str3[i] = tolower(str1[i]);
      else
         str3[i] = str1[i];
   }
   for(int i = 0; i < sizeof(str1); i++)
   {
      if(isupper(str2[i]))
         str4[i] = tolower(str2[i]);
      else
         str4[i] = str2[i];
   }

   printf("**%s**\n", str3);
   printf("**%s**\n", str4);

   return strcmp(str3, str4);
}