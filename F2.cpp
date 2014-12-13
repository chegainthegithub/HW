#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	fstream fs("F2.txt");
	if (fs.is_open() == false)
		cout << "Файл не открыт!" << endl;
	int n = 0; char c;
	while (true)
	{
		fs.get(c);
		if (fs.eof()) break;
		cout << c << endl;
		n++;
		/*
		int a = 0, n = 0, sum = 0;
	char *p = new char[a];
	char c;
	while (true) // 
	{
		fs.get(c);

		if (fs.eof()) break;
		cout << c << endl;

		n++;
	}
	*/
	}
	char *m = new char[n];
	fs.close();
	fstream fs1("F2.txt");
	for (int i = 0; i < n; i++)
	{
		fs1.get(m[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << "m[" << i << "] = " << m[i] << endl;
	}
	cout << "===========================================" << endl;
	for (int i = 0; i < n; i++)
	{
		if (m[i] >= 65 && m[i] <= 90)
			cout << char (m[i] + 32);
		if (m[i] >= 97 && m[i] <= 122)
			cout << char (m[i] - 32);
		if (m[i] == '0')
			cout << "Zero";
		if (m[i] == '1')
			cout << "One";
		if (m[i] == '2')
			cout << "Two";
		if (m[i] == '3')
			cout << "Three";
		if (m[i] == '4')
			cout << "Four";
		if (m[i] == '5')
			cout << "Five";
		if (m[i] == '6')
			cout << "Six";
		if (m[i] == '7')
			cout << "Seven";
		if (m[i] == '8')
			cout << "Eight";
		if (m[i] == '9')
			cout << "Nine";
		else
			cout << m[i];
	}



	fs1.close();
	return 0;
}