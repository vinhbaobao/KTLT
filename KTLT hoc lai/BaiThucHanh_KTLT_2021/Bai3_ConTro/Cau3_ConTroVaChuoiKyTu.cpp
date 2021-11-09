#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int doDai(char *s){
	int i=0;
	while( *(s+i) != '\0')
		i++;
	return i;
}
char* proper(char *s){
	//xem ky tu dau tien neu la chu thuong thi doi thanh chu in
	if( *s>='a' && *s <='z')     *s = *s -32; 
	int i=1; 
	while( *(s+i) != '\0') 
	{
		// neu no la dau tu va no la chu thuong thi doi thanh in
		if( *(s+i-1) == 32 && *(s+i) >= 'a'  && *(s+i) <= 'z') // 32 la ma Ascii cua KHOANG TRANG
			*(s+i) = *(s+i)   -32;
		// neu no o giua va la chu in thi doi thanh chu thuong
		if( *(s+i-1) != 32 && *(s+i) >= 'A'  && *(s+i) <= 'Z')
			*(s+i) = *(s+i)   +32;
		i++;
	}
	return s;
}
char* noiChuoi(char *s1,char *s2){
	char *s;
	s=(char*) malloc(100 * sizeof(char));
	int i=0;
	while(*s1 !='\0'){
		*(s+i) = *s1;
		i++; s1++;
	}
	while(*s2 !='\0'){
		*(s+i) =*s2;
		i++; s2++;
	}
	return s;
}
int main(){
	char *s1, *s2;
	s1=(char*) malloc(50 * sizeof(char));
	s2=(char*) malloc(50 * sizeof(char));
	printf("Nhap s1: ");   	gets(s1);
	fflush(stdin);   // xoa vung nho dem ban phim
	printf("Nhap s2: ");   	gets(s2);
	printf("\nBan vua nhap:\n");
	puts(s1);   	
	puts(s2);
	printf("\nDo dai s1= %d",doDai(s1));
	printf("\nDo dai s2= %d",doDai(s2));
	printf("\nDo dai s1= %d",strlen(s1));  // strlen trong string.h
	printf("\nDo dai s2= %d",strlen(s2));	
	if(strcmp(s1,s2)==0)    	printf("\ns1=s2");
	else
		if(strcmp(s1,s2)>0)   	printf("\ns1>s2");
		else 					printf("\ns1<s2");
	printf("\nDoi thanh chu hoa dau tu: \ns1=%s    \ns2=%s",proper(s1),proper(s2));
	char *s3;
	printf("\nNoi 2 chuoi: %s",noiChuoi(s1,s2));
	
}
