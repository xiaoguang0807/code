/*************************************************************************
	> File Name: inser.c
	> Author: li
	> Mail: xiaoguang.li.0807@Gmail.com 
	> Created Time: Tue 12 Nov 2013 09:07:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"/usr/include/mysql/mysql.h"

main()
{ 
    MYSQL my_connection;
    int res;
    mysql_init(&my_connection);
    if(mysql_real_connect(&my_connection,"localhost","li","123456","one",0,NULL,CLIENT_FOUND_ROWS))
    {
        printf("connection success");
        res = mysql_query(&my_connection,"insert into stu values('4','abc') ");
        if(!res)
        {
            printf("inserted%lu rowsn",(unsigned long)mysql_affected_rows(&my_connection));
        }
        else
        {
            fprintf(stderr,"insert error%d:%sn",mysql_errno(&my_connection),mysql_error(&my_connection));
        }
        mysql_close(&my_connection);
    }
    else
    {
        fprintf(stderr,"connection failedn");
        if(mysql_errno(&my_connection))
        {
            fprintf(stderr,"connection error %d%sn",mysql_errno(&my_connection),mysql_error(&my_connection));
      
        }
    }
    return EXIT_SUCCESS;

}
