#include <iostream>
using namespace std;
int SRT6(int *arr, int find, unsigned n) {
	int mid, left = 0, right = n - 1;
	while (arr[left] <= find && arr[right] >= find) {
		mid = left + ((find - arr[left])*(right - left)) / (arr[right] - arr[left]);
		if (arr[mid]<find) left = mid + 1;
		else
		if (arr[mid]>find) right = mid - 1;
		else
			return mid;
	}
	if (arr[left] == find)
		return left;
	else
		return -1;
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
	cout << "Ќужно найти ";
	int find;
	cin >> find;
	int ans = SRT6(arr, find, n);
	delete[] arr;
	if (ans == -1) {
		cout << "Ёлемент не найден" << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}