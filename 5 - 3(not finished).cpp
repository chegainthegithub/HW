#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int size;
	cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	int max_num;
	int sup;
	{
		max_num = 0;
		sup = arr[0];
		for (int j = 0; j < size; j++)
		{
			if (arr[j] > sup)
			{
				sup = arr[j];
				max_num = j;
			}
		}
		swap(arr[0],arr[max_num]);
	}
	cout << arr[0] << endl;
	int local = 1;
	for (int i = 1; i < size; i++)
	{
		int k = i;
		while (true)
		{
			k = k / 2;
			if (arr[i]>arr[k])
			{
				local = k;
			}
			else
			{
				swap(arr[i], arr[local]);
				i++;
				break;
			}
		}
	}
	for (int i = 0; i < size; i++)
		cout << "arr[" << i << "] is " << arr[i] << endl;
	return 0;
}