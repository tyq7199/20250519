#include"process_copy.h"
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

void process_wait(void)
{
	int status;
	while(wait(&status)!=-1);
}

