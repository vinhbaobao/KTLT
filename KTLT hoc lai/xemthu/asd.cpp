#include<iostream>
#include<conio.h>
#include<math.h>
#include<string.h>
using namespace std;
int _tmain(int argc, char* argv[])
{
	char s[20];
	int len;
	do
	{
		cout << " nhap chuoi ki tu : ";
		cin.getline(s, 50);
		cout << " chuoi vua nhap ";
		cout << "*" << s << "*" << endl;
		// tìm t? dài nh?t
		len = strlen(s);
		int a[100];
		int na = 0;
		if (s[0] != NULL && s[0] != 32){ // xét d? dài t? d?u tiên 	
			int dem = 1;
			for (int i = 1; i < len; i++)
			{
				if (s[i] != 32)
				{
					dem++;
				}
				else
					break;
			}
			a[na++] = dem;
		}
		for (int i = 1; i < len; i++) // xét d? dài nh?ng t? ti?p theo
		{
			if (s[i] != 32)
			{
				int dem = 1;
				for (int j = i + 1; j < len; j++)
				{
					if (s[j] != 32)
					{
						dem++;
					}
					else break;
				}
				a[na++] = dem;
			}
		}
		int max = a[0]; // tìm s? t? dài nh?t là bao nhiêu
		for (int i = 1; i < na; i++)
		{
			if (max < a[i])
			{
				max = a[i];
			}
		}
		if (s[0] != NULL &&s[0] != 32) // xét t? d?u tiên có thoã không 
		{
			int dem = 1;
			int min;
			for (int i = 1; i < len; i++)
			{
				if (s[i] != 32)
				{
					dem++;
				}
				else
				{
					min = i ;
					break;
				}
			}
			if (dem == max)
			{
				for (int j = 0; j <= min; j++)
					cout << s[j];
				cout << endl;
			}
		}
		for (int i = 1; i < len; i++) // xét nh?ng t? phía sau có tho? không 
		{
			int min;
			int dem = 0;
			if (s[i] != 32)
			{
				dem++;
				for (int j = i + 1; j < len; j++)
				{
					if (s[j] != 32)
						dem++;
					else
					{
						min = j;
						break;
					}
				}
			}
			if (dem == max)
			{
				for (int z = i; z < min-1; z++)
					cout << s[z];
				cout << endl;
			}
		}
	} while (_getch() != 27);
	return 0;
}




