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
	float a,b,f,m;
    int i,k,j;
	char c,theta;
	CharStack OPTR,p;
	IntStack OPND;

	CharInitStack(&OPTR);
	CharInitStack(&p);
	IntInitStack(&OPND);
	CharPush(&OPTR,'#');
	CharPush(&p,'#');
    k = 1;
	printf("输入表达式(以‘#’结束)：\n");
	c = getchar();
    if(c == '-')
    {
        k = -1;
        c = getchar();
    }
	while(c != '\n')
	{
        if(c == ' '|| c == '=')
            c = getchar();
		else if(op(c))
		{
            if(c == '('|| c == ')')
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
	                       IntDestory(&OPND);
	                       CharDestory(&OPTR);
	                       CharDestory(&p);
                           return 0;
                       }
                       else if(j)
                            CharPop(&p);
                   }
            }
			switch(Precede(CharGetTop(OPTR),c))
			{
				case '<':
                    j = 1;
				    CharPush(&OPTR,c);
				    c = getchar();
                    if(c == '-')	
                    {
                        k = -1;
                        c = getchar();
               }
                    break;
				case '=':
                    j = 1;
					CharPop(&OPTR);
					c = getchar();
					break;
				case '>':
                    j = 0;
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
		else if(isnum(c)||c == '.')
		{
			f = 0;
			i = 0;
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
			for(i;i>0;i--)
				f = f / 10;
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
    CharPop(&p);
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
	printf("%f\n",m);
	IntDestory(&OPND);
	CharDestory(&OPTR);
	CharDestory(&p);
}
