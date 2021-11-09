#include<stdio.h>
#define max
// ham tra ve so luong toi da
// CAC con ma duoc dat tren ban co
// b�n co sao cho c�c con ma khong an lan nhau m la dong n la cot
int max_knight(int m, int n)
{
// Kiem tra ch�o hoa g�c # 1
     // Neu h�ng hoac cot l� 1
    if (m == 1 || n == 1) {
		// Neu c�, th� cho con in tung so khoi
         // so l� gi� tri ti da cua h�ng hoac cat
        return max(m,n);
    }
// Kiem tra truong hop g�c # 2
     // Neu h�ng hoac cot l� 2
    else if (m == 2 || n == 2) {
	// Neu c�, th� chi con t�nh to�n
         // 2 h�ng hoac cot li�n tiep
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
// �oi voi truong hop chung, chi can in
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
