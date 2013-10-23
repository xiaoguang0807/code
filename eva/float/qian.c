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
	float a,b,i,j;
	float f,m ;
	char c,theta;
	CharStack OPTR;
	IntStack OPND;

	CharInitStack(&OPTR);
	IntInitStack(&OPND);
	CharPush(&OPTR,'#');

	printf("输入表达式：\n");
	c = getchar();
	while(c != '#'||CharGetTop(OPTR) != '#')
	{
		if(op(c))
		{
			switch(Precede(CharGetTop(OPTR),c))
			{
				case '<':
				CharPush(&OPTR,c);
				c = getchar();
				break;

				case '=':
					CharPop(&OPTR);
					c = getchar();
					break;
				case '>':
					theta = CharPop(&OPTR);
					b = IntPop(&OPND);
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
			IntPush(&OPND,f);
		}
		else
			c = getchar();
	}
	m = IntGetTop(OPND);
	printf("%f\n",m);
//	IntDestory(&OPND);
//	CharDestory(&OPTR);

}




