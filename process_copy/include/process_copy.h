#ifndef PROCESS_COPY_H
#define PROCESS_COPY_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int check_pram();
int process_cur();
int process_create();
void process_wait();

#endif

