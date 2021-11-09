#include<stdio.h>
#include<string.h>
//a. Nhap vào ho so cua các nhân viên và luu vào tap tin nhanvien.inp
//d. Tính trung bình so tien phat cua mot nhân viên.
struct DATE{ // dinh nghia kieu du lieu DATE
	unsigned char ngay, thang;
	int nam;
};
struct NV{ // dinh nghia  kieu cau truc  du lieu NV
	char hovaten[30],gt; // chi la 0:nam 1:nu , sai thi nhap lai in ky tu don char
	DATE ngaysinh; // ngay sinh
	char diachi[300];
	float lcb,BHXH,Thuong,Phat,LTL,TBTienPhat; //float dang luy thua neu xuat %f of %e con %g co the loai bo cac so 00 dang sau
};
void nhapDATE(DATE &ng)
{
	//%u so nguyen khong dau
	printf("Nhap ngay/thang/nam: "); scanf("%u%*c%u%*c%u",&ng.ngay,&ng.thang,&ng.nam);
}
void xuatDATE(DATE d){
	printf("\n\t%02u/%02u/%04d",d.ngay,d.thang,d.nam);
}
void nhap1NV(NV &x)
{
	printf("Nhap hoten: "); 	fflush(stdin); 		gets(x.hovaten);
	printf("\nNhap vao dia chi: ");	fflush(stdin);		gets(x.diachi);
	nhapDATE(x.ngaysinh);
	do{
		printf("Gioi tinh (0:nu, 1:nam):"); fflush(stdin);	scanf("%c",&x.gt);
	}while(x.gt!='0' && x.gt!='1');
	printf("\n\t Luong co ban :");	fflush(stdin);// xoa vung nho dem ban phim
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
void nhapDSNV(NV x[], int n){
	for(int i=0; i<n;i++)
	{
		printf("\n\tNHAP NV %d:\n",i+1);
		nhap1NV(x[i]);
	}
}
void xuat1NV(NV x){
	xuatDATE(x.ngaysinh);
	if(x.gt=='0')   printf("Nu ");
	else printf("Nam");
	printf("	%s%\t%-15s%5.f%10.f%\n",x.hovaten,x.diachi,x.TBTienPhat,x.LTL);
	printf("\n LCB %f Thuong %5.f Phat %f BHXH %f\n",x.lcb,x.Thuong,x.Phat,x.BHXH);
}
void xuatDSNV(NV x[], int n){
	for(int i=0;i<n;i++)
		xuat1NV(x[i]);
}
//f. Thêm 1 nhân viên moi vào danh sách  vi trí x.
void themNVvaoVtX(NV x[],int &n,int vt){
	//doi cac pt tu vt k ve sau
	for(int i=n;i>vt;i--)
		x[i]=x[i-1];
	//doi xong
	nhap1NV(x[n]);
	n++;
}
//c Cho biet có bao nhiêu nhân viên bi phat, in thông tin cua nhân viên bi phat nhieu nhat.
int demSoNVPhat(NV x[], int n){
	int dem=0;
	for(int i=0;i<n;i++)
		if(x[i].Phat > 0)
			dem++;
	return dem;
}
void xuatNVPhat(NV x[], int n){
	int i;
	int max= x[0].Phat;
	for(int i=0;i<n;i++){
			if(max>x[i].Phat){
			max=x[i].Phat;
		}
	}
	xuat1NV(x[0]);
}
//e. In danh sách các nhân viên nu
void xuatDSNVnu(NV x[], int n){
	for(int i=0;i<n;i++)
			if(x[i].gt == '0')
		xuat1NV(x[i]);	
}
//b
int timMax(NV x[], int n){
	if(n==0)  return x[0].LTL;
	int max=timMax(x,n-1);
	if(x[n-1].LTL>max)   max=x[n-1].LTL;
	return max;
}
void ghiFileNP(char *tenFile,NV x[], int n){
	FILE *f=fopen(tenFile,"wb");
	for(int i=0;i<n;i++)
		fwrite(&x[i],sizeof(NV[n]),1,f);//nhi phan ( sizeo kich thuoc moi o nho tinh = byte )
	fclose(f);
}
void docFileNP(char tenFile[],NV x[],int n){
	FILE *f=fopen(tenFile,"rb");
	int i=0;
	while( !feof(f)){
		fread(&x[i],sizeof(NV[n]),1,f); //truyen vao dia chi
		i++;
		n=i;
	}
	fclose(f);	
}
int main()
{
	int n;
	NV x[100];
	printf("Nhap SLNV: "); scanf("%d",&n);
	nhapDSNV(x,n);
	xuatDSNV(x,n);
	int vt;
	printf("\nNhap vi tri muon chen:"); scanf("%d",&vt);
	themNVvaoVtX(x,n,vt);
	printf("\n\nDSNV SAU KHI them:\n");
	xuatDSNV(x,n);
	printf("\n\nDS co %d NV bi Phat.\n",demSoNVPhat(x,n));
	xuatNVPhat(x,n);
	printf("\n---DSSVNu------\n");
	xuatDSNVnu(x,n);
	printf("\nNV %s LTL Cao Nhat:%d",x,timMax(x,n));
	char tenFile[15] = "DSNV.TXT";
	ghiFileNP(tenFile,x,n);
	docFileNP(tenFile,x,n);
}
