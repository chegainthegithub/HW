#include <iostream>
#include <clocale>
using namespace std;
int func1(int m) {
	int k = 0;
	int j = 0;
	int const n = 20;
	int a[n];
	for (int i = 0; i < n; ++i)
		a[i] = i + 1;
	int l = 0;
	while (k != n - 1) {
		for (j = 0; j < m; ++j) {
			if (a[l % 20] == 0)
				--j;
			if (j == m - 1) {
				a[l % 20] = 0;
				++k;
			}
			++l;
		}
	}
	int x;
	for (int i = 0; i < n; ++i)
	if (a[i] != 0)
		x = a[i];
	return x;
}
int main() {
	int const n = 20;
	int a[n];
	int k = 0;
	setlocale(LC_ALL, "rus");
	int m;
	cout << "¬ведите число от 1 до 20" << endl;
	cin >> m;
	cout << func1(m) << " номер оставшегос€ Ђв живыхї человека" << endl;
	for (int m = 2; m < n; ++m){
		int k = 0;
		int j = 0;
		int const n = 20;
		int a[n];
		for (int i = 0; i < n; ++i)
			a[i] = i + 1;
		int l = 0;
		while (k != n - 1) {
			for (j = 0; j < m; ++j) {
				if (a[l % 20] == 0)
					--j;
				if (j == m - 1) {
					a[l % 20] = 0;
					++k;
				}
				++l;
			}
		}
		int x;
		for (int i = 0; i < n; ++i)
		if (a[i] != 0)
			x = a[i];
		if (x == 1)
			cout << m << "  такое m>1, при котором Ђв живыхї останетс€ первый." << endl;
	}
	return 0;
}