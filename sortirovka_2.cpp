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
	short x;
	short left;
	short right;
	short sred;
	for (short i = 1; i < n; i++)
		if (m[i - 1] > m[i])
		{
			x = m[i];
			left = 0;
			right = i - 1;
			do {
				sred = (left + right) / 2;
				if (m[sred] < x) 
					left = sred + 1;
				else  
					right = sred - 1;
			} while (left <= right);
			for (short j = i - 1; j >= left; j--)
			{
				m[j + 1] = m[j];
				m[left] = x;
			}
		}
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << "  ";
	}
	cout << endl;
	return 0;
}