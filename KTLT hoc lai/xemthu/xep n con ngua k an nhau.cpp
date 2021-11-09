#include<stdio.h>
#include<string.h>
#include <conio.h>
/* m * n là kích thuoc bang K là so con ma duoc dat trên so dem là so luong giai pháp có the */

int m, n, k;
int dem = 0;
// tao bang M*N trong  

void TaoBco(char** board)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i] [j]= '_';
        }
    }
}
//Xuat ban co
void Xuatco(char** board)
{
	printf("DAT CON MA la K:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
        	printf("%c  ",board[i][j]);
        }
		printf("\n");
    }
}
// danh dau tat ca cac vi tri tan cong cua 1 con ma duoc dat tren bang co tai vi tri thu [i] va [j] 
void TanCong(int i, int j, char a,char** board)
{
	//cac dieu kien de dam bao rang cac khoi ranh duoc kiem tra nam ben trong bang
    if ((i + 2) < m && (j - 1) >= 0) {
        board[i + 2][j - 1] = a;
    }
    if ((i - 2) >= 0 && (j - 1) >= 0) {
        board[i - 2][j - 1] = a;
    }
    if ((i + 2) < m && (j + 1) < n) {
        board[i + 2][j + 1] = a;
    }
    if ((i - 2) >= 0 && (j + 1) < n) {
        board[i - 2][j + 1] = a;
    }
    if ((i + 1) < m && (j + 2) < n) {
        board[i + 1][j + 2] = a;
    }
    if ((i - 1) >= 0 && (j + 2) < n) {
        board[i - 1][j + 2] = a;
    }
    if ((i + 1) < m && (j - 2) >= 0) {
        board[i + 1][j - 2] = a;
    }
    if ((i - 1) >= 0 && (j - 2) >= 0) {
        board[i - 1][j - 2] = a;
    }
}
//dat con ma vao cac vi tri trong 
bool canPlace(int i, int j, char** board)
{
    if (board[i][j] == '_')
        return true;
    else
        return false;
}
//dat con ma o vi tri i j  va sao chep bang cu thanh bang moi de so sanh cac the co khong che
void place(int i, int j, char k, char a,char** board, char** new_board){
      for (int y = 0; y < m; y++) {
        for (int z = 0; z < n; z++) {
            new_board[y][z] = board[y][z];
        }
    }
    //dat con ma(K) o vi tri i j tren bang moi
      new_board[i][j] = k;
    //danh dau tat ca cac vi tri tan cong moi cua con ma tren ban co moi
      TanCong(i, j, a, new_board);
}
//chuc nang  nay la dat cac hiep sy len ban co de chung k tang cong nhau
void Try(int k, int sti, int stj, char** board){
	//neu khong con quan ma nao de dat thi hien thi bang va tang so luong
    if (k==0) {
    	
        Xuatco(board);
        dem++;
    }
    //Tao. vong lap de ktra tat ca cac vi tri tren ban co m*n
    else {
    	//moi gia tri co the gan voi i va j
          for (int i = sti; i < m; i++) {
            for (int j = stj; j < n; j++) {
            	//co the dat con ma o vi tri [i] [j] tren ban co trong 
                  if (canPlace(i, j, board)) {
                  	//tao 1 bang moi va dat con ma moi tren do
                      char** new_board = new char*[m];
                    for (int x = 0; x < m; x++) {
                        new_board[x] = new char[n];
                    }
                    place(i, j, 'K', 'A', board, new_board);
                    //goi ham de quy cho k-1 la cac con ma con sot lai
                      Try(k - 1, i, j, new_board);
                      for (int x = 0; x < m; x++) {
                      	//Xoa bo mach moi de giai phong bo nho
                        delete[] new_board[x];
                    }
                    delete[] new_board;
                }
            }
            stj = 0;
        }
    }
}  
int main()
{
    m = 2, n = 4, k =4;
    //tao bang co m*n  
    char** board = new char*[m];
    for (int i = 0; i < m; i++) {
        board[i] = new char[n];
    }  
    TaoBco(board);
    Try(k, 0, 0,board);
  	printf("\nTong so giai phap dat con ma :%d",dem);
  	printf("\n");
	int demconma=k;
	printf("co bao nhieu con ma tren ban co: %d",demconma);
    return 0;
}
