#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void sinhMT(int a[][MAX], int d,int c){
	srand(time(0));
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
			a[i][j]=rand()%10;
}
void xuatMT(int a[][MAX], int d, int c){
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<c;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
}
void ghiMT(int a[][MAX], int d,int c){
	FILE *f=fopen("test.inp","wt");
	if(f==NULL){
		printf("Khong mo duoc file!");
		return;
	}
	fprintf(f,"%3d%3d\n",d,c);
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<c;j++)
			fprintf(f,"%3d",a[i][j]);
		fprintf(f,"\n");
	}
	printf("\nDa luu vao file!");
	fclose(f);
}
void docFile(int a[][MAX], int &d,int &c){
	FILE *f=fopen("test.inp","rt");
	if(f==NULL){
		printf("\nKhong mo duoc flie!");
		return;
	}
	fscanf(f,"%d%d",&d,&c);
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
			fscanf(f,"%d",&a[i][j]);
	printf("\nDa doc file luu vao bien MT xong.\n");
	fclose(f);
}
int main()
{
	int a[MAX][MAX],b[MAX][MAX], db,cb;
	sinhMT(a,5,6);
	ghiMT(a,5,6);
	docFile(b,db,cb);
	xuatMT(b,db,cb);
}

