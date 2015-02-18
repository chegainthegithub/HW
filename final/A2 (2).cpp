#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double z1, z2, x;
	cin >> x;
	z1 = (1 - 2 * sin(x)*sin(x)) / (1 + sin(2 * x));
	z2 = (1 - sin(x) / cos(x)) / (1 + sin(x) / cos(x));
	cout << "z1=" << z1 << endl << "z2=" << z2 << endl;
	return 0;
}