#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	fstream fs("A2.cpp");
	if (fs.is_open() == false)
		cout << "Файл не открыт!" << endl;
	int n = 0, q = 0;
	char c;
	while (true)
	{
		fs.get(c);
		if (fs.eof())
			break;
		n++;
	}
	cout << "n = " << n << endl;
	char *m = new char[n];
	fs.close();
	fstream fs1("A2.cpp");
	for (int i = 0; i < n; i++)
	{
		fs1.get(m[i]);
		//cout << "m[" << i << "] = " << m[i] << endl;
	}
	cout << "n = " << n << endl;
	fs1.close();
	fstream fs2("A2.cpp", ios_base::out | ios_base::trunc);
	for (int i = 0; i < n - 1; i++)
	{
		if (m[i] == '/' && (m[i + 1] == '/' || m[i + 1] == '*'))
		{
			q = i;
			//cout << 4 << endl;
			if (m[i + 1] == '/')
			{
				while (m[q] != '\n')
					q++;
				q--;
			}
			else if (m[i + 1] == '*')
			{
				while (m[q] != '*' || m[q + 1] != '/')
					q++;
				q++;
			}
			for (int j = i; j <= q; j++)
			{
				if (m[j] = '\n')
					
				m[j] = ' ';
				//cout << "m[" << j << "] = " << m[j] << endl;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		//cout << "m[" << i << "] = " << m[i] << endl;
		fs2 << m[i];		
	}
	fs2.close();
	return 0;
}