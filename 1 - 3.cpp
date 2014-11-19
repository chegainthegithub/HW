#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a == 0)
		cout << "x=" << -c / b << endl;
	else
		if (b*b - 4 * a*c >= 0)
		{
		cout << "x1=" << (-b - sqrt(b*b - 4 * a*c)) / (2 * a) << endl;
		cout << "x2=" << (-b + sqrt(b*b - 4 * a*c)) / (2 * a) << endl;
		}
		else
		{

			if (b != 0) 
				cout << "x1=" << (-b / (2 * a));
			cout << "-" << sqrt(abs(b*b - 4 * a*c)) / (2 * a) << "i" << endl;
			if (b != 0) cout << "x2=" << (-b / (2 * a));
			cout << "+" << sqrt(abs(b*b - 4 * a*c)) / (2 * a) << "i" << endl;
		}

	if ((a == b) && (b == c) && (c == 0))
		cout << "any x suits" << endl;
	if ((a == b)&&(b==0) && (c != 0))
		cout << "no x suits" << endl;
	return(0);
}