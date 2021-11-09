#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50
void sinhMT(int a[][MAX],int d, int c)
{
	srand(time(0));
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
			a[i][j]=rand()%10;
}
void xuatMT(int a[][MAX],int d,int c)
{
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<c;j++)	
			printf("%3d",a[i][j]);
		printf("\n");
	}	
}
void ghiFile(int a[][MAX],int d,int c)
{
	FILE *f=fopen("test.inp","wt");
	if(f==NULL)
	{
		printf("Khong mo duoc file de ghi!");
		exit(0);
	}	
	fprintf(f,"%3d%3d\n",d,c);
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<c;j++)	
			fprintf(f,"%3d",a[i][j]);
		fprintf(f,"\n");
	}		
	fclose(f);
}
void docFile(int a[][MAX],int &d,int &c)
{
	FILE *f=fopen("test.inp","rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file de doc!");
		exit(0);
	}
	fscanf(f,"%d%d",&d,&c);
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)	
			fscanf(f,"%d",&a[i][j]);
	fclose(f);
}
int main()
{
	int a[MAX][MAX],d=5,c=6;
	sinhMT(a,d,c);
	xuatMT(a,d,c);
	ghiFile(a,d,c);
	int b[MAX][MAX];
	docFile(b,d,c);
	printf("\nMT doc tu file:\n");
	xuatMT(b,d,c);
	
}

