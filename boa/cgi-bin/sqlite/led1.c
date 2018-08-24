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

 
	ioctl(fd, 1, 0);
	ioctl(fd, 2, 0);
	ioctl(fd, 3, 0);

	close(fd); 
printf("order finished");

fflush(stdout);
return 0;


}
