#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "fifo.h"

int initFifo(struct fifo *theFifo)
{
  int i;
  printf ("initializing fifo at %p\n", theFifo);
  theFifo->tail = theFifo->head = theFifo->count = 0;
  memset(theFifo->data, 0, sizeof(theFifo->data));
  printf("there are %d elements:\n", FIFOSIZE);
  for (i=0; i<FIFOSIZE; ++i)
    printf("%d ", theFifo->data[i]);
  return 0;
}

int isFull(struct fifo *fifoToCheck)
{
  return (fifoToCheck->count == FIFOSIZE);
}

int isEmpty(struct fifo *fifoToCheck)
{
  return (fifoToCheck->count == 0);
}


int push(int dataToPush, struct fifo *fifoToPush)
{
  if (isFull(fifoToPush))
  {
    printf ("fifo is FULL - no push\n");
    return -1;
  }
  fifoToPush->data[fifoToPush->tail] = dataToPush;
  
  if(fifoToPush->tail == FIFOSIZE-1)
    fifoToPush->tail = 0;
  else  
    fifoToPush->tail++; 

  fifoToPush->count++;

  return 0;
}

int pop(struct fifo *fifoToPop)
{
  int ret = fifoToPop->data[fifoToPop->head];
  if (isEmpty(fifoToPop))
  {
    printf ("nothing left to pop\n");
    return -1;
  }
  if(fifoToPop->head == FIFOSIZE-1)
  {
    printf ("fifo is full (popping last element, then reset)\n");
    fifoToPop->head = 0;
  }
  else
  {
    fifoToPop->head++;
  }
  fifoToPop->count--;
  return ret;
}

void displayFifo(struct fifo *fifoToPrint)
{
  int i = 0;
  //int i = fifoToPrint->head;
  printf("\ndisplayFifo entry; head: %d tail: %d count: %d\n", 
      fifoToPrint->head, fifoToPrint->tail, fifoToPrint->count);
  while(i < FIFOSIZE)
  {
    printf("i: %d val: %d  \n", i, fifoToPrint->data[i]);
    i++;
  }
}

int main (void)
{
  int  in, ret;
  char option[100];
  struct fifo myFifo;
  printf("\nThis demonstrates a FIFO queue with size %d\n", FIFOSIZE);
  initFifo(&myFifo);
  while(1)
  {
    printf("\nenter push <value> or pop: ");
    scanf("%s", option);
    printf("option: %s \n", option);
    if (strstr(option, "push") || (strstr(option, "pop"))) 
    {
      if (strstr(option, "push"))
      {
        scanf("%d", &in);
        push(in, &myFifo);
      }
      else
      {
        printf("\npopping\n");
        ret = pop(&myFifo);
	if (ret==-1)
	  printf("fifo is empty\n");
	else
          printf("popped: %d\n", ret);
      }
    }
    else
    {
      printf ("Try again\n");
      return 0;
    }
    displayFifo(&myFifo);
  }
  return 0;
}


