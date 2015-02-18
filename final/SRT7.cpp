#include <iostream>
using namespace std;
unsigned SRT7(int *arr, unsigned n) {
	unsigned ans = 0;
	for (unsigned i = 0; i < n; i++) {
		unsigned j = 0;
		for (; j < i; j++) {
			if (arr[i] == arr[j]) {
				break;
			}
		}
		if (i == j) {
			ans++;
		}
	}
	return ans;
}
int main(){
	setlocale(LC_ALL, "rus");
	unsigned n;
	cout << "Введите количество элементов массива ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++) {
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	n = SRT7(arr, n);
	cout << "Количество различных элементов " << n << endl;
	delete[] arr;
	return 0;
}