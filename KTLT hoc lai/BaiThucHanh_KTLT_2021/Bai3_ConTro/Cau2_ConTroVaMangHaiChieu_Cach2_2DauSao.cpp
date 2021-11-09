#include <stdio.h>
#include <stdlib.h>
void nhapSL(int &m,int &n)
{
	do{
		printf("Nhap so dong: ");
		scanf("%d",&m);
	}while(m<=0 || m>=100);
	do{
		printf("Nhap so cot: ");
		scanf("%d",&n);
	}while(n<=0 || n>=100);	
}
void nhapMaTran(int **a, int m, int n)
{
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			printf("a[%d][%d]= ",i,j);
			scanf("%d",(*(a+i)+j));
		}
}
void xuatMaTran(int **a, int m, int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			printf("%4d",*(*(a+i)+j) );
		printf("\n");
	}
}
int tongMT(int **a,int m,int n){
	int s=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			s= s + *(*(a+i)+j);	
	return s;
}
int main()
{
	int m,n;
	nhapSL(m,n);
	int **a ;
	//xin cap phat vung nho
	a = (int**)calloc(m,sizeof(int));
	for(int i=0;i<m;i++)
	  	a[i] = (int*) calloc(n,sizeof(int));
	//------------------
	nhapMaTran(a,m,n);
	printf("\nMa tran vua nhap:\n");
	xuatMaTran(a,m,n);
	printf("\nTong MT = %d",tongMT(a,m,n));
	
	//giai phong bo nho
	for(int i=0;i<m;i++)
		free(a[i]);
	free(a);
}
