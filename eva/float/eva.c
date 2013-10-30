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
    float a,b,d,f,e,k;
    char m,c;
    int i;
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
        else if(isnum(c)||c == '.')
        {       
            i = 0;
            f = 0;
            while(isnum(c))
            {
                c = c - '0';
                f = f * 10 + c;
                c = getchar();
            }
            if(c == '.')
            {
                c = getchar();
                while(isnum(c))
                {
                    c = c - '0';
                    f = f * 10 + c;
                    c = getchar();
                    i++;
                }
            }
            for(;0< i;i--)
                f = f / 10;
            f = k * f;
            IntPush(&OPTR,f);
            printf("%f ",f);
            k = 1;
        }
    }
    e = IntPop(&OPTR);
    printf("\n表达式值为：%f\n",e);
    IntDestory(&OPTR);
}
