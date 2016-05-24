#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIFOSIZE 3

struct lifo
{
  int data[LIFOSIZE]; //length
  int top;
};

int initLifo(struct lifo *theLifo)
{
  int i;
  printf ("initializing lifo at %p\n", theLifo);
  theLifo->top = -1;
  memset(theLifo->data, 0, sizeof(theLifo->data));
  printf("there are %d elements:\n", LIFOSIZE);
  for (i=0; i<LIFOSIZE; ++i)
    printf("%d ", theLifo->data[i]);
  return 0;
}

int LifoEmpty(struct lifo *lifoToCheck)
{
  int ret = lifoToCheck->top;
  printf("empty check: %d\n", ret);
  return (lifoToCheck->top == -1);
}

int push(int dataToPush, struct lifo *lifoToPush)
{
  lifoToPush->top++; 
  if (lifoToPush->top == LIFOSIZE)
  {
    printf ("lifo is FULL - not pushing\n");
  }
  else  
  {
    lifoToPush->data[lifoToPush->top] = dataToPush;
  }
  return 0;
}

int pop(struct lifo *lifoToPop)
{
  if (LifoEmpty(lifoToPop))
  {
    printf("lifo empty- nothing to pop\n");
    return -1;
  }
  else
  {
    lifoToPop->top--;
  }
  printf("returning from index %d\n", lifoToPop->top+1);
  return(lifoToPop->data[lifoToPop->top+1]);
}

void displayLifo(struct lifo *lifoToPrint)
{
  int i = 0;
  printf("\ndisplayLifo entry; top: %d\n", lifoToPrint->top);
  while(i < LIFOSIZE)
  {
    printf("i: %d val: %d  \n", i, lifoToPrint->data[i]);
    i++;
  }
}

int main (void)
{
  int  in, ret;
  char option[100];
  struct lifo myLifo;
  printf("\nThis demonstrates a LIFO queue with size %d\n", LIFOSIZE);
  initLifo(&myLifo);
  while(1)
  {
    printf("\nenter push <value> or pop: ");
    scanf("%s", option);
    printf("option: %s \n", option);
    if (strstr(option, "push") || (strstr(option, "pop"))) 
    {
      if (strstr(option, "push"))
      {
        //printf("\nenter data to push: %d", in);
        scanf("%d", &in);
        push(in, &myLifo);
      }
      else
      {
        printf("\npopping\n");
        ret = pop(&myLifo);
        if(ret != -1) printf("popped: %d\n", ret);
      }
    }
    else
    {
      printf ("Try again\n");
      //return 0;
    }
    displayLifo(&myLifo);
  }
  return 0;
}


