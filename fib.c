#include <stdio.h>

int fib_iterative(int num)
{
   if (num == 1)
   {
      return 0;
   }
   else if (num == 2)
   {
      return 1;
   }

   int num_prev = 0;
   int num_current = 1;
   int num_next;

   for (int i = 2; i < num; i++)
   {
      num_next = num_prev + num_current;
      num_prev = num_current;
      num_current = num_next;
   }

   return num_current;
}

int fib_recursive(int num)
{
   if (num == 1)
   {
      return 0;
   }
   else if (num == 2)
   {
      return 1;
   }

   return fib_recursive(num - 1) + fib_recursive(num - 2);
}

int main(int argc, char *argv[])
{
   int num_arg;
   int num_file;
   int num_total;
   int num_final;
   char option = argv[2][0];
   FILE *file = fopen(argv[3], "r");

   sscanf(argv[1], "%d", &num_arg);

   fscanf(file, "%d", &num_file);
   fclose(file);

   num_total = num_arg + num_file;

   if (option == 'i')
   {
      num_final = fib_iterative(num_total);
      printf("%d\n", num_final);
   }
   else if (option == 'r')
   {
      num_final = fib_recursive(num_total);
      printf("%d\n", num_final);
   }

   return 0;
}
