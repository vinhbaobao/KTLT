#include <stdio.h>
void nhapMangKhongTrung(int a[],int n)
{
	int sai;
	for(int i=0;i<n;i++)
		do
		{
			printf("Nhap a[%d]= ",i); scanf("%d",&a[i]);
			sai=0;
			for(int j=0;j<i;j++)
				if(a[j]==a[i])    
				{
					sai=1;
					break;
				} 
			if(sai==1) printf("SAI ROI, NHAP LAI!\n");
		}while(sai==1);
}
void nhapn(int &n)
{
	do{
		printf("Nhap n duong:"); scanf("%d",&n);
	} while(n<=0);
}
int main()
{
	int a[100],n;
	nhapn(n);
	nhapMangKhongTrung(a,n);
}

