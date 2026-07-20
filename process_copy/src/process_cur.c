#include"process_copy.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int process_cur(const char *srcfile,int pronum)
{
	//1.srcfile-size
	struct stat file_info;
	stat(srcfile,&file_info);
	long file_size=file_info.st_size;
	//2.blocksize/pronum
	int blocksize=file_size/pronum;
	if(file_size%pronum!=0)
	{
		blocksize=blocksize+1;
	}
	return blocksize;
}

