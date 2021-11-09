#include <stdio.h>
struct SACH{
	int ma;
	char ten[10];
	float gia;
};
void nhapN(int &n){
	do{
		printf("Nhap n: "); scanf("%d",&n);
	}while(n<=0);
}
void nhap1Sach(SACH &x){
	printf("Ma (so nguyen): "); scanf("%d",&x.ma);
	printf("Ten: "); fflush(stdin); gets(x.ten);
	printf("Gia: ");  scanf("%f",&x.gia);
}
void nhapDSSach(SACH x[], int n){
	for(int i=0; i<n;i++)
	{
		printf("\tNHAP SACH THU %d:\n",i+1);
		nhap1Sach(x[i]);
	}
}
void xuat1Sach(SACH x){
	printf("\n   %-4d%-12s%10.0f",x.ma,x.ten,x.gia);
}
void xuatDSSach(SACH x[], int n){
	for(int i=0;i<n;i++)
		xuat1Sach(x[i]);
}
void ghiFileNP(char *tenFile,SACH a[], int n){
	FILE *f=fopen(tenFile,"wb");
	for(int i=0;i<n;i++)
		fwrite(&a[i],sizeof(SACH),1,f);
	fclose(f);
}
void docFileNP(char tenFile[],SACH a[],int n){
	FILE *f=fopen(tenFile,"rb");
	int i=0;
	while( !feof(f)){
		fread(&a[i],sizeof(SACH),1,f);
		i++;
	}
	fclose(f);	
}
int main()
{
	int n=5;
	char tenFile[15] = "DSSach.DAT";
	nhapN(n);
	SACH a[n],b[n];
	nhapDSSach(a,n);
	xuatDSSach(a,n);
	ghiFileNP(tenFile,a,n);
	docFileNP(tenFile,b,n);
	xuatDSSach(b,n);
}

