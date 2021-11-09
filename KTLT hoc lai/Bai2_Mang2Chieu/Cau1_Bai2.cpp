#include <stdio.h>
#define MAX 10
void nhapDC(int &d,int &c)
{
	do{
		printf("Nhap dong= "); scanf("%d",&d);
	}while(d<=0);
	do{
		printf("Nhap cot= "); scanf("%d",&c);
	}while(c<=0);	
}
void nhapMT(int a[][MAX], int d,int c)
{
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
		{
			printf("a[%d][%d]= ",i,j); scanf("%d",&a[i][j]);
		}
}
void xuatMT(int a[][MAX], int d,int c)
{
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<c;j++)	
			printf("%4d",a[i][j]);	
		printf("\n");	
	}
}
int tongMT(int a[][MAX],int d,int c)
{
	int tong=0;
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
			tong+=a[i][j];
	return tong;	
}
float TBCMT(int a[][MAX],int d,int c)
{
	return (float)tongMT(a,d,c)/(d*c);
}
float TBCDuong(int a[][MAX],int d,int c)
{
	int demSoDuong=0, tongSoDuong=0;
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)	
			if(a[i][j]>0)
			{
				demSoDuong++;
				tongSoDuong+=a[i][j];
			}
	return (float) tongSoDuong/demSoDuong;
}
void xuatDongK(int a[][MAX],int d,int c,int k)
{
	if(k>=d || k<0)
	{
		printf("\nKhong co Dong %d !!!",k);
		return;
	}
	printf("\nDong %d cua MT:\n",k);
	for(int j=0;j<c;j++)
		printf("%4d",a[k][j]);	
}
int tongDongK(int a[][MAX],int d,int c,int k)
{
	if(k>=d || k<0)
	{
		printf("\nKhong co Dong %d !!!",k);
		return 0;
	}
	int tong=0;
	for(int j=0;j<c;j++)
		tong+=a[k][j];	
	return tong;
}
int main()
{
	int m,n,a[MAX][MAX];
	nhapDC(m,n);
	nhapMT(a,m,n);
	printf("Ma tran vua nhap:\n");
	xuatMT(a,m,n);
	printf("\nTong MT= %d",tongMT(a,m,n));
	printf("\nTBC MT= %.2f",TBCMT(a,m,n));
	printf("\nTBC so duong= %.2f",TBCDuong(a,m,n));
	int k;
	printf("\nMuon xuat ra dong may: ");scanf("%d",&k);
	xuatDongK(a,m,n,k);
	printf("\nTong dong %d = %d",k,tongDongK(a,m,n,k));
}

