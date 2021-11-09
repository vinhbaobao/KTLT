#include <stdio.h>
#include <string.h>
void proper(char s[]){
	if(s[0]!=32 && s[0]>=90  && s[0]<=122)   	s[0]=s[0]-32;
	for(int i=1;i<strlen(s);i++)
	{
		if(s[i]!=32 && s[i-1]==32 && s[i]>=97 && s[i]<=122)  	s[i]=s[i] -32;   	//doi thanh HOA
		if(s[i]!=32 && s[i-1]!=32 && s[i]>=65 && s[i]<=90) 	s[i]=s[i] +32; 	//doi thanh thuong
	}	
}
int main()
{
	char s[30];
	printf("Nhap chuoi s: "); gets(s);
	proper(s);
	puts(s);
	
}

