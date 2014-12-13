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
	int min_num;
	int inf;
	for (int i = 0; i < size; i++)
	{
		min_num = i;
		inf = arr[i];
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < inf)
			{
				inf = arr[j];
				min_num = j;
			}
		}
		swap(arr[i], arr[min_num]);
	}
	for (int i = 0; i < size; i++)
		cout << "arr[" << i << "] is " << arr[i] << endl;
	return 0;
}