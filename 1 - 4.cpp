#include <iostream>
using namespace std;
int main()
{
	double x, y;
	cin >> x;
	cin >> y;
	if (y <= 0)
		if (x <= 0)
			if ((x + 1)*(x + 1) + (y*y) <= 1)
				cout << "yes" << endl;
			else cout << "no" << endl;
		else
			if (((x - 1)*(x - 1) + (y*y)) <= 1)
				cout << "yes" << endl;
			else cout << "no" << endl;
	else
		if (y > 2)
			cout << "no" << endl;
		else
			if (x <= 0)
				if (y <= 2 * x + 2)
					cout << "yes" << endl;
				else cout << "no" << endl;
			else
				if (y <= 2 - 2 * x)
					cout << "yes" << endl;
				else cout << "no" << endl;
}