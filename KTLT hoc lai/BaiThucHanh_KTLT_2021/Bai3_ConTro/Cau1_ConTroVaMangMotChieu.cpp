#include <stdio.h>
#include <stdlib.h>
void nhapSL(int &n)
{
	do{
		printf("Nhap so phan tu mang: ");
		scanf("%d",&n);
	}while(n<=0 || n>=100);
}
void nhapMang(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",a+i);
	}
}
void xuatMang(int *a,int n)
{
	for(int i=0;i<n;i++)
		printf("\t%d",*(a+i));
}
int tongMang(int *a, int n)
{
	int s=0;
	for(int i=0;i<n;i++)
		s+= *(a+i);
	return s;
}
int main()
{
	int n,*a;
	nhapSL(n);
//Xin cap phat vung nho, dung mot trong cac dong sau:
	a=(int *) malloc(n*sizeof(int));
//	a=(int *) calloc(n,sizeof(int));
//	a=(int *) realloc(0,n * sizeof(int));
//	a=(int *) realloc(NULL,n * sizeof(int));
	nhapMang(a,n);
	xuatMang(a,n);
	printf("\nTong mang = %d",tongMang(a,n));
	free(a);
	return 0;
}

