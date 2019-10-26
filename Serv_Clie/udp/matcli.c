#include<stdlib.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
int clisocket;
struct sockaddr_in servaddr;

void CreateClientSocket(){
	clisocket = socket(AF_INET,SOCK_DGRAM,0);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(8000);
}
int main(){
	CreateClientSocket();
	int n = 5;
	int len=sizeof(servaddr);
	int rc = sendto(clisocket,&n,sizeof(n),0,(struct sockaddr *) &servaddr,len);
	printf("SENT\n");
	char buf[256];
	int rd = recvfrom(clisocket,buf,sizeof(buf),0,(struct sockaddr *)&servaddr,&len);
	puts(buf);
	printf("Enter ROws\n");
	int row[5];
	for(int l = 0;l<5;l++){
		for(int i =0;i<5;i++){
			scanf("%d",&row[i]);
		}
		sendto(clisocket,row,sizeof(row),0,(struct sockaddr *) &servaddr,len);
	}
	int mat[5][5];
	recvfrom(clisocket,mat,sizeof(mat),0,(struct sockaddr *) &servaddr,&len);
	printf("\n");
	for(int i =0;i<5;i++){
		for(int j = 0;j<5;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	printf("Terminated client");
	close(clisocket);
}
