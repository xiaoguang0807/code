/*************************************************************************
	> File Name: Queue.c
	> Author: li
	> Mail: xiaoguang.li.0807@Gmail.com 
	> Created Time: Sun 10 Nov 2013 10:51:40 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"define.h"

typedef int QElemType;

typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue *p)
{
    p->front = p->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!p->front) exit(OVERFLOW);
    p->front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue *p)
{
    while(p->front)
    {
        p->rear = p->front->next;
        free(p->front);
        p->front = p->rear;
    }
    return OK;
}

Status ClearQueue(LinkQueue *p)
{
    QNode *q,*l;
    q = p->front;
    while(q)
    {
        
    }
}
main()
{
    LinkQueue Q;
    InitQueue(&Q);
    DestroyQueue(&Q);

}
