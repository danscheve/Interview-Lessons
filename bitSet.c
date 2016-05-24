#include <stdio.h>
float av(float *farray, size_t size);
int setCount (float val);
int main (int argc, char **argv)
{
  float test[] = {1,2,3,4,5,6,7,8,9,10};
  size_t tsize = sizeof(test) / sizeof(float);
  float avg = av(test, tsize);
  printf ("avg: %f float size: %lu testsize: %lu array size: %lu\n",avg, 
      sizeof(float), sizeof(test), tsize);
  return 0;
}

int setCount (float val)
{
  int ret = 0;
  int i, bitsInFloat = sizeof(float) * 8;
  unsigned shift = 1;
  for (i=0; i < bitsInFloat; ++i)
  {
    if ((unsigned)val & shift) ++ret;
    shift <<= 1;
  }
  return ret;
}

float av(float *farray, size_t size)
{
  int i, count=0;
  float ret = 0;
  for (i=0; i < size; ++ i)
  {
    ret += farray[i];
  }
  unsigned shift = 1;
  for (i=0; i < size; ++ i)
  {
    printf("element: %f\n", farray[i]);
    printf("There are %d bits set in %f \n", setCount(farray[i]), farray[i]);
  }
  return (ret / size);
}

