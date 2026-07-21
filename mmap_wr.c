#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
	int fd;
	int size;
	fd=open("MMAPFILE",O_RDWR);
	size=lseek(fd,0,SEEK_END);
	char*ptr=NULL;
	if((ptr=mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0))==MAP_FAILED)
	{
		perror("mmap fail");
		exit(0);
	}
	close(fd);
	int num=0;
	while(1)
	{
		sprintf(ptr,"write:%d",num++);
		printf("wrire process:%s\n",ptr);
		sleep(1);
	}
	munmap(ptr,size);
	return 0;
}

