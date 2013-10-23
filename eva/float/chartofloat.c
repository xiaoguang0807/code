/*************************************************************************
	> File Name: chartofloat.c
	> Author: li
	> Mail: xiaoguang.li.0807@gmail.com 
	> Created Time: 2013年10月19日 星期六 10时17分30秒
 ************************************************************************/

#include<stdio.h>

int isnum(char c)
{
	if(c >= '0' && c <= '9' )
		return 1;
	else
		return 0;
}
main()
{
	char c;
	float f;
	int i = 0;

	c = getchar();
	while(isnum(c)||c == '.')
	{
		while(isnum(c))
		{
			c = c - '0';
			f = f * 10 + c;
			c = getchar();
		}
		if(c = '.')
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
	}

		for(i;i>0;i--)
			f  = f /10;
		printf("%f",f);
}
