#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int main(){
	

	int i,n;
	char value; // generic
	char top; //generic
	stack s;
	stackInit(&s,sizeof(char)); //generic size
	printf("Enter the size of stack:");
	scanf("%d",&n);
	printf("enter elements\n");
	for(i=0;i<n;i++){
		scanf("%c",&value); // change the access specifier based on datatype
		stackPush(&s,&value);
	}
	printStack(&s);
	stackPop(&s,&top);
	printf("\n\n Old top : %c",top); // change the access specifier based on datatype
	stackDestroy(&s);
	return 0;
}

void stackInit(stack *s, int elemsize){
	s->elemsize = elemsize;
	s->allocsize = 4;
	s->logsize = 0;
	s->elem = malloc(s->allocsize*s->elemsize);
	return;
}

void printStack(stack *s){
	int i=s->logsize-1;
	void *n = NULL;
	if(s->elem!=NULL){
	printf("Stack Elements\n");
	while(i>=0){
	void *n = (char *)s->elem + ((i)*s->elemsize);
	printf("%c\t",*(char *)n); // change the access specifier and type cast based on datatype
	--i;
	}
	}
	else{
		printf("\nStack is empty");
	}
}

void stackPush(stack *s,void *elemAddr){
	if(s->allocsize==s->logsize){
		s->allocsize = s->allocsize*2;
		s->elem = realloc(s->elem,s->allocsize*s->elemsize);
		assert(s->elem!=NULL);
	}
	void *target = (char *)s->elem + (s->logsize*s->elemsize);
	memcpy(target,elemAddr,s->elemsize);
	s->logsize++;
	return;
}

void stackDestroy(stack *s){
	s->elem = NULL;
	free(s->elem);
	printf("\n\nStack Destroyed");
	printStack(s);
}

void stackPop(stack *s,void *elemAddr){
	void *newtop = (char *)s->elem + ((s->logsize-1) * s->elemsize);
	memcpy(elemAddr,newtop,s->elemsize);
	s->logsize--;
	printf("\n\nAfter POP");
	printStack(s);
}
