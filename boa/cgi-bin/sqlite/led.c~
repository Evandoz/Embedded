#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main() 
{
	int fd; 
   printf("Content-type: text/html\n\n"); 

	fd = open("/dev/leds", 0);
	if (fd < 0)
	{ 

   	perror("open device /dev/leds");  
      exit(1);
	}


	ioctl(fd, 1, 1);
	ioctl(fd, 2, 1);
	ioctl(fd, 3, 1);

	close(fd); 
printf("receive order");
fflush(stdout);
return 0;


}
