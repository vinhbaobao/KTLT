#include <stdio.h>
#include <string.h>
int main()
{
	char s1[20],s2[20];
	printf("Nhap chuoi s1: "); fflush(stdin);	gets(s1);
	printf("Nhap chuoi s2: "); fflush(stdin);	gets(s2);
	printf("Ban vua nhap 2 chuoi:\n");
	printf("   s1 do dai %d :  ",strlen(s1)); puts(s1);
	printf("   s2 do dai %d :  ",strlen(s2)); puts(s2);	
	int ss=strcmp(s1,s2);
	if(ss==0)     printf("Chuoi s1 = Chuoi s2.");
	else
		if(ss>0)    printf("Chuoi s1 > Chuoi s2.");
		else			printf("Chuoi s1 < Chuoi s2.");
	strcat(s1,s2);
	printf("\nChuoi s1 (sau khi noi) do dai %d :  ",strlen(s1)); puts(s1);
	


}

