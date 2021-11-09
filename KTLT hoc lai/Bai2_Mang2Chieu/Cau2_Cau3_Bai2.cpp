#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void nhapn(int &n)
{
	do{
		printf("Nhap n: "); scanf("%d",&n);
	}while(n<=0);
}
void sinhMT(int x[][MAX],int n,int lan)
{
//	srand(time(0));  // trong <time.h> de sinh so khac nhau
	srand(time(0)+lan);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			x[i][j] = 0 + rand() % 5 ;  // so ngau nhien tu 0 den 9
}
void xuatMT(int a[][MAX],int d,int c)
{
	for(int i=0;i<d;i++){
		for(int j=0;j<c;j++)	
			printf("%3d",a[i][j]);
		printf("\n");
	}
}
void xuatCheoChinh(int a[][MAX],int d,int c)
{
	printf("\n");
	for(int i=0;i<d;i++){
		for(int j=0;j<c;j++)	
			if(i==j)
				printf("%4d",a[i][j]);
			else 
				printf("%4c",32);
		printf("\n");
	}
}
void xuatCheoChinhPhu(int a[][MAX],int d,int c)
{
	printf("\n");
	for(int i=0;i<d;i++){
		for(int j=0;j<c;j++)	
			if(i+j==d-1 || i==j)
				printf("%3d",a[i][j]);
			else 
				printf("%3c",32);
		printf("\n");
	}
}
void xuatDuongBien(int a[][MAX],int d,int c)
{
	printf("\n");
	for(int i=0;i<d;i++){
		for(int j=0;j<c;j++)	
			if(i==0 || i==d-1 || j==0 || j==c-1)
				printf("%3d",a[i][j]);
			else 
				printf("%3c",32);
		printf("\n");
	}
}
int tongDongK(int a[][MAX],int n,int k)
{
	int S=0;
	for (int i=0;i<n;i++)
		S+=a[k][i];
	return S;
}
void tongMoiDong(int a[][MAX], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nDong %d: ",i);
		for(int j=0;j<n;j++)
			printf("%3d",a[i][j]);
		printf("     Tong = %d",tongDongK(a,n,i));
	}
}
int maxTongDong(int a[][MAX],int n)
{
	int max=tongDongK(a,n,0),tam;
	for(int i=1;i<n;i++)
	{
		tam=tongDongK(a,n,i);
		if(tam>max)    max=tam;	
	}
	return max;	
}
void xuatDongTongMax(int a[][MAX],int n)
{
	int max=maxTongDong(a,n);
	printf("\nDong co tong lon nhat:");
	for(int i=0;i<n;i++)
	{
		if(tongDongK(a,n,i)==max)
		{
			printf("\nDong thu %d: ",i);
			for(int j=0;j<n;j++)
				printf("%3d",a[i][j]);
			printf("     Cong = %d",tongDongK(a,n,i));	
		}
	}		
}

int KTDoiXung(int a[][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j && a[i][j] != a[j][i])   return 0;
	return 1;
}
int tongBien(int a[][MAX],int d,int c)
{
	int s=0;
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
			if(i==0 || i==d-1 || j==0 || j==c-1)
				s+=a[i][j];
	return s;
}
int main()
{
	int a[MAX][MAX], b[MAX][MAX],c[MAX][MAX],n,k;
	nhapn(n);
	sinhMT(a,n,1);
	xuatMT(a,n,n);
	printf("\nTong duong bien 2 = %d",tongBien(a,n,n));
	xuatCheoChinhPhu(a,n,n);
	xuatDuongBien(a,n,n);
	printf("\nNhap dong muon tinh tong: "); scanf("%d",&k);
	if(k<0 || k>=n)
		printf("\nKhong co dong nay!");
	else 
		printf("Tong dong %d = %d",k,tongDongK(a,n,k));
	tongMoiDong(a,n);
	xuatDongTongMax(a,n);
	int dx=KTDoiXung(a,n);
	if(dx==1)      printf("\nMa tran doi xung.");
	else 				printf("\nMa tran KHONG doi xung.");
}

