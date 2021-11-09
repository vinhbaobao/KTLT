#include <stdio.h>

int UCLN(int a,int b){
	if(a==0)    return b;
	return  UCLN(b%a,a);
}
int BCNN(int a,int b)
{
 	if(a==0)    return 0;
 	return (a*b)/UCLN(a,b);
} 
int main()
{
	int a,b;
	printf("Nhap a b : "); scanf("%d%d",&a,&b);
	printf("\nUCLN(%d,%d)= %d",a,b,UCLN(a,b));
	printf("\nBCNN(%d,%d)= %d",a,b,BCNN(a,b));
}

