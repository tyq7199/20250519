#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#define BUF 4096

int main(int argc,char **argv)
{
	if(argc!=5)
	{
		exit(-1);
	}
	int fd_src,fd_dst;
	int blocksize=atoi(argv[3]);
	off_t offset=atoll(argv[4]);
	//1.open src
	fd_src=open(argv[1],O_RDONLY);
	if(fd_src<0)
	{
		perror("open src fail");
		exit(-1);
	}
	//2.open dst
	fd_dst=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fd_dst<0)
	{
		perror("dst open fail");
		exit(-1);
	}
	//3.change read-write location
	lseek(fd_src,offset,SEEK_SET);
	lseek(fd_dst,offset,SEEK_SET);
	//4.get blocksize-num
	char buf[BUF];
	int n;
	while(blocksize>0&&(n=read(fd_src,buf,BUF))>0)
	{
		write(fd_dst,buf,n);
		blocksize=blocksize-n;
	}
	//5.close
	close(fd_src);
	close(fd_dst);
	return 0;
}
	
