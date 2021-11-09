#include <stdio.h>
#define MAX 100
void nhapn(int &n)
{
	do{
		printf("Nhap so nguyen duong: "); scanf("%d",&n);
	}while(n<=0);
}
void nhapMang(int a[], int n)
{
	if(n==0)   return;
	nhapMang(a,n-1);
	printf("Nhap a[%d]=",n-1);
	scanf("%d",&a[n-1]);
}
void xuatMang(int a[], int n)
{
	if(n==0)   return;
	xuatMang(a,n-1);
	printf("%4d",a[n-1]);
}
int tongMang(int a[], int n)
{
	if(n==0) return 0;
	int s=tongMang(a,n-1);
	s=s+a[n-1];
	return s;
}
int tongPTChan(int a[], int n)
{
	if(n==0)  return 0;
	int s=tongPTChan(a,n-1);
	if(a[n-1]%2==0)
		s=s+a[n-1];
	return s;
}
int demSoPTDuong(int a[], int n)
{
	if(n==0)    return 0;
	int dem=demSoPTDuong(a,n-1);
	if(a[n-1]>0)
		dem++;
	return dem;
}
int timMax(int a[], int n)
{
	if(n==0)    return a[0];
	int max=timMax(a,n-1);
	if(a[n-1]>max)
		max=a[n-1];
	return max;
}
int timChanCuoi(int a[], int n) // -1: Mang khong co PT chan
{
	if(n==0) 	return -1;
	int chancuoi=timChanCuoi(a,n-1);
	if(a[n-1]%2==0)
		chancuoi=a[n-1];
	return chancuoi;
}
int timXCuoi(int a[],int n,int x)
{
	if(n==0)   return -1;
	int vt=timXCuoi(a,n-1,x);
	if(a[n-1]==x)
		vt=n-1;
	return vt;
}
int main()
{
	int n, a[MAX];
	nhapn(n);
	nhapMang(a,n);
	printf("Mang vua nhap: ");
	xuatMang(a,n);
	printf("\nTong mang = %d",tongMang(a,n));
	printf("\nTong PT chan = %d",tongPTChan(a,n));
	printf("\nSo PT duong = %d",demSoPTDuong(a,n));
	printf("\nPT lon nhat = %d",timMax(a,n));
	int chancuoi=timChanCuoi(a,n);
	if(chancuoi==-1)
		printf("\nMang khong co PT chan.");
	else
		printf("\nPT chan cuoi la %d",chancuoi);
		
	int x;
	printf("\nNhap gia tri can tim: "); scanf("%d",&x);
	int vtx=timXCuoi(a,n,x);
	if(vtx==-1)
		printf("\nMang khong co PT x=%d",x);
	else
		printf("\nPT x=%d o vi tri %d",x,vtx);	
	
}
