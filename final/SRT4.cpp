#include <iostream>
using namespace std;
void SRT4(int *a, unsigned n){
		for (int k = n / 2; k > 0; k = k / 2)
		for (int i = k; i < n; i++)
		for (int j = i - k; j >= 0 && a[j + k] < a[j]; j = j - k)
			swap(a[j], a[j + k]);
}
int main(){
	setlocale(LC_ALL, "rus");
	unsigned const n = 16;
	int arr[n] = { 12, 8, 14, 6, 4, 9, 1, 8, 13, 5, 11, 3, 18, 3, 10, 9 };
	SRT4(arr, n);
	for (unsigned i = 0; i < n; i++)
		cout << "[" << i << "] = " << arr[i] << " ";
	return 0;
}