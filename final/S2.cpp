#include <iostream>
#include <clocale>
using namespace std;
int v10(char*pa, int s1, int s2, int k) {
	int c = 1;
	int z = 0;
	for (int i = 0; i < k - 1; ++i)
		c = c * s1;
	for (int j = 0; j < k; ++j) {
		if (pa[j] < 58) {
			z = z + c * (pa[j] - '0');
			c = c / s1;
		}
		else {
			z = z + c * (pa[j] - 55);
			c = c / s1;
		}
	}
	return z;
}
int vdr(char*pb, int s2, int z) {
	int a = 0;
	int i = 0;
	while (z > 0) {
		if (z % s2 < 10) {
			pb[i] = z % s2 + '0';
			z = z / s2;
			++i;
		}
		else {
			pb[i] = z % s2 + 55;
			z = z / s2;
			++i;
		}
	}
	return i;
}
int main() {
	setlocale(LC_ALL, "rus");
	int s1 = 0;
	int s2 = 0;
	int k = 0;
	int z = 0;
	char*pa = new char[];
	char*pk = new char[];
	cout << "¬ведите систему счислени€ вводимого числа от 2 до 16" << endl;
	cin >> s1;
	cout << "¬ведите систему счислени€ в которую нужно перевести данное число" << endl;
	cin >> s2;
	cout << "¬ведите число в данной системе счислени€" << endl;
	cin >> pa;
	char*pb = pa;
	while (*pb != '\0') {
		++k;
		++pb;
	}
	z = v10(pa, s1, s2, k);
	int c = 0;
	c = vdr(pk, s2, z);
	for (int i = c - 1; i >= 0; --i)
		cout << pk[i];
	return 0;
}