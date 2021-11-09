#include <stdio.h>
#include <string.h>
int main()
{
	char s1[30],s2[30];
	printf("Nhap chuoi s1: ");
	gets(s1);
	printf("Nhap chuoi s2: ");
	gets(s2);
	printf("Ban vua nhap s1: %s  VA s2: %s",s1,s2);
	printf("\nDo dai s1= %d  va do dai s2= %d",strlen(s1),strlen(s2));

	int sosanh=strcmp(s1,s2);
	if(sosanh==0) printf("\ns1=s2");
	else 	if(sosanh >0)  printf("\ns1>s2");
			else printf("\ns1<s2");

	char *tim=strstr(s1,s2);
	printf("\n%s",tim);
	if(tim==NULL)   printf("\ns1 khong chua s2");
	else  printf("\ns1 chua s2 tai vi tri so %d",strlen(s1)-strlen(tim));
	
	if(strstr(s2,s1)==NULL)   printf("\ns2 khong chua s1");
	else printf("\ns2 chua s1 tai vi tri so %d",strlen(s2)-strlen(strstr(s2,s1)));
	

	printf("\nTim s1 trong s2: %s ",strstr(s1,s2));

	printf("\nNoi 2 chuoi: %s",strcat(s1,s2));
}

