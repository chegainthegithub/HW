#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char*argv[])
{
	setlocale(LC_ALL, "Russian");
	char c;
	int z = 0;
	int n = 0;
	int k = 0;
	fstream fs;
	fs.open(argv[1]);
	if (fs.is_open() == false)
		cout << "‘айл не открылс€!";
	else
	{
		while (fs.eof() == false)
		{
			fs.get(c);
			if (fs.eof() == true) break;
			++k;
		}
		fs.close();
		fs.open(argv[1]);
		char* ch = new char[k];
		for (int i = 0; i < k; ++i)
		{
			fs.get(ch[i]);
			//cout << "ch[" << i << "] = " << ch[i] << endl;
		}
		//cout << "k = " << k << endl;
		fs.close();
		for (int i = 0; i < k; i++)
		{
			if (ch[i] == '(') n++;
			if (ch[i] == ')') z++;
		}
		if (z != n)
		{
			cout << "¬ведите корректные данные." << endl;
			return(0);
		}
		int m1 = 0;
		for (int i = 0; i < k; i++)
		{
			if (ch[i] == '(')
			{
				m1++;
			}
			if (ch[i] == ')')
			{
				m1--;
			}
			if (m1 < 0)
			{
				cout << "¬ведите корректные данные." << endl;
				return(0);
			}
		}
		char s1[4] = { '{', '(', '[', '\0' };
		char s2[4] = { '}', ')', ']', '\0' };
		int j = 0, j1 = 0;
		bool a = 0, b = 0;
		for (int i = 0; i < k; i++)
		{
			if (ch[i] == '(')
			{
				if (a == 0)
				{
					j++;
					if (j == 3) j = 0;
				}
				ch[i] = s1[j];
				a = 0;
			}
			if (ch[i] == ')')
			{
				if (a == 1)
				{
					j--;
					if (j == -1) j = 2;
				}
				ch[i] = s2[j];
				a = 1;
			}
		}
		fs.open(argv[1], ios_base::out | ios_base::trunc);
		for (int i = 0; i < k; i++)
			fs << ch[i];
		fs.close();
	}
	return 0;
}