#include <iostream>
using namespace std;
void SRT2(int *arr, unsigned n){
	for (unsigned i = 1; i < n; i++) {
		unsigned j = 0;
		while (j < i && arr[j] >= arr[i]) {
			j++;
		}
		int temp = arr[i];
		for (unsigned e = i; e > j; e--) {
			arr[e] = arr[e - 1];
		}
		arr[j] = temp;
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
	SRT2(arr, n);
	for (unsigned i = 0; i < n; i++) {
		cout << "[" << i << "] = " << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}