/*************************************************************************
	> File Name: hou1.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Sat 26 Oct 2013 09:45:36 AM CST
 ************************************************************************/
#include<stdio.h>
#include"intstack.c"
#include"hanshu.c"

main()
{
    IntStack OPTR;
    int a,b,c,d,f,e,k;
    char m;
    IntInitStack(&OPTR);
    
    printf("后缀式为：");
    k = 1;
    c = getchar();
    while(c != '#')
    {
        if(c == ' ')
            c = getchar();
        else if(c == '-')
        {
            m = getchar();
            if(m == ' ')
            {
                printf("%c ",c);
                b = IntPop(&OPTR);
                a = IntPop(&OPTR);
                d = Operate(a,c,b);
                IntPush(&OPTR,d);
                c = getchar();
            }
            else
            {
                k = -1;    
                c = m;
            }

        }
        else if(c == '+'||c == '*'||c == '/')
        {
            printf("%c ",c);
            b = IntPop(&OPTR);
            a = IntPop(&OPTR);
            d = Operate(a,c,b);
            IntPush(&OPTR,d);
            c = getchar();
        }
        else if(isnum(c))
        {            
            f = 0;
            while(isnum(c))
            {
                c = c - '0';
                f = f * 10 + c;
                c = getchar();
            }
            f = k * f;
            IntPush(&OPTR,f);
            printf("%d ",f);
            k = 1;
        }
    }
    e = IntPop(&OPTR);
    printf("\n表达式值为：%d\n",e);
    IntDestory(&OPTR);
}
