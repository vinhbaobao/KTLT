#include <stdio.h>
int Fibonacci(int n){
	if(n==1 || n==2)  return 1;
	return (Fibonacci(n-2)+Fibonacci(n-1));
}
int main()
{
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	printf("\nFibonacci thu %d la: %d",n,Fibonacci(n));
	printf("\nDay so Fibonacci tu vi tri 1 den vi tri %d: \n",n);
	for(int i=1;i<=n;i++)
		printf("%4d",Fibonacci(i));

}

