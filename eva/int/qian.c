/*************************************************************************
  > File Name: qian.c
  > Author: li
  > Mail: xiaoguang.li.0807@gmail.com
  > Created Time: 2013年10月10日 星期四 15时35分39秒
 ************************************************************************/

#include<stdio.h>
#include "intstack.c"
#include "charstack.c"
#include "hanshu.c"


main()
{
    int a,b,i;
    int f,m,k ;
    char c,theta;
    CharStack OPTR;
    CharStack p;
    IntStack OPND;

    CharInitStack(&OPTR);
    IntInitStack(&OPND);
    CharInitStack(&p);
    CharPush(&OPTR,'#');
    CharPush(&p,'#');
    k = 1;
    printf("请输入表达式（以‘#’结束）：\n");
    c = getchar();
    if(c == '-')
    {
        k = -1;
        c = getchar();
    }
    while(c != '\n'/*||CharGetTop(OPTR) != '#'*/)
    {
      
        if(c == ' '||c == '=')
            c = getchar();
       else if(op(c))
        {
            if(c == '('||c ==')')
            {
                if(c == '(')
                   {
                       CharPush(&p,c);
                   }
                 else
                   {
                        if(CharStackEmpty(p))
                        {
                            printf("括号不匹配");
                            IntDestory(&OPND);    //在函数返回前先把所有的栈销毁
                            CharDestory(&OPTR);
                            CharDestory(&p);
                            return 0;
                        }
                        else if(i)//判断当前括号是否执行完毕 
                            CharPop(&p);
                   }
            }
            switch(Precede(CharGetTop(OPTR),c))
            {
            case '<':
                i = 1;
                CharPush(&OPTR,c);
                c = getchar();
                if(c == '-')
                {
                    k = -1;
                    c = getchar();
                }
                break;

            case '=':
                i = 1;
                CharPop(&OPTR);
                c = getchar();
                break;
            case '>':
                i = 0;
                theta = CharPop(&OPTR);
               if(IntEmpty(OPND))
                {
                    printf("请输入正确的表达式");
                    IntDestory(&OPND);
                    CharDestory(&OPTR);
                    CharDestory(&p);
                    return 0;
                }
                b = IntPop(&OPND);
                if(b == 0 && theta == '/')
                {
                    printf("error:divde is zero");
                    IntDestory(&OPND);
                    CharDestory(&OPTR);
                    CharDestory(&p);
                    return 0;
                }
               if(IntEmpty(OPND))
                {
                    printf("请输入正确的表达式");
                    IntDestory(&OPND);
                    CharDestory(&OPTR);
                    CharDestory(&p);
                    return 0;
                }
                a = IntPop(&OPND);
                IntPush(&OPND,Operate(a,theta,b));
                break;
            }//switch
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
            IntPush(&OPND,f);
            k = 1;
        }
        else
        {
            printf("请输入正确的表达式");
            IntDestory(&OPND);
             CharDestory(&OPTR);
            CharDestory(&p);
            return 0;
        }  

    }
    CharPop(&p);//将p栈中的‘#’弹出
    if(!CharStackEmpty(p))
    {
        printf("括号不匹配");
        IntDestory(&OPND);
        CharDestory(&OPTR);
        CharDestory(&p);
        return 0;
    }
    if(!CharStackEmpty(OPTR))
    {
        printf("请输入正确的表达式");
        IntDestory(&OPND);
        CharDestory(&OPTR);
        CharDestory(&p);
        return 0;
    }
    m = IntPop(&OPND);
    if(!IntEmpty(OPND))
    {
        printf("请输入正确的表达式");
        IntDestory(&OPND);
        CharDestory(&OPTR);
        CharDestory(&p);
        return 0;
    }
    printf("结果为：%d\n",m);
    IntDestory(&OPND);
    CharDestory(&OPTR);
    CharDestory(&p);
}




