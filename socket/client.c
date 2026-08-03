#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void){
	int client_sockfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in destaddr;
	destaddr.sin_family=AF_INET;
	destaddr.sin_port=htons(8080);
	destaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	int err=connect(client_sockfd,(struct sockaddr*)&destaddr,sizeof(destaddr));
	if(err==-1){
		printf("connect fail\n");
	}
	else{
		printf("connect sucess\n");
	}
	char buf[1024];
	recv(client_sockfd,buf,sizeof(buf),0);
	printf("%s\n",buf);
	close(client_sockfd);
	return 0;
	}

