#include<stdio.h>
#include<string.h>
int main(){
	int n,i,Max,Min;
	int dem=0;
	char s[100];
	char kq[1000]="";
	FILE* fp=fopen("string4.txt","r");
	fscanf(fp,"%d",&n);
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		fscanf(fp,"%s",s);
		strcat(kq,"\t");
		strcat(kq,s);
	}
	printf("%s\n",kq);
	char test[30];
	printf("Nhap tu can tim:");
	scanf("%s",&test);
	char * kqtk=strstr(kq,test);
	if(kqtk!=NULL){
		printf("Tim thay chuoi:");
	}
	else{
		printf("Khong thay chuoi:");
	}
//r) �?m s? t? trong m?ng. T? l� d�y k� t? li�n ti?p nhau, gi?a c�c t? du?c ph�n c�chb?ng m?t hay nhi?u kho?ng tr?ng.
	n=strlen(kq);
	for(i=0;i<n;i++)               //dem tinh bang so(ky tu + khoang trang)lien nhau
		if(kq[i]!=' '&&kq[i]!='\t')
        if(kq[i+1]==' '||kq[i+1]=='\t')
       		dem++;
		if (kq[n-1]!=' '&& kq[n-1]!='\t')  //cuoi chuoi la ky tu
	printf("So tu = %d",dem+1);
    Max = Min = strlen(kq);
    for(i=0; i<n; i++) { //l?y t?ng chu?i sau d� d? so s�nh
    //t�m d? d�i Max
    if(Max<strlen(s)) //n?u d? d�i l?n hon Max
      Max = strlen(s); //th� luu v�o Max (chu tr�nh l?p l?i v?i c�c chu?i ti?p theo)
    //t�m d? d�i Min
    if(Min>strlen(s)) //n?u d? d�i nh? hon Min
      Min = strlen(s); //th� luu v�o Min
  }

//in ra gi� tr? d? d�i l?n nh?t v� nh? nh?t trong bi?n Max v� Min sau chu tr�nh l?p
  printf("\nDo dai lon nhat va nho nhat trong cac chuoi la Max = %d, Min = %d", Max, Min);
	fclose;
}
