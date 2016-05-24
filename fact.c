#include <stdio.h>
float av(float *farray, size_t size);
int setCount (float val);
int main (int argc, char **argv)
{
  long userInput, ret;
  printf("/nenter a number between 1 and 100 : ");
  scanf("%ld", &ret);
  if (ret > 0 & ret < 101)
  {
    userInput = ret;
    for (long i=1; i<userInput; ++i)
    {
      ret *= i;
      printf("ret: %ld' i: %ld\n", ret, i);
    }
    printf ("the factorial of %ld is %ld\n", userInput, ret);
  }
  else
    printf ("Try again\n");
  return 0;
}


