#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 101
void nhapChuoi(char s[])
{
	printf("Nhap chuoi: "); fflush(stdin) ;gets(s);
}
void ghiNguyenAm(char s[])
{
	FILE *f=fopen("NguyenAm.txt","wt");
	if(f==NULL)
	{
		printf("Khong mo duoc file de ghi!");
		exit(0);
	}
	int d=strlen(s);
	for(int i=0;i<d;i++)
		if( s[i]=='a'|| s[i]=='e'|| s[i]=='o'|| s[i]=='u'|| s[i]=='i' || s[i]=='A'|| s[i]=='E'|| s[i]=='O'|| s[i]=='U'|| s[i]=='I'   )
			fprintf(f,"%3c",s[i]);
	fclose(f);		
}
void docfileNguyenAm(char s[])
{
	FILE *f=fopen("NguyenAm.txt","rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file de doc!");
		exit(0);
	}
	fgets(s,100,f);
	fclose(f);
}
int main()
{
	char s[MAX],s2[MAX]="";
	nhapChuoi(s);
	ghiNguyenAm(s);
	docfileNguyenAm(s2);
	if(strlen(s2)>0)
	{
		printf("\nDoc tu file nguyen am: ");
		puts(s2);		
	}
	else
		printf("\nChuoi khong co nguyen am!");
}

