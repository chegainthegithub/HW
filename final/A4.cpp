#include <iostream>
using namespace std;
bool func(double x, double y) {
	if ((((y <= 0) && ((x + 1)*(x + 1) + y * y) <= 1)) || ((y <= 0) && ((x - 1)*(x - 1) + y * y <= 1)) || ((y >= 0) && (2 * x + 2 >= y) && (-2 * x + 2 >= y)))
		return true;
	else 
		return false;
}
int main() {
	double x;
	double y;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	cout << func(x, y);
	return 0;
}