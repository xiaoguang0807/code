#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ERROR  -1
#define OK 1
#define TRUE 1
#define FALSE 0
#define OVERFLOW 1

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}Stack;


Status InitStack(Stack *s)
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE *sizeof(ElemType));
	if(!s->base) exit(OVERFLOW);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack


Status GetTop(Stack S,ElemType *e)
{
	if(S.top == S.base) 
		return ERROR;
	else
		*e =*(S.top - 1);
	return OK;
	
}//GetTop


Status Push(Stack *S, ElemType e)
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (ElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(ElemType));
		if(!S->base) exit(OVERFLOW);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top++) = e;
	return OK;
}//Push


Status Pop(Stack *S,ElemType *e)
{
	if(S->top == S->base) 
		return ERROR;
	else
		*e = *(--S->top);
	return OK;
}//Pop

Status IntDestory(Stack *s)
{
	if(s)
	{
		free(s->base);
		s = NULL;
		return OK;
	}
	else 
		return ERROR;
}

IntEmpty(Stack s)
{
    if(s.base == s.top)
        return OK;
    else
		return ERROR;
}//IntEmpty
/*main()
{
	int i,e;
	Stack s;

	InitStack(&s);
	for(i = 0; i <= 10; i++)
	{
		Push(&s,i);
	}
	for(i = 0; i<= 10; i++)
	{
		Pop(&s,&e);
		printf("%d",e);
	}
}*/
