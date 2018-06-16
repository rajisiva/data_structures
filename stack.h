#include<stdio.h>
//
typedef struct{
	void *elem;
	int elemsize;
	int logsize;
	int allocsize;
}stack;
//
void stackInit(stack *s,int elemsize);
void stackDestroy(stack *s);
void stackPush(stack *s,void *elemAddr);
void printStack(stack *s);
void stackPop(stack *s,void * elemAddr);


