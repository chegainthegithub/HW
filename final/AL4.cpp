#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	double z = 0;
	double x = 0;
	double c = -1;
	double dx;
	double E;
	double l = 1;
	int v = 1;
	double x1, x2;
	cout << "Введите x1";
	cin >> x1;
	cout << "Введите x2";
	cin >> x2;
	cout << "Введите шаг dx " << endl;
	cin >> dx;
	cout << "Введите точность Е" << endl;
	cin >> E;
	for (x1; x1 < x2; x1 = x1 + dx){
		for (int n = 0; abs(l) > E; ++n) {
			c = c*((-1)*(x1 - 1));
			z = z + c / (n + 1);
			l = c / (n + 1);
		}
		cout << "x=   " << x1 << "   " << z << endl;
		z = 0;
		c = -1;
		l = 1;
	}
	return 0;
}