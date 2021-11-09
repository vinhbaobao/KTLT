#include<stdio.h>
#define max
// ham tra ve so luong toi da
// CAC con ma duoc dat tren ban co
// bàn co sao cho các con ma khong an lan nhau m la dong n la cot
int max_knight(int m, int n)
{
// Kiem tra chéo hoa góc # 1
     // Neu hàng hoac cot là 1
    if (m == 1 || n == 1) {
		// Neu có, thì cho con in tung so khoi
         // so là giá tri ti da cua hàng hoac cat
        return max(m,n);
    }
// Kiem tra truong hop góc # 2
     // Neu hàng hoac cot là 2
    else if (m == 2 || n == 2) {
	// Neu có, thì chi con tính toán
         // 2 hàng hoac cot liên tiep
        int c = 0;
        c = (max(m, n) / 4) * 4;
  
        if (max(m,n) % 4 == 1) {
            c += 2;
        }
        else if (max(m, n) % 4 > 1) {
            c += 4;
        }
        return c;
    }
// Ðoi voi truong hop chung, chi can in
     // mot nua tong so khoi
    else {
        return (((m * n) + 1) / 2);
    }
}
int main()
{
	//tao ban co m la dong n la cot
    int m = 1, n = 4;
  
	printf("co bao nhieu con ma tren ban co :%d",max_knight(m, n));  
    return 0;
}
