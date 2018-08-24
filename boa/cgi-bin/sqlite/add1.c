#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
int main()
{
    sqlite3 *db;
    int nrow = 0, ncolumn = 0;
    char *zErrMsg = 0;
    char sql[500];
    int rc = 0;
    char *data=NULL;
    char name[20],type[20];
	 int price;
	  printf("Content-type: text/plain; charset=iso-8859-1\n\n\n\n\n");



    rc = sqlite3_open("dish.db", &db);//打开数据库
    if (rc)
    {
        printf("open db failed!\n\n");
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    //建立dishlist菜谱表
    sprintf(sql,
        "create table dishlist(ID integer, name varchar(20), type varchar(20), price integer)");
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL1 error: %s\n", zErrMsg);
        return 1;
    }


    //获取页面文本输入框内容
    data=getenv("QUERY_STRING");
printf("<p>");
	printf(data);
		
    if(data==NULL)
        printf("<p>错误：数据没有被输入或数据传输发生错误</p>");
    else
    {
		  
        sscanf(data,"name=%[^&]&type=%[^&]&price=%d",name,type,price);
printf("<p>");
printf(name);
printf(type);
printf(price);

    }


    //添加菜品，insert数据库
    sprintf(sql,"insert into dishlist(name,type,price) values('%s','%s',%d)", name,type,price);
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL1 error: %s\n", zErrMsg);
        return 1;
    }

    sqlite3_close(db);//关闭数据库

    return 0;
}


static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i = 0;

	printf("Content-type: text/html\n\n");
	for (i=0; i<argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}
