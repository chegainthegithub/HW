#include <iostream>
#include <ctime>
#include <clocale>
using namespace std;
int main() {
	int z, x, v;
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int p = -8;
	cout << "¬ведите количество элементов 1 последовательности" << endl;
	cin >> z;
	cout << "¬ведите количество элементов 2 последовательности" << endl;
	cin >> x;
	cout << "¬ведите количество элементов 3 последовательнсоти" << endl;
	cin >> v;
	int*a = new int[z];
	int*b = new int[x];
	int*c = new int[v];
	float sra = 0;
	float srb = 0;
	float src = 0;
	int l = 0;
	for (int i = 0; i < z; ++i) {
		while (((p < 0) || (p > 23)))
			p = rand() % 100; \
			a[i] = p;
		p = -8;
	}
	for (int i = 0; i < x; ++i) {
		while ((p < 50) || (p > 59))
			p = rand() % 100;
		b[i] = p;
		p = -8;
	}
	for (int i = 0; i < v; ++i) {
		while ((p < -7) || (p > 5)) {
			++l;
			if (l % 2 == 0)
				p = rand() % 100;
			else
				p = (-1) * (rand() % 100);
		}
		c[i] = p;
		p = -8;
	}
	for (int i = 0; i < z; ++i)
		sra = (sra + a[i]);
	sra = sra / z;
	for (int i = 0; i < x; ++i)
		srb = (srb + b[i]);
	srb = srb / x;
	for (int i = 0; i < v; ++i)
		src = (src + c[i]);
	src = src / v;
	for (int i = 0; i < z; ++i)
		cout << a[i] << " ";
	cout << endl;
	for (int i = 0; i < x; ++i)
		cout << b[i] << " ";
	cout << endl;
	for (int i = 0; i < v; ++i)
		cout << c[i] << " ";
	cout << endl;
	cout << "среднее 1 последовательности  " << sra << endl;
	cout << "среднее 2 последовательности  " << srb << endl;
	cout << "среднее 3 последовательности  " << src << endl;
	int k;
	if (a[0] == a[1])
		k = 0;
	else
		k = 1;
	for (int i = 1; i < z - 1; ++i) {
		if (((a[i] >= a[i - 1]) && (a[i] > a[i + 1])) || ((a[i] <= a[i - 1]) && (a[i] < a[i + 1])))
			++k;
	}
	cout << " оличество монотонных подпоследовательностей в 1 последовательности " << k << endl;
	if (b[0] == b[1])
		k = 0;
	else
		k = 1;
	for (int i = 1; i < x - 1; ++i) {
		if (((b[i] >= b[i - 1]) && (b[i] > b[i + 1])) || ((b[i] <= b[i - 1]) && (b[i] < b[i + 1])))
			++k;
	}
	cout << " оличество монотонных подпоследовательностей в 2 последовательности " << k << endl;
	if (c[0] == c[1])
		k = 0;
	else
		k = 1;
	for (int i = 1; i < v - 1; ++i) {
		if (((c[i] >= c[i - 1]) && (c[i] > c[i + 1])) || ((c[i] <= c[i - 1]) && (c[i] < c[i + 1])))
			++k;
	}
	cout << " оличество монотонных подпоследовательностей в 3 последовательности " << k << endl;
	return 0;
}