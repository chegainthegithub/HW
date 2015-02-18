#include <iostream>
using namespace std;
int main() {
	char p[13];
	char*pa = p;
	int a;
	int k = 0;
	cin >> a;
	if (a / 1000 > 0) {
		for (int i = 1; i <= a / 1000; ++i) {
			*pa = 'M';
			++pa;
			++k;
		}
	}
	if ((a / 100) % 10 > 0) {
		if ((a / 100) % 10 <= 3) {
			for (int i = 1; i <= (a / 100) % 10; ++i) {
				*pa = 'C';
				++pa;
				++k;
			}
		}
		if ((a / 100) % 10 == 4) {
			*pa = 'C';
			++pa;
			++k;
			*pa = 'D';
			++pa;
			++k;
		}
		if ((a / 100) % 10 == 5) {
			*pa = 'D';
			++pa;
			++k;
		}
		if (((a / 100) % 10 >= 6) && ((a / 100) % 10 <= 8)) {
			*pa = 'D';
			++pa;
			++k;
			for (int i = 6; i <= (a / 100) % 10; ++i) {
				*pa = 'C';
				++pa;
				++k;
			}
		}
		if ((a / 100) % 10 == 9) {
			*pa = 'C';
			++pa;
			++k;
			*pa = 'M';
			++pa;
			++k;
		}
	}
	if ((a / 10) % 10 > 0) {
		if ((a / 10) % 10 <= 3) {
			for (int i = 1; i <= (a / 10) % 10; ++i) {
				*pa = 'X';
				++pa;
				++k;
			}
		}
		if ((a / 10) % 10 == 4) {
			*pa = 'X';
			++pa;
			++k;
			*pa = 'L';
			++pa;
			++k;
		}
		if ((a / 10) % 10 == 5) {
			*pa = 'L';
			++pa;
			++k;
		}
		if (((a / 10) % 10 >= 6) && ((a / 10) % 10 <= 8)) {
			*pa = 'L';
			++pa;
			++k;
			for (int i = 6; i <= (a / 10) % 10; ++i) {
				*pa = 'X';
				++pa;
				++k;
			}
		}
		if ((a / 10) % 10 == 9) {
			*pa = 'X';
			++pa;
			++k;
			*pa = 'C';
			++pa;
			++k;
		}
	}
	if (a % 10 > 0) {
		if (a % 10 <= 3) {
			for (int i = 1; i <= a % 10; ++i) {
				*pa = 'I';
				++pa;
				++k;
			}
		}
		if (a % 10 == 4) {
			*pa = 'I';
			++pa;
			++k;
			*pa = 'V';
			++pa;
			++k;
		}
		if (a % 10 == 5) {
			*pa = 'V';
			++pa;
			++k;
		}
		if ((a % 10 >= 6) && (a % 10 <= 8)) {
			*pa = 'V';
			++pa;
			++k;
			for (int i = 6; i <= a % 10; ++i) {
				*pa = 'I';
				++pa;
				++k;
			}
		}
		if (a % 10 == 9) {
			*pa = 'I';
			++pa;
			++k;
			*pa = 'X';
			++pa;
			++k;
		}
	}
	for (int i = 0; i < k; ++i)
		cout << p[i];
	return 0;
}