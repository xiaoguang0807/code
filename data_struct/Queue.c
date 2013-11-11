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
}//InitQueue

Status DestroyQueue(LinkQueue *p)
{
    if(p->front == p->rear)
    {
        free(p->front);
        return OK;
    }
    while(p->front)
    {
        p->rear = p->front->next;
        free(p->front);
        p->front = p->rear;
    }
    return OK;
}//DestroyQueue

Status EnQueue(LinkQueue *p,QElemType *e)
{
    QNode *q;
    q = (QueuePtr)malloc(sizeof(QNode));
    if(!q) exit(OVERFLOW);
    q->data = *e;
    q->next = NULL;
    p->rear->next = q;
    p->rear = q;
    return OK;
}//EnQueue

Status DeQueue(LinkQueue *p,QElemType *e)
{
    QNode *q;
    if(p->front == p->rear) return ERROR;
    q = p->front->next;
    *e = q->data;
    p->front->next = q->next;
    if(p->rear == q) p->rear = p->front;
    free(q);
    return OK;
}//DeQueue

Status QueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}//QueueEmpty

Status GetHead(LinkQueue Q,QElemType *e)
{
    if(QueueEmpty(Q))      return ERROR;
    *e = (Q.front->next)->data;
    return OK;
}//GetHead

int QueueLength(LinkQueue Q)
{
    QNode *q;
    int i = 0;

    q = Q.front->next;
    while(q)
    {
        q = q->next;
        i++;
    }
    return i;
}//QueueLength

Status ClearQueue(LinkQueue *p)
{
    QNode *q;
    if(p->front == p->rear)
        return OK;
    q = p->front->next;
    while(q)
    {
        p->rear = q;
        free(q);
        q = p->rear->next;
    }
    p->rear = p->front;
    return OK;
}//ClearQueue
/*main()
{
    int e=1;
    int p=1 ;
    int i;
    int k;
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q,&e);
    GetHead(Q,&i);
    k = QueueLength(Q);
    printf("%d",k);
    printf("%d",i);
    ClearQueue(&Q);
    DeQueue(&Q,&p);
    printf("%d",p);
    DestroyQueue(&Q);

}*/
