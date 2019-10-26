#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#define PORTNO 10200

int createClientSocket(int sockfd, struct sockaddr_in address){
	int len, result;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(PORTNO);

	len = sizeof(address);
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if(result == -1){
		perror("\nCLIENT ERROR");
		exit(1);
	}
	return sockfd;
}

void performClientTask(int sockfd){
	int n, a, b, res=0;
	char op;

	printf("Enter 2 numbers: ");
	scanf("%d %d", &a, &b);
	write(sockfd, &a, sizeof(a));
	write(sockfd, &b, sizeof(b));
	printf("Enter operator: ");
	scanf(" %c", &op);
	write(sockfd, &op, sizeof(op));

	read(sockfd, &res, sizeof(res));
	printf("Server sent: %d\n", res);
}

void terminateSocket(int sockfd){
	close(sockfd);
}

int main(){
	int sockfd, n=1;
	struct sockaddr_in address;

	sockfd = createClientSocket(sockfd, address);
	performClientTask(sockfd);
	terminateSocket(sockfd);
}

