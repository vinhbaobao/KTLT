#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void sinhMT(int x[][MAX],int d,int c,int lan)
{
	srand(time(0)+lan);
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
			x[i][j] = 0 + rand() % 5 ;  // so ngau nhien tu 0 den 9
}
void tongMT(int a[][MAX], int b[][MAX],int c[][MAX],int da, int ca)
{
	for (int i=0;i<da;i++)
		for(int j=0;j<ca;j++)
			c[i][j]=a[i][j]+b[i][j];
}
void tichMT(int a[][MAX],int m, int n, int b[][MAX],int k, int c[][MAX])   //k la so cot cua b
{
	for (int i=0;i<m;i++)
		for(int j=0;j<k;j++)
		{
			c[i][j]=0;
			for(int p=0;p<n;p++)	
				c[i][j]+=a[i][p]*b[p][j];
		}		
}
void xuatMT(int a[][MAX],int d,int c)
{
	for(int i=0;i<d;i++){
		for(int j=0;j<c;j++)	
			printf("%3d",a[i][j]);
		printf("\n");
	}
}
int main()
{
	int a[MAX][MAX],da,ca,b[MAX][MAX],db,cb,c[MAX][MAX],dc,cc;
	printf("Nhap so dong MT a: ");scanf("%d",&da);
	printf("Nhap so cot MT a: ");scanf("%d",&ca);
	printf("Nhap so dong MT b: ");scanf("%d",&db);
	printf("Nhap so cot MT b: ");scanf("%d",&cb);	
	sinhMT(a,da,ca,1);
	sinhMT(b,db,cb,2);
	printf("\nMa tran a:\n");
	xuatMT(a,da,ca);
	printf("\nMa tran b:\n");
	xuatMT(b,db,cb);	
	if(da==db && ca==cb)
	{
		tongMT(a,b,c,da,ca);
		printf("\nMT a + MT b:\n");
		xuatMT(c,da,ca);
	}
	if(ca==db)	
	{
		tichMT(a,da,ca,b,cb,c); 
		printf("\nTich 2 MT axb =\n");
		xuatMT(c,da,cb);
	}
	if(cb==da)
	{
		tichMT(b,db,cb,a,ca,c); 
		printf("\nTich 2 MT bxa =\n");
		xuatMT(c,db,ca);		
	}
}

