#include<iostream>
using namespace std;
// khai báo c?u trúc  1 cái node
struct node
{
    int data; // d? li?u c?a node ==> d? li?u mà node s? luu tr?
    struct node *pLeft; // node liên k?t bên trái c?a cây <=> cây con trái
    struct node *pRight; // node liên k?t bên ph?i c?a cây <=> cây con ph?i
};
typedef struct node NODE;
typedef NODE* TREE;
 
// kh?i t?o cây
void KhoiTaoCay(TREE &t)
{
    t = NULL; // cây r?ng
}
 
// hàm thêm ph?n t? x vào cây nh? phân
void ThemNodeVaoCay(TREE &t, int x)
{
    // n?u cây r?ng
    if (t == NULL)
    {
        NODE *p = new NODE; // kh?i t?o 1 cái node d? thêm vào cây
        p->data = x;// thêm d? li?u x vào data
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;// node p chính là node g?c <=> x chính là node g?c
    }
    else // cây có t?n t?i ph?n t?
    {
        // n?u ph?n t? thêm vào mà nh? hon node g?c ==> thêm nó vào bên trái
        if (t->data > x)
        {
            ThemNodeVaoCay(t->pLeft, x); // duy?t qua trái d? thêm ph?n t? x
        }
        else if (t->data < x) // n?u ph?n t? thêm vào mà l?n hon node g?c ==> thêm nó vào bên ph?i
        {
            ThemNodeVaoCay(t->pRight, x); // duy?t qua ph?i d? thêm ph?n t? x
        }
    }
}
 
// hàm xu?t cây nh? phân theo NLR
void Duyet_NLR(TREE t)
{ 
    // n?u cây còn ph?n t? thì ti?p t?c duy?t
    if (t != NULL)
    {
        cout << t->data << " "; // xu?t d? li?u trong node
        Duyet_NLR(t->pLeft); // duy?t qua trái
        Duyet_NLR(t->pRight); // duy?t qua ph?i
    }
}
 
// hàm xu?t cây nh? phân theo NRL
void Duyet_NRL(TREE t)
{
    // n?u cây còn ph?n t? thì ti?p t?c duy?t
    if (t != NULL)
    {
        cout << t->data << " "; // xu?t d? li?u trong node
        Duyet_NRL(t->pRight); // duy?t qua ph?i 
        Duyet_NRL(t->pLeft); // duy?t qua trái
    }
}
 
// hàm xu?t cây nh? phân theo LNR <=> xu?t ra các ph?n t? t? bé d?n l?n
void Duyet_LNR(TREE t)
{
    // n?u cây còn ph?n t? thì ti?p t?c duy?t
    if (t != NULL)
    {
        Duyet_LNR(t->pLeft); // duy?t qua trái
        cout << t->data << "  "; // xu?t giá tr? c?a node
        Duyet_LNR(t->pRight); // duy?t qua ph?i
    }
}
 
// hàm xu?t cây nh? phân theo RNL <=> xu?t ra các ph?n t? t? l?n d?n bé
void Duyet_RNL(TREE t)
{
    // n?u cây còn ph?n t? thì ti?p t?c duy?t
    if (t != NULL)
    {
        Duyet_RNL(t->pRight); // duy?t qua ph?i
        cout << t->data << "  "; // xu?t giá tr? c?a node
        Duyet_RNL(t->pLeft); // duy?t qua ph?i
    }
}
 
// hàm xu?t cây nh? phân theo LRN
void Duyet_LRN(TREE t)
{
    // n?u cây còn ph?n t? thì ti?p t?c duy?t
    if (t != NULL)
    {
        Duyet_LRN(t->pLeft); // duy?t qua trái
        Duyet_LRN(t->pRight); // duy?t qua ph?i
        cout << t->data << "  "; // xu?t giá tr? c?a node
    }
}
 
// hàm xu?t cây nh? phân theo RLN
void Duyet_RLN(TREE t)
{
    // n?u cây còn ph?n t? thì ti?p t?c duy?t
    if (t != NULL)
    {
        Duyet_RLN(t->pRight); // duy?t qua ph?i
        Duyet_RLN(t->pLeft); // duy?t qua trái
        cout << t->data << "  "; // xu?t giá tr? c?a node
    }
}
 
 
// hàm nh?p d? li?u
void Menu(TREE &t)
{
    while (true)
    {
        cout << "\n\n\t\t =========== MENU ===========";
        cout << "\n1. Nh?p d? li?u cho cây: ";
        cout << "\n2. Duy?t cây NLR";
        cout << "\n3. Duy?t cây NRL";
        cout << "\n4. Duy?t cây LNR";
        cout << "\n5. Duy?t cây RNL";
        cout << "\n6. Duy?t cây LRN";
        cout << "\n7. Duy?t cây RLN";
        cout << "\n0. Thoát";
        cout << "\n\n\t\t ============================";
 
        int luachon;
        cout << "\nNh?p l?a ch?n c?a b?n: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 7)
        {
            cout << "\nL?a ch?n không h?p l?";
        }
        else if (luachon == 1)
        {
            int x;
            cout << "\nNh?p s? nguyên x: ";
            cin >> x;
            ThemNodeVaoCay(t, x);
        }
        else if (luachon == 2)
        {
            cout << "\nDuy?t cây theo NLR\n";
            Duyet_NLR(t);
        }
        else if (luachon == 3)
        {
            cout << "\nDuy?t cây theo NRL\n";
            Duyet_NRL(t);
        }
        else if (luachon == 4)
        {
            cout << "\nDuy?t cây theo LNR\n";
            Duyet_LNR(t);
        }
        else if (luachon == 5)
        {
            cout << "\nDuy?t cây theo RNL\n";
            Duyet_RNL(t);
        }
        else if (luachon == 6)
        {
            cout << "\nDuy?t cây theo LRN\n";
            Duyet_LRN(t);
        }
        else if (luachon == 7)
        {
            cout << "\nDuy?t cây theo RLN\n";
            Duyet_RLN(t);
        }
        else
        {
            break;
        }
    }
}
 
int main()
{
    TREE t;
    KhoiTaoCay(t);
    Menu(t);
 
    cout<<"\n-------------------------------------\n";
  cout<<"Chuong trình này du?c dang t?i Freetuts.net";
}
