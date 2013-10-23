/*************************************************************************
  > File Name: hanshu.c
  > Author: li
  > Mail: xiaoguang.li.0807@gmail.com 
  > Created Time: 2013年10月10日 星期四 15时35分39秒
 ************************************************************************/

#include<stdio.h>

int op(char c)   //判断c是否是操作符
{
	char v[]={'[',']','(',')','{','}','-','+','*','/','#'};
	int i;

	for(i=0;i<11;i++)
	{
		if(c == v[i])
			return 1;
	}	
	return 0;
}

char Precede(char a,char b) //操作符优先级的比较
{
	if(a == '+'||a == '-')
	{
		if(b=='+'||b == '-'||b == ')'||b=='#')
			return '>';
		else
			return '<';
	}
	else if(a == '*'||a == '/')
	{
		if(b=='+'||b == '-'||b == ')'||b =='*'||b=='/'||b=='#')
			return '>';
		else
			return '<';
	}
	else if(a == '(')
	{
		if(b == ')')
			return '=';
		else
			return '<';
	}
	else if(a == ')')
	{
		return '>';
	}
	else if(a == '#')
	{
		if(b == '#')
			return '=';
		else 
			return '<';
	}
	else
		return;
}


int Operate(int a,char c,int b) //进行运算
{
	if(c == '-')
		return a - b;
	else if(c == '+')
		return a + b;
	else if(c == '*')
		return a*b;
	else if(c == '/')
		return a/b;
}

int isnum(char c)  //判断c是否为数字
{
	if(c >= '0' && c <= '9')
		return 1;
	else 
		return 0;
}



