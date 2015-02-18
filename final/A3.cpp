#include <iostream>
using namespace std;
int main() {
	double A;
	double B;
	double C;
	double x1;
	double x2;
	double D;
	double re;
	double im;
	cout << "A*x*x+B*x+C=0" << endl;
	cout << "A=";
	cin >> A;
	cout << "B=";
	cin >> B;
	cout << "C=";
	cin >> C;
	D = B * B - 4 * A * C;
	if (D < 0) {
		re = (-B / (2 * A));
		im = (sqrt(-D) / (2 * A));
		cout << "x1=" << re << "+" << im << "*i" << endl;
		cout << "x2=" << re << "-" << im << "*i" << endl;
	}
	else {
		x1 = (-B + sqrt(D)) / (2 * A);
		x2 = (-B - sqrt(D)) / (2 * A);
		cout << "x1=" << x1 << endl << "x2=" << x2 << endl;
	}
	return 0;
}