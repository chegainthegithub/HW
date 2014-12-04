#include <iostream>
#include <cmath>
using namespace std;
int array[20];
int moisej(int step)
{
	for (int i = 0; i < 20; i++)
		array[i] = i+1;
	int man = 0;
	int dead = 0;
	for (int i = 0; i < 19; i++)
	{
		array[(man + step) % (20 - dead)] = -1;
		for (int j = (man + step) % (20 - dead); j < 19; j++)
			swap(array[j], array[j + 1]);
		cout << "(" << man << ") " << "(" << dead << ") ";
		man = (man + step) % (20 - dead);
		dead++;
		for (int k = 0; k < 20; k++)
			cout << array[k] << " ";
		cout << endl;
		cout << "====================" << endl;
	}
	cout << array[0]  << endl;
	return(0);
}
int main()
{
	int step;
	cin >> step;
	moisej(step);
	return(0);
}