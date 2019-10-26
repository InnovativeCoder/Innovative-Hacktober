#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

	int server_socket;
	struct sockaddr_in servaddr,cliaddr;

void CreateServerSocket()
{
	server_socket = socket(AF_INET,SOCK_DGRAM,0);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8000);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(bind(server_socket,(struct sockaddr *)&servaddr,sizeof(servaddr))<0){
		printf("-1");
	}
	printf("BINDED\n");
}

int main(){
	CreateServerSocket();
	printf("Returned\n");
	int n;
	int len=sizeof(cliaddr);
	int rd = recvfrom(server_socket,&n,sizeof(n),0,(struct sockaddr *) &cliaddr, &len);
	printf("VALUE RECIEVE %d\n",n);
	char buf[256] = "SErver to client -- send all rows\0";
	int se = sendto(server_socket,buf,sizeof(buf),0,(struct sockaddr *) &cliaddr, len);
	printf("\n");
	int row[5];
	int mat[5][5];
	int k =0;
	for(int i =0;i<5;i++){
		recvfrom(server_socket,row,sizeof(row),0,(struct sockaddr *) &cliaddr,&len);
		for(int j =0;j<5;j++)
		printf("%d",row[j]);
		for(int j = 0;j<5;j++)
		mat[k][j] = row[j];
		k++;
		printf("\n1 row done\n");
	}
	printf("\n");
	printf("The matrix is : \n");
	for(int i =0;i<5;i++){
		for(int j =0;j<5;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	sendto(server_socket,mat,sizeof(mat),0,(struct sockaddr *) &cliaddr,len);
	printf("Server completed");
	close(server_socket);
}