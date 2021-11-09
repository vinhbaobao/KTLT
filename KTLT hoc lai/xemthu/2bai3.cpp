#include <stdio.h>
//de quy dung ham fibonacci
int Fibonacci(int n){
	//Tinh so fibonacci thu n
 //@param n: chi so cua day fibonacci tinh tu 1

	if(n==1 || n==2)  return 1;
	return (Fibonacci(n-1)+Fibonacci(n-2)*(n-1));
	// @return so fibonacci thu n

}
//k de quy dung vong lap va mang 1 chiu
int khdequy(int n){
	int a[1000];
	a[1]=1;a[2]=1;
	for(int i=3;i<=n;i++){
		a[i]=a[i-1]+(i-1)*a[i-2];
	}
	return a[n];
}
//int khdequyc1(int n){
//	int x=n,x1=1,x2=1;
//	for(int i=3; i<=n; i++){
//		x=x2+x1*(i-1);
//		x1=x2;x2=x;
//	}
//	return x;
//}
int main()
{
	int n;	printf("Nhap n: "); scanf("%d",&n);
	printf("\nFibonacci thu %d la: %d",n,Fibonacci(n));
	printf("\nDay so Fibonacci tu vi tri 1 den vi tri %d: \n",n);
	for(int i=1;i<=n;i++)
		printf("%4d",Fibonacci(i));
	printf("\n kh de quy :%d",khdequy(n));
//	printf("\n kh de quy 1:%d",khdequyc1(n));

}

