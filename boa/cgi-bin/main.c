#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

char *join(char *a, char *b) {  
    char *c = (char *) malloc(strlen(a) + strlen(b) + 1); //局部变量，用malloc申请内存  
	 char *tempc = c; //把首地址存下来  
    if (c == NULL) exit (1);  
    
    while (*a != '\0') {  
        *c++ = *a++;  
    }  
    while ((*c++ = *b++) != '\0') {  
        ;  
    }  
    //注意，此时指针c已经指向拼接之后的字符串的结尾'\0' !  
    return tempc;//返回值是局部malloc申请的指针变量，需在函数调用结束后free之  
}  

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
	
    memset(cname,0,50);
    printf("Content-Type:text/html;charset=utf-8\n\n");  
    printf("<TITLE>添加菜品</TITLE> ");
   
	
    
    if(data == NULL){
        printf("<P>错误！数据没有被输入或者数据传输有问题");
    }
    printf("<P>");
    printf(data);
    sscanf(data,"m=%[^&]&n=%d",cname,&price);  
            //printf("<p>");
            //printf(data);
            printf("<p>");
            printf("your order:");
            printf(cname);
            
        
            printf("<p>");
            printf("its price is:");
            printf("%dyuan",price);
       
        
    
    sql= "insert into Dish(Name,Price)values('";

    sql=join(sql,cname);

    sql=join(sql,"',");
    sprintf(cprice,"%d",price);
    
    sql=join(sql,cprice);
    sql=join(sql,")");
    
    
    
    
   rc = sqlite3_open("testdb.db" , &pdb);
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
   
    
    
    
    
    
    
    
    printf("<P>wait a moment......and it will step into index page");
   
    printf("<meta http-equiv='refresh' content='5;url=http://127.0.0.1/cgi-bin/index.cgi'>");
    
    fflush(stdout);
    return 0;
}
