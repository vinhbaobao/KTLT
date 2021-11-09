#include <stdio.h>
void nhapN(int &n){
	do{
		printf("Nhap so nguyen: ");
		scanf("%d",&n);
	}while(n<=0);
}
void nhapMang(int a[], int n){
	if(n==0)    
		return;
	nhapMang(a,n-1);
	printf("a[%d]=",n-1);  
	scanf("%d",&a[n-1]);
}
void xuatMang (int a[], int n){
	if(n==0)  return;
	xuatMang(a,n-1);
	printf("%4d",a[n-1]);
}
int tongMang(int a[], int n){
	if(n==0)   return 0;
	int S=tongMang(a,n-1);
	S+=a[n-1];
	return S;
}
int tongChan(int a[], int n){
	if(n==0)   return 0;
	int S=tongChan(a,n-1);
	if(a[n-1] %2==0)
		S+= a[n-1];
	return S;
}
int demDuong(int a[], int n){
	if(n==0)  return 0;
	int dem=demDuong(a,n-1);
	if(a[n-1]>0)    dem++;
	return dem;	
}
int timMax(int a[], int n){
	if(n==0)  return a[0];
	int max=timMax(a,n-1);
	if(a[n-1]>max)   max=a[n-1];
	return max;
}
int timMin(int a[], int n){
	if(n==0)  return a[0];
	int min=timMin(a,n-1);
	if(a[n-1]<min)   min=a[n-1];
	return min;
}
int timChanCuoi(int a[],int n){
	if(n==0)    return -1; // mang khong co pt chan
	int chan = timChanCuoi(a,n-1);
	if(a[n-1]%2==0)   chan = a[n-1];
	return chan;
}
int timVTxCuoi(int a[], int n, int x){
	if(n==0)  return -1;   //khong tim thay x
	int vt= timVTxCuoi(a,n-1,x);  // vt la vi tri
	if(a[n-1]==x)    vt=n-1;
	return vt;
}
int main()
{
	int n,a[100];
	nhapN(n);
	nhapMang(a,n);
	xuatMang(a,n);
	printf("\nTONG MANG = %d",tongMang(a,n));
	printf("\nTONG CAC PHAN TU CHAN = %d",tongChan(a,n));
	printf("\nMANG CO %d PHAN TU DUONG.",demDuong(a,n));
	printf("\nGIA TRI LON NHAT TRONG MANG = %d",timMax(a,n));
	printf("\nGIA TRI NHO NHAT TRONG MANG = %d",timMin(a,n));
	int chanCuoi= timChanCuoi(a,n);
	if(chanCuoi==-1)   printf("\nMANG KHONG CO PHAN TU CHAN");
	else	printf("\nPHAN TU CHAN CUOI CUNG TRONG MANG = %d",chanCuoi);
	int x;
	printf("\nNhap x = ");   scanf("%d",&x);
	int xCuoi=timVTxCuoi(a,n,x);
	if(xCuoi==-1)   printf("MANG KHONG CO PHAN TU X NAY!");
	else	printf("PHAN TU X CUOI CUNG TRONG MANG NAM TAI VI TRI = %d",xCuoi);
	
}

