#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>  //inet_addr

int main(int argc, char*agrv[])
{
	int socket_desc;
	struct sockaddr_in server;

	//create socket
	socket_desc=socket(AF_INET, SOCK_STREAM,0);
	if(socket_desc==-1)
	{
		printf("Cloud not create socket");
	}

	server.sin_family=inet_addr("192.168.72.3"); //server ip addr
	server.sin_family=AF_INET;
	server.sin_port=htons(22);

	//connect to remote server
	if(connect(socket_desc, (struct sockaddr*)&server, sizeof(server))<0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected");
	return 0;
}
