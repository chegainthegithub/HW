#include <iostream>
using namespace std;
/*void quickSort(unsigned e, unsigned f, int *arr) {
	long i = e, j = f;
	int q = arr[(e + f) / 2];
	do {
		while (arr[i] < q) { i++; }
		while (q < arr[j]) { j--; }
		if (i <= j) {
			double temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (e < j){ quickSort(e, j, arr); }
	if (i < f){ quickSort(i, f, arr); }
}*/
void SRT2(int *arr, unsigned n){
	for (unsigned i = 1; i < n; i++)
	{
		unsigned j = 0;
		while (j < i && arr[j] <= arr[i])
		{
			j++;
		}
		int temp = arr[i];
		for (unsigned e = i; e > j; e--)
		{
			arr[e] = arr[e - 1];
		}
		arr[j] = temp;
	}
	return;
}
void SRT8(int *arr, unsigned n) {
	SRT2(arr, n);
	unsigned j = 0;
	for (unsigned i = 0; i < arr[n - 1]; i++) {
		if (i != arr[j]) {
			cout << i << " ";
		}
		else {
			j++;
		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	unsigned n;
	cout << "¬ведите количество элементов массива ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++) {
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	SRT8(arr, n);
	delete[] arr;
	return 0;
}