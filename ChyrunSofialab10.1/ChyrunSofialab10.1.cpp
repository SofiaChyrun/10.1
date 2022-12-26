// ChyrunSofialab10.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_10_1.cpp
// < Чирун Софія >
// Лабораторна робота № 10.1
// Пошук символів у текстовому файл
// Варіант 18

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(char* fname)
{
	ofstream fout(fname);
	char ch;
	string s;
	do
	{
		cin.get();
		cin.sync();
		cout << "enter line: "; getline(cin, s);
		fout << s << endl;
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
int PrintTXT(char* fname, int line)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		line++;
		cout << s << endl;
	}
	return line;
}
int Count(const string s)
{
	int k = 0;
	size_t pos = 0;
	while ((pos = s.find('.', pos)) != -1)
	{
		pos++;
		k++;
	}
	return k;
}
size_t Count4PointTXT(string d, int number, int line)
{
	int i = 0;
	int k = 0, j = line, v = line;
	i = 0;
	if (number < 4)
	{
		int h;
		h = Count(d);
		cout << ". <4" << endl;
	}
	else
		for (int p = (int)size(d) - 1; p >= 0; p--) {
			if (d[p] == '.' && k < 4)
			{
				k++;
				j = p;
				i = v;
			}
			if (d[p] == '$') {
				v--;
			}
			if (k == 4)
			{
				int r = 0;
				for (int c = j; c >= 0; c--)
				{
					if (d[c] != '$')
					{
						r++;
					}
					else
					{
						j = r - 1;
						r = 0;
						break;
					}
				}
				cout << "Number i and j are " << endl;
				cout << i + 1 << "  " << j << endl;
				break;
			}
		}
	return number;

}

int ProcessTXT1(char* fname)
{
	ifstream fin(fname);
	string s, d;
	int k = 0, j = 0, l;
	while (getline(fin, s))
	{

		for (unsigned i = 0; i < s.length(); i++)
			if (s[i] == '.')
				k++;
		d = d + s + "$";
	}
	l = Count4PointTXT(d, k, j);
	return l;
}

int main()
{
	char fname[100];
	int number = 0, line = 0;
	cout << "enter file name 1: "; cin >> fname;
	cout << "Enter string with '. >=4':" << endl;
	CreateTXT(fname);
	line = PrintTXT(fname, 0);
	number = ProcessTXT1(fname);
	cout << "k(.) = " << number << endl << endl;
	return 0;
}
