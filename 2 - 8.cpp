#include <iostream>
#include <cmath>
using namespace std;
void input(float *arr, unsigned int size)
{
	for (int i = 0; i < size; i++)
		cin >> arr[i];
}
void Treeconstr(float *a, unsigned int size)
{
	for (int i = 0; i < size; i++)
	{
		int n = i;
		for (int j = i / 2; j >= 0; j--)
			if (a[n]>a[j])
			{
			swap(a[n], a[j]);
			n = j;
			for (int k = 0; k < size; k++)
				cout << a[k] << " ";
			cout << endl;
			}
	}
}
void HeapSort(float *a, unsigned size)
{
	unsigned size2 = size - 1;
	for (int i = 0; i < size - 2; i++)
	{
		swap(a[0], a[size2]);
		size2 = size2 - 1;
		Treeconstr(a, size2);
	}
}

void calculate(float *arr,unsigned int size)
{
	Treeconstr(arr, size);
	HeapSort(arr, size);
}
float calculatemax(float *arr, unsigned int size)
{
	float max = arr[size-1] + arr[size-2] + arr[size-3];
	return(max);
}
float calculatemin(float *arr, unsigned int size)
{
	float min = arr[0] + arr[1] + arr[2];
	return(min);
}

int main()
{
	unsigned int size;
	cin >> size;
	float *arr = new float[size];
	input(arr, size);
	calculate(arr, size);
	calculatemin(arr, size);
	cout << "max sum = " << calculatemax(arr, size) << endl;
	cout << "min sum = " << calculatemin(arr, size) << endl;

}