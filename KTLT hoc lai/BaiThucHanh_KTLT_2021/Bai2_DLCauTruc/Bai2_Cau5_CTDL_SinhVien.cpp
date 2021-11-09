
#include <stdio.h>
#include <string.h>
struct DATE{   // dinh nghia kieu du lieu DATE
	int ngay,thang,nam;
};
/*struct MH{ 		// dinh nghia kieu du lieu MON HOC
	char tenMH[20];
	float diem;
};*/
struct SV{       // dinh nghia kieu du lieu sinh vien
	char ma[6];
	char hoTen[20];
	DATE ns;  // ngay sinh
	int gt; // chi la 0:nam 1:nu , sai thi nhap lai
	char lop[6];
//	int soMon;
//	MH dsMH[100];
};
//float tinhDTB(SV x); // khai bao nguyen mau



/*void nhap1MH(MH &m){   // ham nhap mot mon hoc
	fflush(stdin);   // xoa vung nho dem ban phim
	printf("Ten mon hoc: "); gets(m.tenMH);
	printf("Diem: "); scanf("%f",&m.diem);
}
void nhapDSMH(MH m[],int n){   // nhap danh sach mon hoc
	for(int i=0;i<n;i++)
	{
		printf("\n\tNHAP MON HOC THU %d\n",i+1);
		nhap1MH(m[i]);
	}
}*/
void nhapDATE(DATE &d){     // nhap mot bien kieu DATE
	printf("Ngay/thang/nam: "); scanf("%d%*c%d%*c%d",&d.ngay,&d.thang,&d.nam);
}
void nhap1SV(SV &x){  // nhap mot sinh vien
	printf("Ma SV: "); scanf("%s",&x.ma);
	printf("Ho ten SV: ");   
	fflush(stdin);   // xoa vung nho dem ban phim
	gets(x.hoTen);
	nhapDATE(x.ns);
	do{
		printf("Gioi tinh (0:nam, 1:nu): ");    scanf("%d",&x.gt);
	}while(x.gt != 0  && x.gt !=1);
	fflush(stdin);   // xoa vung nho dem ban phim
	printf("Lop: "); scanf("%s",&x.lop);
//	printf("So mon hoc: "); scanf("%d",&x.soMon);
//	nhapDSMH(x.dsMH,x.soMon);	
}
void nhapDSSV(SV x[],int n){     // nhap danh sach sinh vien
	for(int i=0;i<n;i++)
	{
		printf("\tNHAP SINH VIEN THU %d\n",i+1);
		nhap1SV(x[i]);
	}
}
/*void xuat1MH(MH m){    // xuat mot mon hoc ra man hinh
	printf("\n\t\t%-20s%5.1f",m.tenMH,m.diem);
}
void xuatDSMH(MH m[],int n){   // xuat danh sach n mon hoc ra man hinh
	for(int i=0;i<n;i++)
		xuat1MH(m[i]);
}*/
void xuat1SV(SV x){    // xuat mot sinh vien ra man hinh
	printf("\n%-7s%-20s%-8s DTB= %5.1f",x.ma,x.hoTen,x.lop,(x));
	if(x.gt ==0)    printf("  Nam  ");
	else 			printf("  Nu   ");	
	printf("  %02d/%02d/%4d   ",x.ns.ngay,x.ns.thang,x.ns.nam);
//	printf("\n\tDS CAC MON HOC CUA SV %s",x.hoTen);
//	xuatDSMH(x.dsMH,x.soMon);
}
void xuatDSSV(SV x[], int n){    // xuat danh sach n sinh vien ra man hinh
	for(int i=0;i<n;i++)
		xuat1SV(x[i]);
}
int demSoSVNu(SV x[], int n){
	int dem=0;
	for(int i=0;i<n;i++)
		if(x[i].gt == 1)
			dem++;
	return dem;
}
/*void xuatDSTH(SV x[], int n){
	for(int i=0;i<n;i++)
		if(x[i].lop[3]=='T' && x[i].lop[4]=='H')   // thoa dieu kien moi xuat sv do ra
			xuat1SV(x[i]);	
}
float tinhDTB(SV x){
	float tongDiem=0;
	for(int i=0;i<x.soMon;i++)
		tongDiem= tongDiem+ x.dsMH[i].diem;
	return tongDiem/x.soMon;
}
float dtbMax(SV x[], int n){
	float max= tinhDTB(x[0]);
	float dtb;
	for(int i=0;i<n;i++)
	{
		dtb=tinhDTB(x[i]);
		if(dtb>max)      max=dtb;
	}
	return max;
}
void xuatDSdtbMax(SV x[], int n){
	float maxDTB= dtbMax(x,n);
	for(int i=0;i<n;i++)
	{
		if(tinhDTB(x[i])==maxDTB)
			xuat1SV(x[i]);
	}
}
void timXvaXoa(SV a[], int &n, char x[]){
	for(int i=0;i<n;i++)
		if(strcmp(a[i].ma,x) == 0)
		{
			//xoa SV thu i
			for(int j=i;j<n-1;j++)
				a[j]=a[j+1];
			//xoa xong
			printf("\nDA TIM THAY VA DA XOA.");
			n--;
			return;
		}
	printf("\n\nTRONG DSSV KHONG CO MA X NAY!")	;
}
void themSVcuoiDS(SV x[],int &n){
	printf("\nNHAP THEM SV VAO CUOI DS:\n");
	nhap1SV(x[n]);
	n++;
}*/
void themSVvaoVtK(SV x[],int &n,int vt){
	//doi cac pt tu vt k ve sau
	for(int i=n;i>vt;i--)
		x[i]=x[i-1];
	//doi xong
	nhap1SV(x[vt]);
	n++;
}
int main()
{
	int n;   // khai bao bien n chua so nguyen
	printf("Nhap n: "); scanf("%d",&n);   // nhap so nguyen vao n
	SV x[100];   // khai bao mang 100 phan tu kieu du lieu SV
	nhapDSSV(x,n);  // dung ham nhapDSSV de nhap du lieu vao n sinh vien
	xuatDSSV(x,n);  // xuat ALL danh sach sv ra man hinh
//	printf("\n\nDS co %d SV nu.",demSoSVNu(x,n));
//	printf("\n\nDANH SACH SV TIN HOC:");
//	xuatDSTH(x,n);
//	printf("\n\nDANH SACH SV CO DTB CAO NHAT:");
//	xuatDSdtbMax(x,n);
//	char maMuonXoa[6];
//	printf("\nNHAP MA SV BAN MUON XOA: ") ; scanf("%s",&maMuonXoa);
//	timXvaXoa(x,n,maMuonXoa);
//	printf("\n\nDSSV SAU KHI THUC HIEN HAM TIMVAXOA:");
//	xuatDSSV(x,n);
//	themSVcuoiDS(x,n);
	int vt;
	printf("\nNhap vi tri muon chen:"); scanf("%d",&vt);
	themSVvaoVtK(x,n,vt);
	printf("\n\nDSSV SAU KHI them:");
	xuatDSSV(x,n);	
}

