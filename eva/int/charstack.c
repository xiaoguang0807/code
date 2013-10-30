#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0
//#define OVERFLOW 1

typedef int Status;
//typedef char ElemType;

typedef struct
{
	char *base;
	char *top;
	int stacksize;
}CharStack;


Status CharInitStack(CharStack *s)
{
	s->base = (char *)malloc(STACK_INIT_SIZE *sizeof(char));
	if(!s->base) exit(1);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack


char CharGetTop(CharStack S)
{
	if(S.top == S.base)
            return ERROR;
    else
        return *(S.top - 1);
	
}//GetTop


Status CharPush(CharStack *S,char e)
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (char *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(char));
		if(!S->base) exit(1);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top++) = e;
	return OK;
}


char CharPop(CharStack *S)
{
	if(S->top == S->base) return ERROR;
	return *(--S->top);
}//Pop

int CharDestory(CharStack *s)
{
	if(s)
	{
		free(s->base);
		s = NULL;
//		printf("destory stack success");
		return 1;
	}
	else
		return 0;
}

int CharStackEmpty(CharStack s)
{
    if(s.base == s.top)
        return 1;
    else
        return 0;
}
//main()
//{
//	CharStack c;
//	char s;
//
//	CharInitStack(&c);
//	CharPush(&c,'#');
//	s = CharPop(&c);
//	printf("%c",s);
//}


