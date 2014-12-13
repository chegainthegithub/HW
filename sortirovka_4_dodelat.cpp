#include <iostream>
#include <cmath>
using namespace std;

int  main()
{
	int m[16];
	for (int i = 0; i < 16; i++)
	{
		m[i] = rand() % 100;
		cout << m[i] << "  ";
	}
	cout << endl;
	int d = 8;
	for (int i = 8; i < 16; i++)
		if (m[i] < m[i - d])
			swap(m[i], m[i - d]);
	for (int i = 0; i < 16; i++)
	{
		cout << m[i] << "  ";
	}
	cout << endl;
	d = d / 2;
	for (int i = 4; i < 8; i++)
	{
		for (int j = i; j < 16; j = j + d)
		{
			while (m[j] < m[j - d])
			{
				swap(m[j], m[j - d]);
				j = j - d;
			}
		}
	}
	for (int i = 0; i < 16; i++)
	{
		cout << m[i] << "  ";
	}
	cout << endl;
	d = d / 2;
	for (int i = 2; i < 4; i++)
	{
		for (int j = i; j < 16; j = j + d)
		{
			while (m[j] < m[j - d])
			{
				swap(m[j], m[j - d]);
				j = j - d;
			}
		}
	}
	for (int i = 0; i < 16; i++)
	{
		cout << m[i] << "  ";
	}
	cout << endl;
	d = d / 2;
	for (int i = 1; i < 2; i++)
	{
		for (int j = i; j < 16; j = j + d)
		{
			while (m[j] < m[j - d])
			{
				swap(m[j], m[j - d]);
				j = j - d;
			}
		}
	}
	for (int i = 0; i < 16; i++)
	{
		cout << m[i] << "  ";
	}
	cout << endl;
	return 0;
}