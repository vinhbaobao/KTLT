#include<stdio.h>
#define MAX 100
void docTuFileLuuVaoBien(char *tenFile,int a[], int &n)
{
	FILE *f=fopen(tenFile,"rt"); // r: read ; t:text (file van ban)
	if(f==NULL)   // neu khong mo duoc
	{
		printf("KHONG MO FILE DUOC!!!");
		return;    // thi thoat!
	}
	// da mo file
	fscanf(f,"%d",&n);   // doc so 8 tu File vao bien n
	for(int i=0;i<n;i++)
		fscanf(f,"%d",&a[i]);   // doc day so ben duoi vao a[i]
	fclose(f);  // lam xong dong file
}
void xuatMang(int a[], int n)
{
	for(int i=0;i<n;i++)
		printf("%3d",a[i]);
}
int KTNT(int n)   // kiem tra xem n co phai la so nguyen to khong? 1: NT    0: khong NT
{
	if(n<2)	   return 0; // khong phai NT
	for(int i=2; i<n;i++)
		if(n%i==0)    return 0;   // khong phai so NT!
	return 1;   // la so NT
}
void themSoNTvaoFile(char *tenFile, int a[], int n)
{
	FILE *f=fopen(tenFile,"at"); // a: append ; t:text (file van ban)
	if(f==NULL)   // neu khong mo duoc
	{
		printf("KHONG MO FILE DUOC!!!");
		return;    // thi thoat!
	}
	//da mo file roi
	fprintf(f,"\nCac so nguyen to trong mang la: ");
	for(int i=0;i<n;i++)
		if(KTNT(a[i])==1)
		{
			fprintf(f,"%3d",a[i]); // xuat a[i] ra File
		}
	
	fclose(f)	;
}
int main()
{
	int a[MAX], n;
	char tenFile[30]="CAU1.TXT";
	docTuFileLuuVaoBien(tenFile,a,n);
	printf("\nMang vua doc tu file: ");
	xuatMang(a,n);
	themSoNTvaoFile(tenFile,a,n);
}
