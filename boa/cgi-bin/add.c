#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"


int main(void)
{
    char *data= getenv("QUERY_STRING");
    char *sql;
    int rc;
	
    sqlite3_stmt *statement=NULL;
	 sqlite3 *pdb = NULL ;
    int ret ;
    
    int price=0;//价格
   
    char cprice[50];
    char cname[50];
	 char type[50];
	
    memset(cname,0,50);
	 memset(type,0,50);
    if(data == NULL){
        printf("<P>错误！数据没有被输入或者数据传输有问题");
    }
    printf(data);
    sscanf(data,"name=%[^&]&type=%[^&]&price=%d",cname,type,price);
            //printf("<p>");
            //printf(data);
       
        
    sql= "insert into dishlist(name,type,price)values('";

    sql=join(sql,cname);

    sql=join(sql,"',");

sql=join(sql,"',");
sql=join(sql,type);


    sql=join(sql,"',");
    sprintf(cprice,"%d",price);
    
    sql=join(sql,cprice);
    sql=join(sql,")");
    
    
    
    
   rc = sqlite3_open("dish.db" , &pdb);
        if(rc){
            printf("<tr><td><label>数据库服务失败</label></td></tr>");
                //fprintf(stderr , "can't open database: %s\n",sqlite3_errmsg(pdb));
            sqlite3_close(pdb) ;
                
        }else{
            ret=sqlite3_prepare(pdb,sql,-1,&statement,NULL);
            if(ret != SQLITE_OK){
                printf("<tr><td><label>prepare error ret </label></td></tr>");
            }else{
                
                if (sqlite3_step(statement) == SQLITE_DONE) {
                       
                        printf("<H3>添加成功</H3> ");
                }else{
                    printf("<H3>添加失败</H3> ");
                }
                
                        
                sqlite3_finalize(statement);
            
            }
                
                
            sqlite3_close(pdb) ;
        }
   
    
    
    
    
    
    
    
    //intf("<P>wait a moment......and it will step into index page");
   
   //rintf("<meta http-equiv='refresh' content='5;url=http://127.0.0.1/cgi-bin/index.cgi'>");
    
    fflush(stdout);
    return 0;
}
