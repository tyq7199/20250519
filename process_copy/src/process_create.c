#include"process_copy.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int process_create(const char*srcfile,const char*destfile,int pronum,int blocksize)
{
	//1.create child process
	int i;
	char stroffset[10];
	char strblocksize[10];
	for(i=0;i<pronum;i++)
	{
		pid_t pid;
		pid=fork();
		if(pid<0)
		{
			perror("fork fail");
			return -1;
		}
		if(pid==0)
		{
			//2.execl copy
			int offset=i*blocksize;
			sprintf(stroffset,"%d",offset);
			sprintf(strblocksize,"%d",blocksize);
			execl("mod/copy","copy",srcfile,destfile,strblocksize,stroffset,NULL);
			perror("execl fail");
			exit(1);
		}
	}
	return 0;
}

