#include <stdio.h>
#include <stdlib.h>
struct PS{
	int tu,mau;
};
int UCLN(int a,int b){
	if(a==0)    return b;
	return  UCLN(b%a,a);
}
void nhap1PS(PS *x)
{
	printf("Tu so:"); 	scanf("%d",&x->tu);
	do{
		printf("Mau so:"); 	scanf("%d",&x->mau);
	}while(x->mau==0);
	if(x->mau <0 )
	{
		x->tu = - x->tu;
		x->mau=-x->mau;
	}
}
void xuat1PS(PS x)
{
	printf("%d/%d  ",x.tu,x.mau);
}
void nhapDayPS(PS *p, int n){
	for(int i=0;i<n;i++)
	{
		printf("\n\tNHAP PHAN SO THU %d:\n",i+1);
		nhap1PS(p+i);
	}	
}
void xuatDayPS(PS *p,int n){
	for(int i=0;i<n;i++)
		xuat1PS(*(p+i));
}
int soSanh(PS x1, PS x2){   // neu tra ve so am thi x1<x2, so duong thi x1>x2, 0 thi x1=x2
	return (x1.tu*x2.mau - x1.mau*x2.tu);
}
PS timMax(PS *p,int n){
	PS max=*p;
	for(int i=0; i<n;i++)	
		if(soSanh(max,*(p+i)) <0 )
			max = *(p+i);
	return max;
}
PS rutGonPS(PS x){
	int uc= UCLN(x.tu,x.mau);
	PS rg;
	rg.tu=x.tu/uc;
	rg.mau = x.mau/uc;
	return rg;
}
PS cong2PS(PS x1,PS x2){
	PS tong;
	tong.tu=x1.tu*x2.mau+x1.mau*x2.tu;
	tong.mau=x1.mau*x2.mau;
	rutGonPS(tong);
	return tong;
}
PS tongDayPS(PS *p,int n){
	PS tong=*p;  // cho tong = phan tu dau trong day PS
	for(int i=1;i<n;i++)    // i=1 vi tong = phan tu dau roi
		tong=cong2PS(tong,*(p+i));
	return rutGonPS(tong);
}
int main()
{
	PS *x;
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	x=(PS*) malloc(n * sizeof(PS));
	nhapDayPS(x,n);
	printf("\nDay PS ban vua nhap la: ");
	xuatDayPS(x,n);
	printf("\nPS lon nhat trong day PS la: ");
	xuat1PS(timMax(x,n));
	printf("\nTONG DAY PS la: ");
	xuat1PS(tongDayPS(x,n));
	free(x);  // giai phong vung nho
}

