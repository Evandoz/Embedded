#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

char *join(char *a, char *b) {  
    char *c = (char *) malloc(strlen(a) + strlen(b) + 1); //�ֲ���������malloc�����ڴ�  
	 char *tempc = c; //���׵�ַ������  
    if (c == NULL) exit (1);  
    
    while (*a != '\0') {  
        *c++ = *a++;  
    }  
    while ((*c++ = *b++) != '\0') {  
        ;  
    }  
    //ע�⣬��ʱָ��c�Ѿ�ָ��ƴ��֮����ַ����Ľ�β'\0' !  
    return tempc;//����ֵ�Ǿֲ�malloc�����ָ����������ں������ý�����free֮  
}  

int main(void)
{
    char *data= getenv("QUERY_STRING");
    
    
    char *sql;
    int rc;
	
    sqlite3_stmt *statement=NULL;
	 sqlite3 *pdb = NULL ;
    int ret ;
    
    int price=0;//�۸�
   
    char cprice[50];
    char cname[50];
	
    memset(cname,0,50);
    printf("Content-Type:text/html;charset=utf-8\n\n");  
    printf("<TITLE>��Ӳ�Ʒ</TITLE> ");
   
	
    
    if(data == NULL){
        printf("<P>��������û�б�����������ݴ���������");
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
            printf("<tr><td><label>���ݿ����ʧ��</label></td></tr>");
                //fprintf(stderr , "can't open database: %s\n",sqlite3_errmsg(pdb));
            sqlite3_close(pdb) ;
                
        }else{
            ret=sqlite3_prepare(pdb,sql,-1,&statement,NULL);
            if(ret != SQLITE_OK){
                printf("<tr><td><label>prepare error ret </label></td></tr>");
            }else{
                
                if (sqlite3_step(statement) == SQLITE_DONE) {
                       
                        printf("<H3>��ӳɹ�</H3> ");
                }else{
                    printf("<H3>���ʧ��</H3> ");
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
