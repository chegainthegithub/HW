#include <iostream>
#include <clocale>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	double x;
	double p;
	cout << "введите точность слагаемых" << endl;
	cin >> x;
	double k = 1;
	double z = 0;
	double c = 1 / k;
	for (int i = 1; c > x; ++i) {
		c = 1 / k;
		if (i % 2 == 1)
			z = z + c;
		else
			z = z - c;
		k = k + 2;
	}
	cout << 4 * z << endl;
	return 0;
}