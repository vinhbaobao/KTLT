#include <stdio.h>
#include <string.h>
#define MAX 100
struct DATE
{
	unsigned char ngay;
	unsigned char thang;
	int nam;
};
void nhapNgayThangNam(DATE &d)
{
	printf("\t\tNhap ngay: "); scanf("%u",&d.ngay);
	printf("\t\tNhap thang: "); scanf("%u",&d.thang);
	printf("\t\tNhap nam: "); scanf("%d",&d.nam);
}
void xuatNgayThangNam(DATE d)
{
	printf("%02u/%02u/%04d",d.ngay,d.thang,d.nam);
}
typedef struct BUUKIEN
{
	char ma[11];
	char nguoigui[31];
	char nguoinhan[31];
	float trongluong;
	DATE ngaygui;
	char noidung[31];
	float dongia;
}BK;
void nhap1BK(BK &x)
{
	printf("\n\tNhap ma: ");  scanf("%s",&x.ma);
	printf("\tNhap ho ten nguoi gui: ");fflush(stdin); gets(x.nguoigui);
	printf("\tNhap ho ten nguoi nhan: ");fflush(stdin); gets(x.nguoinhan);
	printf("\tNhap trong luong: ") ; scanf("%f",&x.trongluong);
	printf("\tNhap ngay gui:\n"); nhapNgayThangNam(x.ngaygui);
	printf("\tNhap noi dung: ") ; fflush(stdin); gets(x.noidung);
	printf("\tNhap don gia: ") ; scanf("%f",&x.dongia);
}
void nhapSoPT(int &n)
{
	do{
		printf("Nhap so phan tu cua mang (duong): "); scanf("%d",&n);
	}while (n<=0);
}
void xuat1BK(BK x)
{
	printf("\n %-5s\t%-10s\t%-10s\t%5.1f\t",x.ma,x.nguoigui,x.nguoinhan,x.trongluong);
	xuatNgayThangNam(x.ngaygui);
	printf("\t%-10s\t%5.1f",x.noidung,x.dongia);
}
void nhapDSBK(BK a[],int n)
{
	printf("Nhap Danh sach buu kien:\n");
	for(int i=0;i<n;i++)
	{
		printf("    Nhap BK thu %d: ",i+1);
		nhap1BK(a[i]);
	}
}
void xuatDSBK(BK a[],int n)
{
	printf("Xuat DSBK:");
	for(int i=0;i<n;i++)
		xuat1BK(a[i]);
}
void them1BKvaoDS(BK a[],int &n)
{
	nhap1BK(a[n]);
	n++;
}
void sortBK(BK a[],int n)
{
	BK tam;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(strcmp(a[i].ma,a[j].ma)>0)
			{
				tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
}
float giaTriBK(BK a){
	return a.dongia*a.trongluong;
}
float trongLuongMax(BK a[],int n){
	float tlMax= a[0].trongluong;
	for(int i=0;i<n;i++)
		if(tlMax <a[i].trongluong)    tlMax=a[i].trongluong;
	return tlMax;
}
int demSlBKTlMax(BK a[],int n){
	int dem=0;
	float tlMax=trongLuongMax(a,n);
	for(int i=0;i<n;i++)
		if(a[i].trongluong==tlMax)  dem++;
	return dem;
}
void timBKtheoTen(BK a[],int n, char tengui[31]){
	for(int i=0;i<n;i++)
		if(strcmp(a[i].nguoigui,tengui)==0)    xuat1BK(a[i]);
}
void xuatBK042014(BK a[],int n){
	printf("\nCac buu kien trong thang 4 nam 2014: ");
	for(int i=0;i<n;i++)
		if(a[i].ngaygui.thang==4 && a[i].ngaygui.nam ==2014)   xuat1BK(a[i]);
}
int main()
{
	BK a[MAX];
	int n;
	nhapSoPT(n);
	nhapDSBK(a,n);
//	them1BKvaoDS(a,n);
	xuatDSBK(a,n);
	xuatBK042014(a,n);
//	printf("\nCo %d BK co trong luong lon nhat.",demSlBKTlMax(a,n));
//	char tim[31];
//	printf("\nNhap ten can tim: "); fflush(stdin); gets(tim);
//	timBKtheoTen(a,n,tim);
	
//	sortBK(a,n);
//	xuatDSBK(a,n);
}

