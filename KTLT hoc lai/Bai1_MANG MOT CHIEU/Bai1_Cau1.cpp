#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void a_nhapn(int &n)
{
	do{
		printf("Nhap so nguyen duong <= 10: "); scanf("%d",&n);
	}while(n<=0 || n>10);
}
void a_nhapMang(int a[],int n)
{
	printf("Nhap mang:\n");
	for(int i=0;i<n;i++)
 	{
 		printf("a[%d]=",i);   scanf("%d",&a[i]);
 	}
}
int e_timGTPTMax(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
		if(a[i]>max)  max=a[i];
	return max;
}
int f_demSoPTMax(int a[],int n)
{
	int dem=0,max=e_timGTPTMax(a,n);
	for(int i=0;i<n;i++)
		if(a[i] == max)   dem++;
	return dem;
}
void g_xuatViTriPTMax(int a[],int n)
{
	int max=e_timGTPTMax(a,n);
	printf("\nVi tri cac phan tu Max: ");
	for(int i=0;i<n;i++)
		if(a[i]==max)  printf("%4d",i);
}
void b_xuatMang(int a[], int n){
	printf("\nXuat mang:\n");
	for(int i=0;i<n;i++)     printf("%4d\n",a[i]);
}
void c_viTriGiaTriDuongDau(int a[],int n)
{
	for(int i=0;i<n;i++)
		if(a[i]>0)
		{
			printf("Vi tri duong dau tien: %d va co gia tri la: %d",i,a[i]);
			return;
		}
	printf("Mang khong co gia tri duong!");
}
void h_themPT(int a[],int &n,int vitri, int giatri)
{
	for(int i=n;i>vitri;i--)
		a[i]=a[i-1];
	a[vitri]=giatri;
	n++;
}
void k_xoaPT(int a[],int &n,int vitri)
{
	for(int i=vitri;i<n-1;i++)
		a[i]=a[i+1];
	n--;
}
int l_kiemTraCoSoLe(int a[],int n)  //tra ve 1 neu co, 0 thi khong co so le
{
	int co=0;
	for(int i=0;i<n;i++)
		if(a[i]%2==1)
		{
			co=1;
			break;
		}	
	return co;
}
void m_taoMangChuaPTChan(int a[],int n, int b[],int &m)
{
	int j=0;
	for(int i=0;i<n;i++)
		if(a[i]%2==0)
		{
			b[j]=a[i];
			j++;
		}
	m=j;
}
int main()
{
	int n,a[100],b[100],m;
	a_nhapn(n);
	a_nhapMang(a,n);
	c_viTriGiaTriDuongDau(a,n);
//	srand((int)time(0));
//	for(int i=0;i<n;i++)
//		a[i]=0 + rand() % 10;
//	b_xuatMang(a,n);
//	m_taoMangChuaPTChan(a,n,b,m);
//	b_xuatMang(b,m);
//	if(l_kiemTraCoSoLe(a,n))  printf("\nMANG CO SO LE.");
//	else   printf("\nMANG KHONG CO SO LE.");

}

