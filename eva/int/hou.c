/*************************************************************************
	> File Name: hou.c
	> Author: li
	> Mail: xiaoguang.li.0807@gmail.com 
	> Created Time: 2013年10月18日 星期五 20时10分31秒
 ************************************************************************/

#include<stdio.h>
#include"charstack.c"
#include"intstack.c"
#include"hanshu.c"


main()
{
	CharStack OP;
	IntStack  NU;
	char c,a;
	int f,nu,nu1,nu2,nu3;
	
	
	CharInitStack(&OP);
	IntInitStack(&NU);
	CharPush(&OP,'#');
	c = getchar();
	while(c != '#'||CharGetTop(OP) != '#')
	{
		if(op(c))
		{
			switch(Precede(CharGetTop(OP),c))
			{
				case'<':
					CharPush(&OP,c);
					c = getchar();
					break;
				case'=':
					a = CharPop(&OP);
					c = getchar();
					break;
				case'>':
					a = CharPop(&OP);
					printf("%c ",a);
					nu2 = IntPop(&NU);
					if(a == '/'&& nu2 == 0)
					{
						printf("错误：出现0为除数");
						return;
					}
					nu1 = IntPop(&NU);
					nu3 = Operate(nu1,a,nu2);
					IntPush(&NU,nu3);
					break;
			}
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
			IntPush(&NU,f);
			printf("%d ",f);
		}
		else
			c = getchar();
	}//while
	nu = IntPop(&NU);
	printf(" %d\n",nu);
}



