#include<stdio.h>

void nhapn(int &n){
	do 
	{
		printf("nhap gia tri n>0:");
		scanf("%d",&n); 
	}while(n<=0);
}
 
void xuatn(int n){
	for(int i=0;i<=n;i++)
	{
		printf("\n gia tri 1->n :%d",n);
}
	 
}
/*void ktrnto(int n){ 
    if (n <2) return ;
    int dem=0; 
	for(int i=2;i<n;i++){
		if(n%i==0)
			dem++; 
	} 
	if(dem==0){
		printf("%d la so ng to",n); 
	} 
	else 
		printf("%d ko phai la so ngto",n); 
    
    }*/
int  ktrnto(int n){ 
    if (n <2){
		return 0;
	}
    int dem=0; 
	for(int i=2;i<n;i++){
		if(n%i==0)
			dem++; 
	} 
	if(dem==0){
		return 1; 
	} 
	else 
		return 0; 
    
    }
void lkesonto(int n){
	for(int i=2;i<=n;i++){
		if(ktrnto(i)==1){
			printf("%d\t",i); 
		} 
}
}
int main(){
	int n;
	nhapn(n);
	printf("liet ke cac so nto");
	lkesonto(n);
	 
	
 
} 
