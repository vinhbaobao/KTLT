#include <stdio.h>
struct HH{
	char mh[5];
	int sl;
	float dg,tt;
};
void nhap1HH(HH &h){
	printf("Ma HH: ") ; scanf("%s",&h.mh);
	printf("SL: ");  scanf("%d",&h.sl);
	printf("DG: ");  scanf("%f",&h.dg);
	h.tt=h.sl*h.dg;
}
void xuat1HH(HH tam){
	printf("%-5s%8d%10.1f%15.1f\n",tam.mh,tam.sl,tam.dg,tam.tt);
}
void nhapDSHHvaoFileVB(char tenFile[]){
	FILE *f=fopen(tenFile,"wt");
	if(f==NULL){
		printf("KHONG MO FILE DUOC!");
		return;
	}
	int n;
	HH tam;
	printf("\nNhap bao nhieu hang hoa: "); scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("\nNhap hang hoa thu %d: \n",i);
		nhap1HH(tam);  			// nhap HH vao bien tam, xong tu bien tam ghi vao file
		fprintf(f,"%-5s%8d%10.1f%15.1f\n",tam.mh,tam.sl,tam.dg,tam.tt);
	}
	fclose(f);
}
void nhapDSHHvaoFileNP(char tenFileNP[]){
	FILE *f=fopen(tenFileNP,"wb");
	if(f==NULL){
		printf("KHONG MO FILE DUOC!");
		return;
	}
	int n;
	HH tam;
	printf("\nNhap bao nhieu hang hoa: "); scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("\nNhap hang hoa thu %d: \n",i);
		nhap1HH(tam);      // nhap HH vao bien tam, xong tu bien tam ghi vao file
		fwrite(&tam,sizeof(tam),1,f);
	}
	fclose(f);
}
void docFileNP(char tenFileNP[]){   // doc file nhi phan
	FILE *f=fopen(tenFileNP,"rb");
	if(f==NULL){
		printf("KHONG MO FILE DUOC!");
		return;
	}
	HH tam;
	while(!feof(f)){
		if(fread(&tam,sizeof(tam),1,f) ==1)   // doc duoc 1 phan tu thi moi xuat1HH
			xuat1HH(tam);
	}
	fclose(f);
}
void docFileVB(char tenFileVB[]){
	FILE *f=fopen(tenFileVB,"rt");
	if(f==NULL){
		printf("KHONG MO FILE DUOC!");
		return;
	}		
	while(!feof(f)){
		char tam[255]="";
		fgets(tam,255,f);
		printf("%s",tam);
	}
	fclose(f);
}
int main(){
	char tenFileVB[20]="DSHH.TXT";
	nhapDSHHvaoFileVB(tenFileVB);
	docFileVB(tenFileVB);
	//GHI va DOC file NHI PHAN
	char tenFileNP[20]="DSHH.DAT";
	nhapDSHHvaoFileNP(tenFileNP);
	docFileNP(tenFileNP);

}

