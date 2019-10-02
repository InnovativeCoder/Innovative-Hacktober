#include<stdio.h>
int main(){
	long long int t;
	scanf("%lld",&t);
	while(t--){
		long long int n,i,j,a=0,b=1,c=3,d=7,e=12,f=22,g=35,h=49;
		scanf("%lld",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j==a||j==b||j==c||j==d||j==e||j==f||j==g||j==h){
					printf("O");
				}
				else{
					printf(".");
				}
			}
			a=(a+1)%n;
			b=(b+1)%n;
			c=(c+1)%n;
			d=(d+1)%n;
			e=(e+1)%n;
			f=(f+1)%n;
			g=(g+1)%n;
			h=(h+1)%n;
			printf("\n");
		}
	}
}
