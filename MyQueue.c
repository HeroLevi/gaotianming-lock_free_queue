#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef struct
{
	int *base;
	int head;
	int tail;
}MyQueue;

bool InitQueue(MyQueue* q)
{
	q->base = (int*)malloc(sizeof(int)*(MAXSIZE));
	if(!q->base)
	{
		return false;
	}
	q->head = q->tail = 0;
	return true;
}

bool PushQueue(MyQueue* q,int e)
{
	if((q->tail + 1) % MAXSIZE == q->head)//queue is full
		return false;
	q->base[q->tail] = e;
	q->tail = (q->tail + 1) % MAXSIZE;
	return true;
}

bool PopQueue(MyQueue* q,int *e)
{
	if(q->head == q->tail)//queue is empty
		return false;
	*e = q->base[q->head];
	q->head = (q->head + 1) % MAXSIZE;
	return true;
}

int main(void)
{
	MyQueue queue;
	InitQueue(&queue);
	int a = 100;
	PushQueue(&queue,a);
	printf("%d\n",queue.base[queue.head]);
	PopQueue(&queue,&a);
	printf("%d\n",queue.base[queue.head]);

	return 0;
}
