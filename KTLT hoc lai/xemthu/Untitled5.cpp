#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct sanpham{
 char tensp[30];
 char masp[10];
 int gia;
} sp;
void nhap1sp(sp &a){
 printf("\nMoi nhap ten san pham: ");
 fflush(stdin);
 gets(a.tensp);
 printf("Moi nhap ma san pham: ");
 scanf("%s", &a.masp);
 printf("Moi nhap gia: ");
 scanf("%d", &a.gia);
}
void xuat1sp(sp a){
 printf("\nTen san pham: %s", a.tensp);
 printf("\nMa san pham: %s", a.masp);
 printf("\nGia: %d vnd", a.gia);
 printf("\n");
}
void nhapn(int &n){
 do{
  printf("Nhap so luong san pham: ");
  scanf("%d", &n);
  if (n<=0)
   printf("Nhap sai, nhap lai!!!\n");
 }while(n<=0);
}
void nhapds(sp a[], int n){
 for (int i=0; i<n; i++){
  printf("\nMoi nhap san pham thu %d", i+1);
  nhap1sp(a[i]);
 }
}
void xuatds(sp a[], int n){
 for (int i=0; i<n; i++){
  printf("\nSan pham thu %d", i+1);
  xuat1sp(a[i]);
 }
}
void timsp(sp a[], int n){
 char x[30];
 printf("Nhap ma san pham can tim: ");
    fflush(stdin);
 gets(x);
    int flag=0;
 for (int i=0; i<n; i++){
  if(strcmp(a[i].masp,x)==0){
   flag=1;
   xuat1sp(a[i]);
  }
 }
 if (flag==0)
  printf("Khong co san pham nay");
}
void sapxep(sp a[], int n){ 
 sp tam;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
         if(a[i].gia < a[j].gia){
                tam = a[i];
                a[i] = a[j];
                a[j] = tam;
         }
  }
    }
    xuatds(a,n);
}
void ghifile(sp a[], int n){
 FILE* f;
 f = fopen("DSSP.txt", "w");
 if (f==NULL){
  printf("Khong mo duoc file\n");
  exit(0);
 }
 for(int i=0;i<n;i++)
        fprintf(f,"Ten sap pham: %s\nMa sap pham: %s\nGia: %d\n",a[i].tensp,a[i].masp,a[i].gia); 
 fclose(f); 
}
int main()
{
 sp a[100];
    int n;
    char x;
    nhapn(n);
    nhapds(a,n);
    printf("\n======================Xuat danh sach=======================\n");
    xuatds(a,n);
    printf("\n======================Tim san pham=======================\n");
    timsp(a,n);
    printf("\n=================Sap xep theo gia===================\n");
 sapxep(a,n);
    ghifile(a,n);
 
    return 0;
}
