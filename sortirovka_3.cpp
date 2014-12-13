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
			swap(m[i], m[i - d])
	d = d / 2;
	for (int i = 4; i < 8; i++)
		while (m[i] < m[i - d])
			swap(m[i], m[i - d]);
	for (int i = 0; i < 16; i++)
	{
		cout << m[i] << "  ";
	}
	cout << endl;
	return 0;
}