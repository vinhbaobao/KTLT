#include <stdio.h>
#include <string.h>
void luuNgAm(char s[]){
	FILE *f=fopen("NguyenAm.txt","wt");
	if(f==NULL){
		printf("Khong mo duoc file!");
		return;
	}
	while( *s != '\0'){
		if(*s=='a'||*s=='e'||*s =='i'||*s =='o'||*s =='u'||*s=='A'||*s=='E'||*s=='I'||*s=='O'||*s=='U')
			fprintf(f,"%3c",*s);
			s++;
	}
	fclose(f);
}
void docFile(char s[]){
	FILE *f=fopen("NguyenAm.txt","rt");
	if(f==NULL){
		printf("Khong mo duoc file!");
		return;
	}
	while( !feof(f))   // TRONG KHI KHONG PHAI CUOI FILE (EOF: END OF FILE)
		fgets(s,101,f);
	fclose(f);
}
int main()
{
	char s[101],s1[101]="";
	printf("Nhap chuoi: ");
	gets(s);
		
	luuNgAm(s);
	docFile(s1);
	
	if(strlen(s1) != 0)   // neu do dai chuoi s1 khac 0
	{
		printf("Cac nguyen am luu trong file la: ");
		puts(s1);		
	}
	else printf("Chuoi khong co nguyen am!");
}

