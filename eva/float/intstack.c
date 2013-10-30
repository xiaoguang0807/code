#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0
//#define OVERFLOW 1

typedef int Status;
typedef float ElemType;

typedef struct
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}IntStack;


Status IntInitStack(IntStack *s)
{
	s->base = (float *)malloc(STACK_INIT_SIZE *sizeof(float));
	if(!s->base) exit(1);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack


float IntGetTop(IntStack S)
{
	if(S.top == S.base) return ERROR;
	return  *(S.top - 1);
	
}//GetTop


Status IntPush(IntStack *S, float e)
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (float *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(float));
		if(!S->base) exit(1);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top++) = e;
	return OK;
}


float IntPop(IntStack *S)
{
	if(S->top == S->base) return ERROR;
	return *(--S->top);
}//Pop

int IntDestory(IntStack *s)
{
	if(s)
	{
		free(s->base);
		s = NULL;
		return 1;
	}
	else
		return 0;
}
int IntEmpty(IntStack s)
{
    if(s.base == s.top)
        return 1;
    else
        return 0;
}
//main()
//{
//	int i,e;
//	IntStack s;

//	IntInitStack(&s);
//	for(i = 0; i <= 10; i++)
//	{
//		IntPush(&s,i);
//	}
//	for(i = 0; i<= 10; i++)
//	{
//		e = IntPop(&s);
//		printf("%d",e);
//	}
//}
