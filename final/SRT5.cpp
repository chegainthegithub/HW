#include <iostream>
using namespace std;
unsigned SRT5(int *arr, unsigned n){
	int *temparr = new int[n];
	unsigned i = 1, k = 0;
	temparr[0] = arr[0];
	while (i < n) {
		if (arr[i] < temparr[k]) {
			k++;
			temparr[k] = arr[i];
		}
		i++;
	}
	++k;
	for (unsigned j = 0; j < k; j++) {
		arr[j] = temparr[j];
	}
	for (unsigned j = k; j < n; j++) {
		arr[j] = 0;
	}
	delete[] temparr;
	return k;
}
int main(){
	setlocale(LC_ALL, "rus");
	unsigned n;
	cout << "¬ведите количество элементов массива ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++){
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	n = SRT5(arr, n);
	for (unsigned i = 0; i < n; i++){
		cout << "[" << i << "] = " << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}