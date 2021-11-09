#include <stdio.h>
#include <string.h>
#define MAX 10
void nhapn(int &n)
{
	do{
		printf("Nhap so nguyen duong: "); scanf("%d",&n);
	}while(n<=0);
}
struct DATE
{
	unsigned char ngay, thang;
	int nam;
};
struct SV
{
	char ma[9],hoten[30],gt;
	DATE ngaysinh;
	char lop[8];
	float dtb;
};
void nhapDATE(DATE &ng)
{
	printf("Nhap ngay/thang/nam: "); scanf("%u%*c%u%*c%u",&ng.ngay,&ng.thang,&ng.nam);
//	printf("Nhap thang: "); scanf("%u",&ng.thang);
//	printf("Nhap nam: "); scanf("%d",&ng.nam);
}
void xuatDATE(DATE d)
{
	printf("%02u/%02u/%04d",d.ngay,d.thang,d.nam);
}
void nhap1SV(SV &x)
{
	printf("Nhap MaSV: "); scanf("%s",x.ma);
	printf("Nhap ho ten: "); fflush(stdin); gets(x.hoten);
	nhapDATE(x.ngaysinh);
	printf("Lop: "); scanf("%s",&x.lop);
	do{
		printf("Gioi tinh (x:nu, y:nam):"); fflush(stdin);scanf("%c",&x.gt);
	}while(x.gt!='x' && x.gt!='y');
	printf("DTB: "); scanf("%f",&x.dtb);
}
void xuat1SV(SV x)
{
	printf("\n%-15s%-36s",x.ma,x.hoten);
	if(x.gt=='x')   printf("%-15s","Nu ");
	else printf("%-15s","Nam");
	xuatDATE(x.ngaysinh);
	printf("     %-15s%10.1f",x.lop,x.dtb);
}
void nhapDSSV(SV a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\tNhap SV thu %d:\n",i);
		nhap1SV(a[i]);
	}
}
void xuatDSSV(SV a[], int n)
{
	printf("\nDANH SACH SINH VIEN:");
	printf("\n%-15s%-36s%-15s%-15s%-15s%10s","MASV","HO TEN","GIOI TINH","NGAY SINH","LOP","DTB");
	for(int i=0;i<n;i++)
		xuat1SV(a[i]);
}
void xuatDSSVdtbhon5(SV a[], int n)
{
	printf("\nDANH SACH SINH VIEN CO DTB > 5:");
	printf("\n%-15s%-36s%-15s%-15s%-15s%10s","MASV","HO TEN","GIOI TINH","NGAY SINH","LOP","DTB");
	for(int i=0;i<n;i++)
		if(a[i].dtb > 5)
			xuat1SV(a[i]);
}
void xuatCNTT(SV a[], int n)
{
	printf("\nDANH SACH SINH VIEN NGANH CNTT:");
	printf("\n%-15s%-36s%-15s%-15s%-15s%10s","MASV","HO TEN","GIOI TINH","NGAY SINH","LOP","DTB");
	for(int i=0;i<n;i++)
		if(a[i].lop[3]=='T' && a[i].lop[4]=='H')
			xuat1SV(a[i]);
}
int demSVNu(SV a[], int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
		if(a[i].gt=='x')  dem++;
	return dem;
}
void themSVcuoiDS(SV a[],int &n)
{
	printf("THEM 1 SV VAO CUOI DS: \n");
	nhap1SV(a[n]);
	n++;
}
int timSVmaX(SV a[],int &n)  
{
	for(int i=0;i<n;i++)
		if(strcmp(a[i].ma,"X")==0 || strcmp(a[i].ma,"x")==0 )   return i;
	return -1;
}
void xoaSVvt(SV a[],int &n,int vt)
{
	for(int i=vt;i<n-1;i++)
		a[i]=a[i+1];
	n--;
}
void sortTang(SV a[],int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i].dtb > a[j].dtb)
			{
				SV tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
}
int main()
{
	int n;
	SV a[MAX];
	nhapn(n);
	nhapDSSV(a,n);
	xuatDSSV(a,n);
	sortTang(a,n);
	xuatDSSV(a,n);
}

