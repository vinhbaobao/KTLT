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
void nhapHH(HH &x)
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
		nhapHH(x[i]);	
	}	
}
void xuatHH(HH x)
{
	printf("\n%-7s%8d%12.1f%12.1f",x.mh,x.sl,x.dg,x.sl*x.dg);
}
void xuatDSHH(HH x[],int n)
{
	printf("%-7s%8s%12s%12s","MA","SL","DG","TT");
	for(int i=0;i<n;i++)
		xuatHH(x[i]);
}
void ghiVaoFileNP(HH x[],int n)
{
	FILE *f=fopen("DSHH.DAT","wb");
	if(f==NULL)
	{
		printf("Khong mo duoc");
		return;
	}
	fwrite(x,sizeof(HH),n,f);
	fclose(f);
}
void docFileLuuVaoCT(HH x[], int &n)
{
	FILE *f=fopen("DSHH.DAT","rb");
	if(f==NULL)
	{
		printf("Khong mo duoc");
		return;
	}
	int i=0;
	while(fread(&x[i],sizeof(HH),1,f))
		i++;
	n=i;
	fclose(f);	
}
int main()
{
	int n;
	HH a[MAX];
	docFileLuuVaoCT(a,n);
	xuatDSHH(a,n);
	nhapn(n);
	nhapDSHH(a,n);
	ghiVaoFileNP(a,n);	
}
