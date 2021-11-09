#include <stdio.h>
#define MAX 100
/*void nhapn(int &n)
{
	do{
		printf("Nhap so nguyen duong <= 10: "); scanf("%d",&n);
	}while(0>n || n>MAX);
}*/
void nhapMang(int a[],int n)
{
	printf("Nhap mang:\n");
	for(int i=0;i<n;i++)
 	{
 		printf("a[%d]=",i);   scanf("%d",&a[i]);
 	}
}
void xuatMang(int a[], int n){
	printf("\nXuat mang:");
	for(int i=0;i<n;i++)     printf("%4d",a[i]);
}
int tim(int a[],int n,int x)  // Tim x xuat hien dau tien trong mang a, neu co tra ve vi tri, neu khong tra ve -1
{
 	for (int i=0; i<n ; i++)
		if ( x==a[i] ) 	return i;
	return -1;
}
void xoaTaiVitri(int a[],int &n,int vitri)   //&n de giam n trong main
{
	if(vitri >=n )
	{
		printf("Vi tri khong nam trong mang!");
		return;
	}
	for(int i=vitri;i<n-1;i++)
		a[i]=a[i+1];
	n--;
}
void chenX(int a[],int &n,int x,int vitri)
{
	for(int i=n;i>vitri;i--)
		a[i]=a[i-1];
	a[vitri]=x;
	n++;
}
void tachMang(int a[],int n,int b[],int c[])
{
	for(int i=0;i<(n/2);i++)
	{
		b[i]=a[i];
		c[i]=a[i+(n/2)];
	}
}
int main()
{
	int n,a[100],b[100],c[100];
//	nhapn(n);
	nhapMang(a,n);
	tachMang(a,n,b,c);
//	xuatMang(a,n);
//	xuatMang(b,n/2);
//	xuatMang(c,n/2);
	xoaTaiVitri(a,n,4);
	xuatMang(a,n);
	chenX(a,n,12,4);
	
}

