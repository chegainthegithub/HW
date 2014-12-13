#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

int  main()
{
	setlocale(LC_ALL, "Russian");
	int m[20];
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		m[i] = rand() % 100;
		cout << m[i] << "  ";
	}
	cout << endl;
	for (int j = 1; j < 20; j++)
	{
		while (m[j] > m[j - 1] && j != 0 )
		{
			swap(m[j], m[j - 1]);
			j = j - 1;			
		}
	}
	for (int i = 0; i < 20; i++)
	{
		cout << m[i] << "  ";
	}
	cout << endl;
	int k, ch;
	cout << "Добавь совпадающиt член" << endl;
	cout << "Сколько членов изменить: ";
	cin >> ch;
	for (int i = 1; i <= ch; i++)
	{
		cout << "Номер: ";
		cin >> k;
		cout << "Значение: ";
		cin >> m[k];
	}
	for (int i = 0; i < 20; i++)
	{
		int cov = 0;
		for (int j = i + 1; j < 20; j++)
			if (m[i] == m[j])
				cov = cov + 1;
		for (int l = i + 1; l <= i + cov; l++)
		{
			m[l] = rand() % 100;
			for (int p = 0; p < 20; p++)
				if (m[p] == m[l] && p != l)
				{
				m[l] = rand() % 100;
				p = -1;
				}
		}
	}
	for (int i = 0; i < 20; i++)
	{
		cout << m[i] << "  ";
	}
	cout << endl;
	for (int j = 1; j < 20; j++)
	{
		while (m[j] < m[j - 1])
		{
			swap(m[j], m[j - 1]);
			j = j - 1;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		cout << m[i] << "  ";
	}
	cout << endl;
	return 0;
}
