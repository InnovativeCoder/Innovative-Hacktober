#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10200

int createServerSocket(int sockfd, struct sockaddr_in seraddr){
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	return sockfd;
}

void terminateSocket(int sockfd){
	close(sockfd);
}

void performServerTask(int sockfd, int newsockfd, struct sockaddr_in cliaddr){
	int n = 1, clilen, a, b, op, res;
	char buf[256];

	listen(sockfd, 5);
	printf("Server waiting...\n");
	while(n){
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr,&clilen);

		if(fork() == 0){
			n = read(newsockfd, &a, sizeof(a));
			n = read(newsockfd, &b, sizeof(b));
			printf("Numbers received from client\n");
			printf("%d %d\n", a, b);
			n = read(newsockfd, &op, sizeof(op));
			printf("Operator received from client\n");
			printf("%c\n", op);
			if(op=='+')
				res = a+b;
			else if(op=='-')
				res = a-b;
			else if(op=='*')
				res = a*b;
			else if(op=='/')
				res = a/b;
			else if(op=='%')
				res = a%b;
			printf("Res: %d\n", res);
			n = write(newsockfd, &res, sizeof(res));
			terminateSocket(newsockfd);
			exit(0);
		}
		else{
			terminateSocket(newsockfd);
		}
	}
}

int main(){
	int sockfd, newsockfd, clilen;
	struct sockaddr_in seraddr, cliaddr;

	sockfd = createServerSocket(sockfd, seraddr);
	performServerTask(sockfd, newsockfd, cliaddr);
	terminateSocket(sockfd);
}
