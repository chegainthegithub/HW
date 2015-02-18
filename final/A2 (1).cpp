#include <iostream>
using namespace std;
double sin(double x) {
	double	sin = x;
	double z = x;
	for (int i = 3; i <= 10000; i = i + 2) {
		z = z*((-1)*x*x) / (i*(i - 1));
		sin = sin + z;
	}
	return sin / 0.01*0.01;
}
double cos(double x) {
	double cos;
	cos = sqrt(1 - sin(x)*sin(x));
	return cos / 0.01*0.01;
}
double tg(double x) {
	double tg;
	tg = (sin(x)) / (cos(x));
	return tg / 0.01*0.01;
}
int main() {
	float z1;
	float z2;
	double x;
	cin >> x;
	z1 = (1 - 2 * sin(x)*sin(x)) / (1 + sin(2 * x));
	z2 = (1 - tg(x)) / (1 + tg(x));
	cout << "z1 = " << z1 << endl << "z2 = " << z2 << endl;
	return 0;
}