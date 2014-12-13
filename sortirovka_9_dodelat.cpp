#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	fstream fs1;
	fs1.open("test.txt");
	fstream fs2("out.txt", ios_base::out | ios_base::trunc);
	if (fs1.is_open() != true && fs2.is_open() != true)
		return 0;
	string c;
	int k = 0;
	while (true)
	{
		k++;
		getline(fs1, c);
		if (fs1.eof())
		{
			break;
		}
	}
	cout << "===>" << k << endl;
	fs1.close();
	fs1.clear();
	fs1.open("test.txt");
	string *m = new string[k+30];
	for (int i = 0; i < k; i++)
	{
		getline(fs1, m[i]);
	}
	cout << "+====================" << endl;
	for (int i = 1; i < k; i++)
	{
		int j = i;
		while (int(m[j][0]) < int(m[j - 1][0]))
		{
			swap(m[j], m[j - 1]);
			j--;
		}
	}
	for (int i = 1; i < k; i++)
		cout << m[i] << endl;
	for (int i = 0; i < k; i++)
		fs2 << m[i] << endl;
	fs1.close();
	fs2.close();
	cin.get();
	return 0;
}
