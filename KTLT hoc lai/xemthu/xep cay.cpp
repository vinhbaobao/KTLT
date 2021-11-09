#include<iostream>
using namespace std;
// khai b�o c?u tr�c  1 c�i node
struct node
{
    int data; // d? li?u c?a node ==> d? li?u m� node s? luu tr?
    struct node *pLeft; // node li�n k?t b�n tr�i c?a c�y <=> c�y con tr�i
    struct node *pRight; // node li�n k?t b�n ph?i c?a c�y <=> c�y con ph?i
};
typedef struct node NODE;
typedef NODE* TREE;
 
// kh?i t?o c�y
void KhoiTaoCay(TREE &t)
{
    t = NULL; // c�y r?ng
}
 
// h�m th�m ph?n t? x v�o c�y nh? ph�n
void ThemNodeVaoCay(TREE &t, int x)
{
    // n?u c�y r?ng
    if (t == NULL)
    {
        NODE *p = new NODE; // kh?i t?o 1 c�i node d? th�m v�o c�y
        p->data = x;// th�m d? li?u x v�o data
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;// node p ch�nh l� node g?c <=> x ch�nh l� node g?c
    }
    else // c�y c� t?n t?i ph?n t?
    {
        // n?u ph?n t? th�m v�o m� nh? hon node g?c ==> th�m n� v�o b�n tr�i
        if (t->data > x)
        {
            ThemNodeVaoCay(t->pLeft, x); // duy?t qua tr�i d? th�m ph?n t? x
        }
        else if (t->data < x) // n?u ph?n t? th�m v�o m� l?n hon node g?c ==> th�m n� v�o b�n ph?i
        {
            ThemNodeVaoCay(t->pRight, x); // duy?t qua ph?i d? th�m ph?n t? x
        }
    }
}
 
// h�m xu?t c�y nh? ph�n theo NLR
void Duyet_NLR(TREE t)
{ 
    // n?u c�y c�n ph?n t? th� ti?p t?c duy?t
    if (t != NULL)
    {
        cout << t->data << " "; // xu?t d? li?u trong node
        Duyet_NLR(t->pLeft); // duy?t qua tr�i
        Duyet_NLR(t->pRight); // duy?t qua ph?i
    }
}
 
// h�m xu?t c�y nh? ph�n theo NRL
void Duyet_NRL(TREE t)
{
    // n?u c�y c�n ph?n t? th� ti?p t?c duy?t
    if (t != NULL)
    {
        cout << t->data << " "; // xu?t d? li?u trong node
        Duyet_NRL(t->pRight); // duy?t qua ph?i 
        Duyet_NRL(t->pLeft); // duy?t qua tr�i
    }
}
 
// h�m xu?t c�y nh? ph�n theo LNR <=> xu?t ra c�c ph?n t? t? b� d?n l?n
void Duyet_LNR(TREE t)
{
    // n?u c�y c�n ph?n t? th� ti?p t?c duy?t
    if (t != NULL)
    {
        Duyet_LNR(t->pLeft); // duy?t qua tr�i
        cout << t->data << "  "; // xu?t gi� tr? c?a node
        Duyet_LNR(t->pRight); // duy?t qua ph?i
    }
}
 
// h�m xu?t c�y nh? ph�n theo RNL <=> xu?t ra c�c ph?n t? t? l?n d?n b�
void Duyet_RNL(TREE t)
{
    // n?u c�y c�n ph?n t? th� ti?p t?c duy?t
    if (t != NULL)
    {
        Duyet_RNL(t->pRight); // duy?t qua ph?i
        cout << t->data << "  "; // xu?t gi� tr? c?a node
        Duyet_RNL(t->pLeft); // duy?t qua ph?i
    }
}
 
// h�m xu?t c�y nh? ph�n theo LRN
void Duyet_LRN(TREE t)
{
    // n?u c�y c�n ph?n t? th� ti?p t?c duy?t
    if (t != NULL)
    {
        Duyet_LRN(t->pLeft); // duy?t qua tr�i
        Duyet_LRN(t->pRight); // duy?t qua ph?i
        cout << t->data << "  "; // xu?t gi� tr? c?a node
    }
}
 
// h�m xu?t c�y nh? ph�n theo RLN
void Duyet_RLN(TREE t)
{
    // n?u c�y c�n ph?n t? th� ti?p t?c duy?t
    if (t != NULL)
    {
        Duyet_RLN(t->pRight); // duy?t qua ph?i
        Duyet_RLN(t->pLeft); // duy?t qua tr�i
        cout << t->data << "  "; // xu?t gi� tr? c?a node
    }
}
 
 
// h�m nh?p d? li?u
void Menu(TREE &t)
{
    while (true)
    {
        cout << "\n\n\t\t =========== MENU ===========";
        cout << "\n1. Nh?p d? li?u cho c�y: ";
        cout << "\n2. Duy?t c�y NLR";
        cout << "\n3. Duy?t c�y NRL";
        cout << "\n4. Duy?t c�y LNR";
        cout << "\n5. Duy?t c�y RNL";
        cout << "\n6. Duy?t c�y LRN";
        cout << "\n7. Duy?t c�y RLN";
        cout << "\n0. Tho�t";
        cout << "\n\n\t\t ============================";
 
        int luachon;
        cout << "\nNh?p l?a ch?n c?a b?n: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 7)
        {
            cout << "\nL?a ch?n kh�ng h?p l?";
        }
        else if (luachon == 1)
        {
            int x;
            cout << "\nNh?p s? nguy�n x: ";
            cin >> x;
            ThemNodeVaoCay(t, x);
        }
        else if (luachon == 2)
        {
            cout << "\nDuy?t c�y theo NLR\n";
            Duyet_NLR(t);
        }
        else if (luachon == 3)
        {
            cout << "\nDuy?t c�y theo NRL\n";
            Duyet_NRL(t);
        }
        else if (luachon == 4)
        {
            cout << "\nDuy?t c�y theo LNR\n";
            Duyet_LNR(t);
        }
        else if (luachon == 5)
        {
            cout << "\nDuy?t c�y theo RNL\n";
            Duyet_RNL(t);
        }
        else if (luachon == 6)
        {
            cout << "\nDuy?t c�y theo LRN\n";
            Duyet_LRN(t);
        }
        else if (luachon == 7)
        {
            cout << "\nDuy?t c�y theo RLN\n";
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
  cout<<"Chuong tr�nh n�y du?c dang t?i Freetuts.net";
}
