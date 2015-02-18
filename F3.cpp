#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string f(int x)
{
	string s = "";
	if (x / 1000 > 0) //тысячи
	{
		for (int i = 0; i < x / 1000; i++) s = s + "M";
		x = x % 1000;
	}
	if (x / 100 > 0) //сотни
	{
		if (x / 100 < 5)
		{
			if (x / 100 < 4)
			{
				for (int i = 0; i < x / 100; i++) s = s + "C";
			}
			else s = s + "CD";
		}
		else
		{
			if (x / 100 > 5 && x / 100 < 9)
			{
				s = s + "D";
				for (int i = 0; i < (x / 100) - 5; i++) s = s + "C";
			}
			else s = s + "CM";
		}
		x = x % 100;
	}
	if (x / 10 > 0) //десятки
	{
		if (x / 10 < 5)
		{
			if (x / 10 < 4)
			{
				for (int i = 0; i < x / 10; i++) s = s + "X";
			}
			else s = s + "XL";
		}
		else
		{
			if (x / 10 > 5 && x / 10 < 9)
			{
				s = s + "L";
				for (int i = 0; i < (x / 10) - 5; i++) s = s + "X";
			}
			else s = s + "XC";
		}
		x = x % 10;
	}
	if (x > 0) // единицы
	{
		if (x < 5)
		{
			if (x < 4)
			{
				for (int i = 0; i < x; i++) s = s + "I";
			}
			else s = s + "IV";
		}
		else
		{
			if (x > 5 && x < 9)
			{
				s = s + "V";
				for (int i = 0; i < x - 5; i++) s = s + "I";
			}
			else s = s + "IX";
		}
	}
	return s;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	fstream fs;
	fs.open("F1.txt");
	if (fs.is_open() == false)
		cout << "not open";
	else
	{
		char c = ' ';
		int n = 0;
		while (fs.eof() == false)
		{
			fs.get(c);
			if (fs.eof() == true) break;
			n++;
		}
		if (n >= 10)
		{
			fs.close();
			fs.open("F1.txt");
			char* ch = new char[n];
			int i = 0, k = 0, d = 0;
			string str = "";
			bool flag = true;

				for (i = 0; i < n; i++)
				{
					fs.get(ch[i]);
					cout << ch[i];
					if (i >= 9)
					{
						if (ch[i - 9] >= 48 && ch[i - 9] <= 57 && ch[i - 8] >= 48 && ch[i - 8] <= 57 && ch[i - 7] == '.' &&
							ch[i - 6] >= 48 && ch[i - 6] <= 57 && ch[i - 5] >= 48 && ch[i - 5] <= 57 && ch[i - 4] == '.' &&
							ch[i - 3] >= 48 && ch[i - 3] <= 57 && ch[i - 2] >= 48 && ch[i - 2] <= 57 && ch[i - 1] >= 48 &&
							ch[i - 1] <= 57 && ch[i] >= 48 && ch[i] <= 57)
						{
							k = (ch[i - 3] - '0') * 1000 + (ch[i - 2] - '0') * 100 + (ch[i - 1] - '0') * 10 + (ch[i] - '0');
							str = f(k);
							d = d + str.length() - 4;
						}
					}
				}
				int m = 0;
				char* ch1 = new char[n + d];
				int sm = 0,j=0; // sm - смещение
				for (i = 0; i < n; i++)
				{
					ch1[i+sm] = ch[i];
					if (i >= 9 && ch[i - 9] >= 48 && ch[i - 9] <= 57 && ch[i - 8] >= 48 && ch[i - 8] <= 57 && ch[i - 7] == '.' &&
						ch[i - 6] >= 48 && ch[i - 6] <= 57 && ch[i - 5] >= 48 && ch[i - 5] <= 57 && ch[i - 4] == '.' &&
						ch[i - 3] >= 48 && ch[i - 3] <= 57 && ch[i - 2] >= 48 && ch[i - 2] <= 57 && ch[i - 1] >= 48 &&
						ch[i - 1] <= 57 && ch[i] >= 48 && ch[i] <= 57)
					{
						k = (ch[i - 3] - '0') * 1000 + (ch[i - 2] - '0') * 100 + (ch[i - 1] - '0') * 10 + (ch[i] - '0');
						str = f(k);
						
						m = -3;
						for (j = 0; j < str.length(); j++)
						{
							ch1[i + m +sm] = str[j];
							m++;
						}
						sm = sm + str.length() - 4;
					}
				}
			cout << endl;
			delete(ch);
			fs.close();
			fs.open("F1.txt", ios_base::out);

			for (i = 0; i < n+d; i++)
				fs << ch1[i];
			fs.close();
			delete(ch1);
		}
	}
	return 0;
}