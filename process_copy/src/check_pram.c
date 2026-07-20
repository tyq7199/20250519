#include"process_copy.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int check_pram(int argc,const char*srcfile,int pronum)
{
	//1.argc-num>3
	if(argc<3)
	{
		printf("argc few than need");
		return -1;
	}
	//2.src exist?
	if(access(srcfile,F_OK)!=0)
	{
		printf("src not exist");
		return -1;
	}
    //3.100>pronum>5
	if(pronum<=5||pronum>100)
	{
		printf("pronum not in 5~100");
		return -1;
	}
	return 0;
}



