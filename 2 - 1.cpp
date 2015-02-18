##include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
void randomize(float *arr, int length, int bot, int top)
{
	srand(time(0));
	for (int i = 0; i < length; i++)
	{
		int b = rand();
		if (b % 2 == 0)
			arr[i] = (rand()) % (bot - top) + bot;
		if (b % 2 == 1)
			arr[i] = (rand()) % (bot - top) + 1.0 / rand() + bot;
	}
}
float aver(float *arr, int length)
{
	float aversum = 0;
	for (int i = 0; i < length; i++)
		aversum = aversum + arr[i];
	aversum = aversum / (length + 0.0);
	return(aversum);
}
int flows(float *arr, int length)
{
	int counter = 0;
	for (int i = 1; i < length - 1; i++)
	{
		if ((arr[i]>arr[i - 1]) && (arr[i] > arr[i + 1]))
			counter = counter + 1;
		if ((arr[i]<arr[i - 1]) && (arr[i]<arr[i + 1]))
			counter = counter + 1;
	}
	counter = counter + 1;
	return(counter);
}
void output(float *arr, int length, int number, float aversum)
{
	for (int i = 0; i < length; i++)
		cout << "arr[" << i << "] = " << arr[i] << endl;
	cout << "average sum = " << aversum << endl;
	cout << "number of flows = " << number;
}
int main()
{
	int length;
	cin >> length;
	float *arr1 = new float[length];
	randomize(arr1, length, 0, 23);
	output(arr1, length, flows(arr1, length), aver(arr1, length));
	delete[]arr1;
	cout << endl;
	cout << "========================" << endl;
	cin >> length;
	float *arr2 = new float[length];
	randomize(arr2, length, 50, 59);
	output(arr2, length, flows(arr2, length), aver(arr2, length));
	delete[]arr2;
	cout << endl;
	cout << "========================" << endl;
	cin >> length;
	float *arr3 = new float[length];
	randomize(arr3, length, -7, 5);
	output(arr3, length, flows(arr3, length), aver(arr3, length));
	cout << endl;
	delete[]arr3;
	cout << "========================" << endl;
	return(0);
}