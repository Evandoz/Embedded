#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include<string.h>


int main()
{
    
    char *name;//菜名
    int price;//价格
    int orderid;//订单编号
   
    int temp=0;
    
    char *sql="select * from Dish";
    sqlite3_stmt *statement=NULL;
    sqlite3_stmt *statement2=NULL;
    int ret ,ret2;
    char *sql2="select Orderlist.Id,Orderlist.Ordernum,Dish.Name,Dish.Price from Orderlist,Dish where Orderlist.Dishid=Dish.Id order by Orderlist.Id desc";
    

    int rc;
    sqlite3 *pdb = NULL ;
    
    
    
    
    printf("Content-Type:text/html;charset='gb2312'\n\n");
    printf("<head><title>点菜系统</title></head>"); 
    
    printf("<body><h1 style='margin-left:600px'>点菜系统管理页面</h1>");
    
      printf("<br><br>");
        printf("<div>");
        printf("<div style='width: 200px;margin-left: 300px;float: left;margin-top: 10px'><h1>查看订单</h1></div>");
        
        
        
        
        
          printf("<table border='1' style='width: 600px;border-spacing:15px;' >");
          
            rc = sqlite3_open("testdb.db" , &pdb);
            if(rc)
            {
                printf("<tr><td><label>数据库服务失败</label></td></tr>");
                //fprintf(stderr , "can't open database: %s\n",sqlite3_errmsg(pdb));
                sqlite3_close(pdb) ;
                
            }else{
                ret2=sqlite3_prepare(pdb,sql2,-1,&statement2,NULL);
                if(ret2 != SQLITE_OK){
                    printf("<tr><td><label>prepare error ret </label></td></tr>");
                }else{
                    //printf("<tr><td><label>取到记录了吗？ </label></td></tr>");
                    if (sqlite3_step(statement2) == SQLITE_ROW) {
                            //printf("<tr><td><label>取到记录了 </label></td></tr>");
                            orderid=sqlite3_column_int(statement2, 1);
                            name = (char *)sqlite3_column_text(statement2, 2);
                            price = sqlite3_column_int(statement2, 3);
                            //name = (char *)sqlite3_column_text(statement, 1);
                            //price = sqlite3_column_int(statement, 2);
                            printf("<tr >");
                            printf("<td><label>");
                            printf(name);       //鱼香肉丝
                            printf(":</label><span>");
                            printf("%d",price);
                            
                            printf(" </span><span>元</span></td>");
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
                            printf(name);       //鱼香肉丝
                            printf(":</label><span>");
                            printf("%d",price);     //  20
                            printf(" </span><span>元</span></td>");
                            printf("</tr>");
                    
                    }
                    sqlite3_finalize(statement2);
                    
                }
                sqlite3_close(pdb) ;
            }
          
          
                 
          printf(" </table>");
                 
          printf("<br><br>");
          printf("<div>");
            printf("<div style='width: 200px;margin-left: 300px'><h1>管理菜单</h1></div>");
            printf("\
            <div style='height=200px'>\
              <table border='1' style='width: 600px;float:left;margin-left:500px;margin-top:-80px;border-spacing:15px;' >\
              ");
              
            rc = sqlite3_open("testdb.db" , &pdb);
            if(rc)
            {
                printf("<tr><td><label>数据库服务失败</label></td></tr>");
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
                            printf(name);       //鱼香肉丝
                            printf(":</label><span>");
                            printf("%d",price);     //  20
                            printf(" </span><span>元</span></td>");

                        }else{
                            printf("       <td><label>");
                            printf(name);       //鱼香肉丝
                            printf(":</label><span>");
                            printf("%d",price);     //  20
                            printf(" </span><span>元</span></td>");
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
              <h1>添加菜品</h1>\
            </div>\
            <div style='width: 400px;margin-left: 500px;margin-top:-50px;float:left;'>\
				<form action='/cgi-bin/search.cgi'>\
					<li style='list-style-type: none;margin-left: 100px'>\
					<label >菜名：</label>\
					<input type='text' name='m'>\
					</li>\
					<li style='list-style-type: none;margin-left: 100px'>\
					<label>价格：</label>\
					<input type='text' name='n'>\
					</li>\
					<li style='list-style-type: none;margin-left: 180px'>\
					<button>提交</button>\
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
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;菜名：<input type="text" name="name" class="input3" />
				</div>
					
				<div class="bbD">
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;类型：<select name="type" class="input3">
					        <option value="qwer">特菜</option></select> 
				</div>
				<div class="bbD">
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;价格：<input class="input3" name="price" type="text" />
				</div>
