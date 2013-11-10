/*************************************************************************
	> File Name: LinkList.c
	> Author: li
	> Mail: xiaoguang.li.0807@Gmail.com 
	> Created Time: Sun 10 Nov 2013 08:47:17 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"define.h"

typedef int ElemType; 


typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;


Status InitList(LinkList *p)
{
    LinkList L;
    L = *p = (LinkList )malloc(sizeof(LNode));
    if(!L)//??
       exit(OVERFLOW);
    L->next = NULL;
    return OK;
}//InitList

Status ClearList(LinkList *p)
{
    LNode *q;

    q = (*p)->next;
    while(q)
    {
        (*p)->next = q->next;
        free(q);
        q = (*p)->next;
    }
    return OK;
}
Status DestroyList(LinkList *p)
{
    ClearList(p);
    free(*p);
    p = NULL;
    return OK;
}//DestroyList

Status ListEmpty(LinkList L)
{
    if(!L->next)
        return OK;
    else
        return FALSE; 
}//ListEmpty

int  ListLength(LinkList L)
{
    LNode *q,*p;
    int i = 0;
    q = L->next;
    while(q)
    {
        i++;
        p = q;
        q = p->next;
    }
    return i;
}//ListLength

Status GetElem(LinkList L,int i,ElemType *e)
{
    int n = ListLength(L);
    LNode *q,*p;

    if(i<1||i>n+1)
        return ERROR;
    q = L->next;
    
    while(i>1)
    {
        p = q;
        q = p->next;
        i--;
    }
    *e = q->data;
    return OK;
}//GetElem

/*int LocateElem(LinkList L,ElemType e)
{
    
}*/

Status ListInsert(LinkList *p,int i,ElemType e)
{
    int n = ListLength(*p);
    if(i<1||i>n+1)
        return ERROR;
    LNode *q,*l;
    q = *p;
    while(i>1)
    {
        l = q;
        q = l->next;
        i--;
    }
    l = (LNode *)malloc(sizeof(LNode));
    l->data = e;
    l->next = q->next;
    q->next = l;
}//ListInsert

Status ListDelete(LinkList *p,int i,ElemType *e)
{
    int n = ListLength(*p);
    if(i<1||i>n+1)
        return ERROR;
    LNode *q,*l;
    q = *p;
    while(i > 1)
    {
        l = q;
        q = l->next;
        i--;
    }
    l = q->next;
    *e = l->data;
    q->next = l->next;
    free(l);
    return OK;

}//ListDelete

/*Status VisitList(LinkList L)
{
    LNode *p,*q;
    q = L->next;
    while(q)
    {
        printf();
    }
    
}*/

/*Status AddList(LinkList *p)
{
    LNode *q;
    q = (LNode *)malloc(sizeof(LNode));
    (*p)->next = q;
}*/

main()
{
    LinkList L;
    int e;
    InitList(&L);
    ListLength(L);
    ListInsert(&L,1,1);
    ListDelete(&L,1,&e);
    ListLength(L);
    ListEmpty(L);
    DestroyList(&L);

}

