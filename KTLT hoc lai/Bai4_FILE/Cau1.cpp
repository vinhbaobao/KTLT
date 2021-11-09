#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int KTNT(int n)
{
	if(n<2) return 0;
	for(int i=2;i<n;i++)
		if(n%i==0)  return 0;
	return 1;
}
void docFile(int a[],int &n)
{
	FILE *f=fopen("CAU1.TXT","rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file de doc!");
		exit(0);
	}
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++)
		fscanf(f,"%d",&a[i]);	
	fclose(f);
}
void ghiFile(int a[],int n)
{
	FILE *f=fopen("CAU1.TXT","at");
	fprintf(f,"\nCac so nguyen to trong mang la:\n");
	for(int i=0;i<n;i++)
		if(KTNT(a[i])==1)
			fprintf(f,"%3d",a[i]);
	fclose(f);	
}
void xuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%4d",a[i]);
}
int main()
{
	int n,a[MAX];
	docFile(a,n);
	printf("\nMang vua doc tu file:");
	xuatMang(a,n);
	ghiFile(a,n);
}

