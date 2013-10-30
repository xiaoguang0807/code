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
	float f,m ,k,i;
	char c,theta;
	CharStack OPTR;

	CharInitStack(&OPTR);
	CharPush(&OPTR,'#');
    k = 1;
	c = getchar();
    if(c == '-')
    {
        k = -1;
        c = getchar();
    }
	while(c != '#'||CharGetTop(OPTR) != '#')
	{
        if(op(c))
		{
			switch(Precede(CharGetTop(OPTR),c))
			{
				case '<':
				CharPush(&OPTR,c);
				c = getchar();
                if(c == '-')
                {
                    k = -1;
                    c = getchar();
                }
				break;

				case '=':
					CharPop(&OPTR);
					c = getchar();
					break;
				case '>':
					theta = CharPop(&OPTR);
                    printf("%c ",theta);
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
            printf("%f ",f);
            k = 1;
        }
		else
			c = getchar();
	}
	printf("%c\n",'#');
	CharDestory(&OPTR);

}




