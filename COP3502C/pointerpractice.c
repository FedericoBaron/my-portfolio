#include <stdio.h>

void swap(int *ptr1, int *ptr2)
{
   int temp = *ptr1;
   *ptr1 = *ptr2;
   *ptr2 = temp;
}

int main(void)
{
   int i = 56, j = 10087;

   // Notice that I'm giving the addresses of i and j to the
   // swap() function. Therefore, swap() will be able to 
   // change the values of i and j from outside of main()!
   swap(&i, &j);

   // Now verify that your swap function worked.
   printf("i = %d, j = %d\n", i, j);

   return 0;
}