#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void){
int server_sock=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in addr;
addr.sin_family=AF_INET;
addr.sin_port=htons(8080);
addr.sin_addr.s_addr=htonl(INADDR_ANY);
bind(server_sock,(struct sockaddr*)&addr,sizeof(addr));
listen(server_sock,128);
int client_sockfd=accept(server_sock,NULL,NULL);
write(client_sockfd,"hi 33.12.45.7 connect sucessly",strlen("hi 33.12.45.7 connect sucessly"));

close(client_sockfd);
close(server_sock);
return 0;
}

