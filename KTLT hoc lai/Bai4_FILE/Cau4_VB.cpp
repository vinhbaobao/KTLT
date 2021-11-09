#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct HH
{
	char mh[5];
	int sl;
	float dg;
};
void nhapn(int &n)
{
	do{
		printf("So phan tu: "); scanf("%d",&n);
	}while(n<=0);
}
void nhap1HH(HH &x)
{
	printf("MH: ");fflush(stdin); scanf("%s",&x.mh);
	printf("SL: "); scanf("%d",&x.sl);
	printf("DG: "); scanf("%f",&x.dg);
}
void nhapDSHH(HH x[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\n\tNhap HH thu %d\n",i+1);
		nhap1HH(x[i]);	
	}	
}
void xuat1HH(HH x)
{
	printf("\n%-7s%8d%12.1f%12.1f",x.mh,x.sl,x.dg,x.sl*x.dg);
}
void ghiVaoFileVB(HH x[],int n)
{
	FILE *f=fopen("DSHH.TXT","wt");
	if(f==NULL)
	{
		printf("Khong mo duoc");
		return;
	}
	fprintf(f,"%d",n);
	for(int i=0;i<n;i++)
		fprintf(f,"\n%-7s%8d%12.1f%12.1f",x[i].mh,x[i].sl,x[i].dg,x[i].sl*x[i].dg);
	fclose(f);
}
void xuatDSHH(HH x[],int n)
{
	printf("%-7s%8s%12s%12s","MA","SL","DG","TT");
	for(int i=0;i<n;i++)
		xuat1HH(x[i]);
}
void docFile()
{
	FILE *f=fopen("DSHH.TXT","rt");
	if(f==NULL)
	{
		printf("Khong mo duoc");
		return;
	}
	char ch[255];
	while(fgets(ch,255,f))
		printf("%s",ch);
	fclose(f);	
}
void docFileLuuVaoCT(HH x[],int &n)
{
	FILE *f=fopen("DSHH.TXT","rt");
	if(f==NULL)
	{
		printf("Khong mo duoc");
		return;
	}
	float tt;
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++)
		fscanf(f,"%s%d%f%f",&x[i].mh,&x[i].sl,&x[i].dg,&tt);
	fclose(f);	
}
int main()
{
	
	int n;
		printf("Nhap SLHH: "); scanf("%d",&n);
	HH a[MAX];
	ghiVaoFileVB(a,n);
	docFileLuuVaoCT(a,n);
	printf("DS HH doc tu file:\n");
	nhapDSHH(a,n);
	xuatDSHH(a,n);
}
