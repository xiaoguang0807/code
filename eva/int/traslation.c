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
    int f,k ;
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
                if(c == '-')   //判断输入数是否为负数
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
        else if(isnum(c))
        {
            f = 0;
            while(isnum(c))
            {
                c = c - '0';
                f = f * 10 + c;
                c = getchar();
            }
            f = k*f;
            printf("%d ",f);
            k = 1;
        }
        else
            c = getchar();
    }
    printf("%c\n",'#');
    CharDestory(&OPTR);
}




