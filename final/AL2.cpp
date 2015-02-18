#include <iostream>
#include <cmath>
#include <ñlocale>
using namespace std;
int main() {
	int n;
	double x, sum, z;
	setlocale(LC_ALL, "rus");
	cout << "ââåäèòå n " << endl;
	cin >> n;
	cout << "ââåäèòå x" << endl;
	cin >> x;
	z = x;
	sum = 0;
	for (int i = 1; i <= n; ++i) {
		z = sin(z);
		sum = sum + z;
	}
	cout << sum;
	return 0;
}