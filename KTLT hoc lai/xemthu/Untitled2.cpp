#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//a. Nhap vào ho so cua các nhân viên và luu vào tap tin nhanvien.inp
//d. Tính trung bình so tien phat cua mot nhân viên.
struct DATE{
	unsigned char ngay, thang;
	int nam;
};
struct NV{
	char hovaten[30],gt;
	DATE ngaysinh;
	char diachi[300];
	float lcb,BHXH,Thuong,Phat,LTL,TBTienPhat;
};
void nhapDATE(DATE &ng)
{
	printf("Nhap ngay/thang/nam: "); scanf("%u%*c%u%*c%u",&ng.ngay,&ng.thang,&ng.nam);
}
void xuatDATE(DATE d){
	printf("\t%02u/%02u/%04d",d.ngay,d.thang,d.nam);
}
void nhap1NV(NV &x)
{
	printf("Nhap hoten: "); 	fflush(stdin); 		gets(x.hovaten);
	printf("\nNhap vao dia chi: ");	fflush(stdin);		gets(x.diachi);
	nhapDATE(x.ngaysinh);
	do{
		printf("Gioi tinh (0:nu, 1:nam):"); fflush(stdin);	scanf("%c",&x.gt);
	}while(x.gt!='0' && x.gt!='1');
	printf("\n\t Luong co ban :");	fflush(stdin);
		scanf("%f",&x.lcb);
	printf("\n\t BHXH :");			fflush(stdin);
		scanf("%f",&x.BHXH);
	printf("\n\t Luong Thuong :");	fflush(stdin);
		scanf("%f",&x.Thuong);
	printf("\n\t Phat :");			fflush(stdin);
		scanf("%f",&x.Phat);
	x.TBTienPhat=x.lcb-x.Phat;
	x.LTL=x.lcb+x.Thuong-x.BHXH-x.Phat;
}
void xuat1NV(NV x){
	xuatDATE(x.ngaysinh);
	if(x.gt=='0')   printf("Nu ");
	else printf("Nam");
	printf("	%s%\t%-15s%5.f%10.f%\n",x.hovaten,x.diachi,x.TBTienPhat,x.LTL);
	printf("\n LCB %f Thuong %5.f Phat %f BHXH %f\n",x.lcb,x.Thuong,x.Phat,x.BHXH);
}
void nhapDSHHvaoFileVB(char tenFile[]){
	FILE *f=fopen(tenFile,"wt");
	if(f==NULL){
		printf("KHONG MO FILE DUOC!");
		return;
	}
	int n;
	printf("\nNhap bao nhieu hang hoa: "); scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("\nNhap hang hoa thu %d: \n",i);
		xuatDATE(x[n].ngaysinh);
		if(x[n].gt=='0')   printf("Nu ");
		else printf("Nam");
		fprintf(f,"	%s%\t%-15s%5.f%10.f%\n",x[n].hovaten,x[n].diachi,x[n].TBTienPhat,x[n].LTL);
		fprintf(f,"\n LCB %f Thuong %5.f Phat %f BHXH %f\n",x[n].lcb,x[n].Thuong,x[n].Phat,x[n].BHXH);
	fclose(f);
	}
}
int main(){
	char tenFileVB[20]="DSHH.TXT";
	nhapDSHHvaoFileVB(tenFileVB,x,n);
	docFileVB(tenFileVB);
	//GHI va DOC file NHI PHAN
	char tenFileNP[20]="DSHH.DAT";
	nhapDSHHvaoFileNP(tenFileNP);
	docFileNP(tenFileNP);

}
