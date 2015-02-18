#include <iostream>;
using namespace std;
void SRT3(int *arr, unsigned n){
	for (unsigned i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			unsigned e = 0, f = i - 1;
			do {
				if (arr[(e + f) / 2] >= arr[i])
					f = (e + f) / 2;
				else
					e = (e + f) / 2;
			} while (e + 1 != f && e != f);
			int temp = arr[i];
			for (unsigned ti = i; ti > f; ti--)
				arr[ti] = arr[ti - 1];
			arr[f] = temp;
		}
	}
}
int main(){
	setlocale(LC_ALL, "rus");
	unsigned n;
	cout << "Введите количество элементов ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	SRT3(arr, n);
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = " << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}