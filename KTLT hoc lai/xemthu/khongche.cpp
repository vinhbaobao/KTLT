#include<iostream>
using namespace std;
#include<stdio.h>
#include<conio.h>
#define max 250     //  neu mang la kieu int thi max =round(sqrt(max_int))
/*Tao 2 mang chua cac toa do con ma khong che tai vtri (x=0,y=0)*/
int a[8]={2,1,-1,-2,-2,-1,1,2};
int b[8]={1,2,2,1,-1,-2,-2,-1};

class conma
{
   public:
	   int  banco[max][max];
	   void taobanco(int size);       
	   void khongche(int size,int x,int y); 
     
};

void conma::taobanco(int size)
{
   int i,j;
   for(i=0;i<size;i++)
	   for(j=0;j<size;j++)
		   banco[i][j]=0;
}


void conma::khongche(int size,int x,int y)
{
   int u;
   int v;
   for(int i=0;i<8;i++)
   {
	   u=x+a[i];
	   v=y+b[i];
	   if(0<=u && u<size && 0<=v && v<size && banco[u][v]==0)  
		banco[u][v]=2;
   }
}


int main()
{
  int dem[65000];  //so ptu cua dem[] chinh xac la max_int(v?i m?ng int)
  int k,l,h,count;
  int m,n,min,tmp;
  int size;
  int dk=0;
  char thoat;
  conma cm;
  while(dk==0)
  {
    tt:  cout<<"Nhap kich thuoc cua ban co ( kich thuoc >=3 ) :";
    cin>>size;
    if(size<3)
    {
       cout<<"              Kich thuoc phai >= 3!!!";
	   cout<<endl;
	   goto tt;
    }
    cout<<endl;
	h=0;                    //de moi lan lap lai chuong trinh thi mang dem[] bat dau lai tu dau

    for(m=0;m<size;m++)                    //chon tung vi tri dat dau tien
    {   
   	  for(n=0;n<size;n++)                  
	  {
 /*tinh so con ma can dat vao ban co ung voi tung vtri dat dau tien*/
		 cm.taobanco(size);                
		 tmp=n;                            
		 count=0;
         for(k=m;k<size;k++)               
         {
	         for(l=tmp;l<size;l++)
	         {
		         if(cm.banco[k][l]==0)
		         {
			        cm.banco[k][l]=1;
			        count++;               
		                cm.khongche(size,k,l);
		         }
	         }
			 tmp=0;
		 }
                 for(int a=0;a<size;a++)
	              for(int b=0;b<size;b++)
		          if(cm.banco[a][b]==0)
		          {
                               cm.banco[a][b]=1;
			       count++;
		               cm.khongche(size,a,b);    
			  } 
	  h++;
         dem[h]=count;
	  }
  
  }
  

    /*xuat so quan ma tuong ung voi tung vi tri dat dau tien(voi dk la size<=10 vi vua du chieu dai man hinh)*/
    if(size<=10)
	{
		cout<<"So con ma can phai dat de khong che toan bo ban co tuong ung \n voi tung vi tri dat dau tien la:"<<endl<<endl;
        for(int x=1;x<=h;x++)          
        {
	       cout<<dem[x]<<"\t";
	       if(x%size==0)
    	       cout<<endl;
        }
	}
    /*Tim so con ma it nhat de khong che ban co*/
    min=dem[1];
    for(int x=1;x<h;x++)         
    {
   	 if(dem[x+1]<min)
		 min=dem[x+1];
    }
  
  cout<<"\n \n So con ma can it nhat de khong che toan bo ban co la: "<<min<<endl<<"--------------------------------\n";
  cout<<"Ban co muon tiep tuc chuong trinh ko?(y/n)";
  tt1: cin>>thoat;
  if(thoat=='n'||thoat=='N')
      dk=1;
  else if(thoat=='y'||thoat=='Y')
	       dk=0;
       else   
	   {
		   cout<<"Chi nhap y hoac n";
		   cout<<"Nhap lai: ";
		   goto tt1;
       }
  }
  getch();
}
