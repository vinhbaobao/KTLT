#include <stdio.h>

int main () { 
	int sl,a[100];
		printf("Nhap so nguyen duong : "); scanf("%d",&sl);
	for (int i = 0; i<=sl; i++) {
		printf("Nhap a[%d]:",i);
		scanf("%d",&a[i]);
	}
	int m; // so nguyen m can nhap
	printf("\n Nhap Tog m : "); scanf("%d",&m);
//A Cho biet mang dã cho có bao nhiêu cap so có tog bang m. Luu ý (x,y) và (y,x) du?c d?m là mot cap
	int dem=0;
	for (int i = 0;i<sl - 1;i++)
	{
		for (int j=i+1;j<=sl;j++)
		{
			if (a[i] + a[j] == m)// bieu thuc
			dem+=1;
		}
	}
	printf("so luong cap la %d",dem);
//B T0ng bih phuong cac phan tu cua cap cac so . co tong =m
	int TBP=0;
		TBP=((dem*m)*(dem*m));
	TBP+=0;
		printf("\nTong binh phuong:%d",TBP);
//C co bao nhieu so trong mang la boi so chung cua m
	int demboiso=0;
	for(int i=0;i<m;i++)
				if(a[i]%m==0)
	demboiso=demboiso+1;
	printf("\nCo Bao Nhiu So Boi Trong Mang=m:%d",demboiso);	
	return 0;
}


