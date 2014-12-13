#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int m[30];
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		m[i] = rand() % 100;
		cout << m[i] << "  ";
	}
	cout << endl;
	for (int j = 1; j < 30; j++)
	{
		while (m[j] < m[j - 1])
		{
			swap(m[j], m[j - 1]);
			j = j - 1;
		}
	}
	for (int i = 0; i < 30; i++)
	{
		cout << m[i] << "  ";
	}
	cout << endl;
	int num = 0;
	for (int i = 0; i < 30; i++)
		if (m[i] >= 1)
		{
			num = i;
			break;
		}
	int k = 0;
	if (m[num] > 1)
		int k = m[num] - 1;
	for (int i = num + 1; i < 30; i++)
		if (m[i] != m[i-1])
			k = k + m[i] - m[i - 1] - 1;
	cout << k << endl;
	return 0;
}