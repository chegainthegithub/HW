#include <iostream>
#include <cmath>
using namespace std;

int  main()
{
	int m[10];
	for (int i = 0; i < 10; i++)
	{
		m[i] = rand() % 100;
		cout << m[i] << "  ";
	}
	cout << endl;
	for (int i = 1; i < 10; i++)
	{
		if (m[i] < m[i - 1])
			while (m[i] < m[i - 1])
				swap(m[i], m[i - 1]);
		cout << m[i] << "  ";
	}
	cout << endl;
	return 0;
}