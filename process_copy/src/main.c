#include"process_copy.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[])
{
	int pronum;
	if(argc<=3)
	{
		pronum=5;
	}
	else
	{
		pronum=atoi(argv[3]);
	}
	int ret=check_pram(argc,argv[1],pronum);
	if(ret!=0)
	{
		printf("argc check fail\n");
		return -1;
	}
	int blocksize=process_cur(argv[1],pronum);
	int ret2=process_create(argv[1],argv[2],pronum,blocksize);
	if(ret2!=0)
	{printf("process_create fail\n");
	return -1;
	}
	process_wait();
	printf("execl success\n");
	return 0;
}
	
	
