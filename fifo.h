//test.h - local prototype test
#define FIFOSIZE 4


struct fifo
{
  int data[FIFOSIZE]; //length
  int head;
  int tail;
  int count;
};

int initFifo(struct fifo *theFifo);
