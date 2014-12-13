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
	for (int i = 0; i < size; i++)
	{
		int k = i;
		for (int j = i-1; j >= 0; j--)
		{
			if (arr[k]>arr[j])
			{
				swap(arr[j], arr[k]);
				k--;
			}
			else break;
		}
	}
	for (int i = 0; i < size; i++)
		cout << "arr[" << i << "] is " << arr[i] << endl;
	return 0;
}