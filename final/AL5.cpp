#include <iostream>
#include <clocale>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	double k;
	double p;
	int g;
	int m;
	double x;
	int q;
	int A = 12;
	int r;
	double a;
	cout << "����� �������" << endl;
	cin >> k;
	cout << "������� �������" << endl;
	cin >> p;
	cout << "���� � �����" << endl;
	cin >> g;
	cout << "����� ������� ������� ������ �������������� ������� �� �������" << endl;
	cin >> m;
	a = (p / 100) + 1;
	double k1 = k;
	double n = 1;
	double b;
	double l;
	double h = 0;
	for (int j = 0; j < g - 1; ++j)
		n = n * a;
	b = n * k;
	int*pa = new int[g - 1];
	for (int i = 0; i < g; ++i) {
		q = A / m;
		pa[i] = q;
		r = A - m * q;
		if (q == pa[i - 1])
			A = A + r;
		else
			A = 12 + r;
	}
	for (int j = 0; j < g - 1; ++j)
		n = n * a;
	for (int j = 0; j < g; ++j) {
		l = n * pa[j];
		h = h + l;
		n = n / a;
	}
	x = b / h;
	for (int j = 0; j < g - 1; ++j) {
		k = (k - pa[j] * x) * a;
		cout << "����� " << j + 1 << " ���� �������� ��������� ������ � ������� " << k << " ������ " << " �� ��� " << k * (p / 100) << " ������ ������� �������" << endl;
	}
	cout << "���� ������� ������ " << m << " ������� ����� � ������� " << x << " ������" << endl << endl;
	cout << "���� ������ �������� ������ �������, ����� ������� ����� ������� " << x << " ������� �� ������ ������� ������ " << m << " �������" << endl;
	double x1;
	int g1 = 0;
	cin >> x1;
	if (x1 > x){
		while (k1 > 0) {
			k1 = (k1 - pa[g1] * x1) * a;
			++g1;
			if (k1 < 0)
				k1 = 0;
			cout << "����� " << g1 << " ���� �������� ��������� ������ � ������� " << k1 << " ������ " << k1 * (p / 100) << " ������ ������� �������" << endl;
		}
		cout << "���� ������� ������ " << m << " ������� ����� � ������� " << x1 << " ������" << endl;
	}
	return 0;
}