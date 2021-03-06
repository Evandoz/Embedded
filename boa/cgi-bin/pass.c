//pass.c 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
char* getcgidata(FILE* fp, char* requestmethod);
int main() 
{
	char *input;
	char *req_method;
   char led[10];
   int i = 0; 
   int j = 0; 
   int fd; 

   printf("Content-type: text/plain; charset=iso-8859-1\n\n\n\n\n");
   printf("Content-type: text/html\n\n"); 

	fd = open("/dev/leds", 0); 
   if (fd < 0)
	{ 
   	perror("open device /dev/leds");  
      exit(1);
	} 
 
   ioctl(fd, 1, 0); 
   req_method = getenv("REQUEST_METHOD"); 
   input = getcgidata(stdin, req_method);//根据input中的字符串信息确定led灯的点亮关闭 
//以下补充完善代码
	printf("Your POST Message is \"%s\". \n\n", input);         
   printf("The following is query reuslt:\n");
   j=0; 
   for ( i = 0; i < (int)strlen(input); i++ )//对接受到的字符串分析
        { 
   	if ( input[i] == 'V' )         //如果字符为“V”则取其后面的一位
               { 
      	led[j]=input[i+1]; 
         j++;
               }
         }
  	for(j=0;j<3;j++)                        //判断灯的状态
	{  
   	if ( led[j]=='1')
		{
			ioctl(fd,j+1,1);    //若接收到为1，开相应的灯，否则熄灭 
			printf("\tNumber %d led is on.\n",j+1);
		}
      else
		{ 
         ioctl(fd,j+1,0); 
			printf("\tNumber %d led is off.\n",j+1);
		}
 	} 
   close(fd);  
   return 0;
 } 
char* getcgidata(FILE* fp, char* requestmethod) 
{ 
	char* input;
   int len;
   int size = 1024;
   int i = 0; 
   if (!strcmp(requestmethod, "GET"))
        { 
   	input = getenv("QUERY_STRING");
      return input;
        } 
   else if (!strcmp(requestmethod, "POST"))
        { 
   	len = atoi(getenv("CONTENT_LENGTH")); 
      input = (char*)malloc(sizeof(char)*(size + 1));
      if (len == 0)
               { 
      	input[0] = '\0';
         return input;
               }
		while(1)
 		{ 
   		input[i] = (char)fgetc(fp);
      	if (i == size)
                	{ 
      		input[i+1] = '\0';
         	return input;
                 	}
      	--len; 
      	if (feof(fp) || (!(len)))
                	{ 
      		i++; 
         	input[i] = '\0';
         	return input;
                 	} 
      	i++;
        	}
        } 
   return NULL; 
}
