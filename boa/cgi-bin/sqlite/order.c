#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include<string.h>


int main()
{
    char *name;
    int Num;
	int DeskNo;
    int temp=0;
    sqlite3_stmt *statement2=NULL;
    int ret2;
    char *sql2="select Name,Num,DeskNo from menu,myorder where menu.ID=myorder.ID order by myorder.DeskNo desc";
    int rc;
    sqlite3 *pdb = NULL ;

    printf("Content-Type:text/html;charset='utf-8'\n\n");
    printf("<head><title>哈工大点菜</title></head>"); 
    printf("<body><h1 style='margin-left:250px'>订单管理</h1>");
    
      printf("<br><br>");
        printf("<div>");
       
        
        
          printf("<table border='1' style='width: 600px;border-spacing:15px;' >");
          
            rc = sqlite3_open("menu.db" , &pdb);
            if(rc)
            {
                printf("<tr><td><label>数据库失败</label></td></tr>");
                sqlite3_close(pdb) ;
                
            }else{
                ret2=sqlite3_prepare(pdb,sql2,-1,&statement2,NULL);
                if(ret2 != SQLITE_OK){
                    printf("<tr><td><label>prepare error ret </label></td></tr>");
                }else{
                    if (sqlite3_step(statement2) == SQLITE_ROW) {
                            
                            name = (char *)sqlite3_column_text(statement2, 0);
                            Num = sqlite3_column_int(statement2, 1);
									DeskNo = sqlite3_column_int(statement2, 2);

									printf("<tr >");
                            printf("<td><label>");
									printf("桌号：</label><span>");
                            printf("%d",DeskNo);   
   									printf(" </span><span>桌</span></td>");
                            printf("</tr>");


                            printf("<tr >");
                            printf("<td><label>");
                            printf(name);      
                            printf("－</label><span>");
									 
                            printf("%d",Num);
									printf(" </span><span>份</span></td>");
                            printf("</tr>");
                            
                    
                    }
                    while(sqlite3_step(statement2) == SQLITE_ROW) {
                            int flag;
                            flag=sqlite3_column_int(statement2, 2);
                            
                            if( flag != DeskNo )break;
                            name = (char *)sqlite3_column_text(statement2, 0);
                            Num = sqlite3_column_int(statement2, 1);
							
                            printf("<tr >");
                            printf("<td><label>");
                            printf(name);      
                            printf("－</label><span>");
									 
                            printf("%d",Num);
									printf(" </span><span>份</span></td>");
                            printf("</tr>");
                    
                    }
                    sqlite3_finalize(statement2);
                    
                }
                sqlite3_close(pdb) ;
            }


            printf("\
						<a href='http://192.168.1.193/cgi-bin/sqlite/led.cgi'>确认订单</a>\
				 ");
printf("－－</label><span>");
printf("\
						<a href='http://192.168.1.193/cgi-bin/sqlite/led1.cgi'>确认完成</a>\
				 ");

printf("</body>");




return 0;
}
