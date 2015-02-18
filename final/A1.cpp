#include <iostream>
using namespace std;
int main() {
	int a = -1;
	int b = -1;
	int c = -1;
	int d = -1;
	int e = -1;
	int x = -1;
	int second1;
	int second2;
	int second3;
	while (!(a >= 0) || !(a <= 23)) {
		cout << "hour1 ";
		cin >> a;
	}
	while (!(b >= 0) || !(b <= 59)) {
		cout << "minute1 ";
		cin >> b;
	}
	while (!(c >= 0) || !(c <= 59)) {
		cout << "second1 ";
		cin >> c;
	}
	while (!(d >= 0) || !(d <= 23)) {
		cout << "hour2 ";
		cin >> d;
	}
	while (!(e >= 0) || !(e <= 59)) {
		cout << "minute2 ";
		cin >> e;
	}
	while (!(x >= 0) || !(x <= 59)) {
		cout << "second2 ";
		cin >> x;
	}
	second1 = 3600 * a + 60 * b + c;
	second2 = 3600 * d + 60 * e + x;
	if (second2 <= second1)
		second3 = second1 - second2;
	else
		second3 = second2 - second1;
	a = second3 / 3600;
	b = (second3 % 3600) / 60;
	c = ((second3 % 3600) % 60);
	cout << a << " hours " << b << " minutes " << c << " seconds ";
	return 0;
}