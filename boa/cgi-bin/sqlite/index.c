#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include<string.h>


int main()
{
    
    char *name;//����
    int price;//�۸�
    int orderid;//�������
   
    int temp=0;
    
    char *sql="select * from Dish";
    sqlite3_stmt *statement=NULL;
    sqlite3_stmt *statement2=NULL;
    int ret ,ret2;
    char *sql2="select Orderlist.Id,Orderlist.Ordernum,Dish.Name,Dish.Price from Orderlist,Dish where Orderlist.Dishid=Dish.Id order by Orderlist.Id desc";
    

    int rc;
    sqlite3 *pdb = NULL ;
    
    
    
    
    printf("Content-Type:text/html;charset='gb2312'\n\n");
    printf("<head><title>���ϵͳ</title></head>"); 
    
    printf("<body><h1 style='margin-left:600px'>���ϵͳ����ҳ��</h1>");
    
      printf("<br><br>");
        printf("<div>");
        printf("<div style='width: 200px;margin-left: 300px;float: left;margin-top: 10px'><h1>�鿴����</h1></div>");
        
        
        
        
        
          printf("<table border='1' style='width: 600px;border-spacing:15px;' >");
          
            rc = sqlite3_open("testdb.db" , &pdb);
            if(rc)
            {
                printf("<tr><td><label>���ݿ����ʧ��</label></td></tr>");
                //fprintf(stderr , "can't open database: %s\n",sqlite3_errmsg(pdb));
                sqlite3_close(pdb) ;
                
            }else{
                ret2=sqlite3_prepare(pdb,sql2,-1,&statement2,NULL);
                if(ret2 != SQLITE_OK){
                    printf("<tr><td><label>prepare error ret </label></td></tr>");
                }else{
                    //printf("<tr><td><label>ȡ����¼���� </label></td></tr>");
                    if (sqlite3_step(statement2) == SQLITE_ROW) {
                            //printf("<tr><td><label>ȡ����¼�� </label></td></tr>");
                            orderid=sqlite3_column_int(statement2, 1);
                            name = (char *)sqlite3_column_text(statement2, 2);
                            price = sqlite3_column_int(statement2, 3);
                            //name = (char *)sqlite3_column_text(statement, 1);
                            //price = sqlite3_column_int(statement, 2);
                            printf("<tr >");
                            printf("<td><label>");
                            printf(name);       //������˿
                            printf(":</label><span>");
                            printf("%d",price);
                            
                            printf(" </span><span>Ԫ</span></td>");
                            printf("</tr>");
                            
                    
                    }
                    while(sqlite3_step(statement2) == SQLITE_ROW) {
                            int flag;
                            flag=sqlite3_column_int(statement2, 1);
                            
                            if( flag != orderid )break;
                            name = (char *)sqlite3_column_text(statement2, 2);
                            price = sqlite3_column_int(statement2, 3);
                            printf("<tr >");
                            printf("       <td><label>");
                            printf(name);       //������˿
                            printf(":</label><span>");
                            printf("%d",price);     //  20
                            printf(" </span><span>Ԫ</span></td>");
                            printf("</tr>");
                    
                    }
                    sqlite3_finalize(statement2);
                    
                }
                sqlite3_close(pdb) ;
            }
          
          
                 
          printf(" </table>");
                 
          printf("<br><br>");
          printf("<div>");
            printf("<div style='width: 200px;margin-left: 300px'><h1>����˵�</h1></div>");
            printf("\
            <div style='height=200px'>\
              <table border='1' style='width: 600px;float:left;margin-left:500px;margin-top:-80px;border-spacing:15px;' >\
              ");
              
            rc = sqlite3_open("testdb.db" , &pdb);
            if(rc)
            {
                printf("<tr><td><label>���ݿ����ʧ��</label></td></tr>");
                //fprintf(stderr , "can't open database: %s\n",sqlite3_errmsg(pdb));
                sqlite3_close(pdb) ;
                
            }else{
                ret=sqlite3_prepare(pdb,sql,-1,&statement,NULL);
                if(ret != SQLITE_OK){
                    printf("<tr><td><label>prepare error ret </label></td></tr>");
                }else{
                    //printf("<tr >");
                    while (sqlite3_step(statement) == SQLITE_ROW) {
                        temp++;
                        name = (char *)sqlite3_column_text(statement, 1);
                        price = sqlite3_column_int(statement, 2);
                        
                        if( temp%3==1 ){
                            printf("<tr >");
                            printf("       <td><label>");
                            printf(name);       //������˿
                            printf(":</label><span>");
                            printf("%d",price);     //  20
                            printf(" </span><span>Ԫ</span></td>");

                        }else{
                            printf("       <td><label>");
                            printf(name);       //������˿
                            printf(":</label><span>");
                            printf("%d",price);     //  20
                            printf(" </span><span>Ԫ</span></td>");
                            if( temp%3==0 ) printf("</tr>");
                        
                        }
                    }
                    printf("</tr>");
                        
                    sqlite3_finalize(statement);
                }
                
                
                sqlite3_close(pdb) ;
            }
                
                printf("\
              </table>\
            </div>");
            printf("\
          </div>\
          <br>\
          <div>\
            <div style='width: 200px;margin-left: 300px'>\
              <h1>��Ӳ�Ʒ</h1>\
            </div>\
            <div style='width: 400px;margin-left: 500px;margin-top:-50px;float:left;'>\
				<form action='/cgi-bin/search.cgi'>\
					<li style='list-style-type: none;margin-left: 100px'>\
					<label >������</label>\
					<input type='text' name='m'>\
					</li>\
					<li style='list-style-type: none;margin-left: 100px'>\
					<label>�۸�</label>\
					<input type='text' name='n'>\
					</li>\
					<li style='list-style-type: none;margin-left: 180px'>\
					<button>�ύ</button>\
					</li>\
				</form>\
            </div>\
          </div>\
        </div>\
            \
</body>");
    
    return 0;
}


<div class="bbD">
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;������<input type="text" name="name" class="input3" />
				</div>
					
				<div class="bbD">
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;���ͣ�<select name="type" class="input3">
					        <option value="qwer">�ز�</option></select> 
				</div>
				<div class="bbD">
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;�۸�<input class="input3" name="price" type="text" />
				</div>
