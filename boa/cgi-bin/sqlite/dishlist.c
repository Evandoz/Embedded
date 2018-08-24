#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include<string.h>


int main()
{
    char *name,*type;
    int price;
    int temp=0;
    char *sql="select * from menu";
    sqlite3_stmt *statement=NULL;
    int ret;
    int rc;
    sqlite3 *pdb = NULL ;
    

    printf("Content-Type:text/html;charset='utf-8'\n\n");
	 printf("<head><title>哈工大点菜</title></head>"); 
    printf("<body><h1 style='margin-left:250px'>查看菜谱</h1>");
	 printf("<br><br>");
 	 printf(" </table>");
                 
          	printf("<br><br>");
          	printf("<div>");
           
            printf("\<div style='height=200px'>\
			<table border='1' style='width: 300px;float:left;margin-left:200px;margin-top:-80px;border-spacing:15px;' >\ ");
              
            rc = sqlite3_open("menu.db" , &pdb);
            if(rc)
            			{
                printf("<tr><td><label>数据库服务失败</label></td></tr>");
                
                sqlite3_close(pdb) ;
                
            }else{
                ret=sqlite3_prepare(pdb,sql,-1,&statement,NULL);
                if(ret != SQLITE_OK){
                    printf("<tr><td><label>prepare error </label></td></tr>");
                }else{

                    while (sqlite3_step(statement) == SQLITE_ROW) {
                        temp++;
                        name = (char *)sqlite3_column_text(statement, 1);
								type = (char *)sqlite3_column_text(statement, 2);
                        price = sqlite3_column_int(statement, 3);
                        
                        if( temp%3==1 ){
                            printf("<tr >");
                            printf("       <td><label>");
                            printf(name);    
                            printf("-</label><span>");
                            printf(type);    
                            printf("-</label><span>");
									 printf("￥</label><span>");
                            printf("%d",price);  
									printf(" </span><span></span></td>");

                        }else{
                            printf("<tr >");
                            printf("       <td><label>");
                            printf(name);    
                            printf("-</label><span>");
                            printf(type);    
                            printf("-</label><span>");
									 printf("￥</label><span>");
                            printf("%d",price);  
									printf(" </span><span></span></td>");   
                            if( temp%3==0 ) printf("</tr>");
								}
}
                    printf("</tr>");
                        
                    sqlite3_finalize(statement);
               				 }
                
                
                sqlite3_close(pdb) ;
           			}

printf("</body>");
return 0;
}







