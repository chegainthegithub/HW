#include <iostream>
using namespace std;

void SRT1(int *arr, unsigned n) {
	for (unsigned i = 0; i < n - 1; i++) {
		int min = arr[i], mini = i;
		for (unsigned j = i + 1; j < n; j++) {
			if (arr[j] < min) {
				min = arr[j];
				mini = j;
			}
		}
		if (mini != i) 
			swap(arr[i], arr[mini]);
	}
}
int main(){
	setlocale(LC_ALL, "rus");
	unsigned n;
	cout << "¬ведите количество элементов массива ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++) {
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	SRT1(arr, n);
	for (unsigned i = 0; i < n; i++) {
		cout << "[" << i << "] = " << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}