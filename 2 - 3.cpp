#include <iostream>
#include <cmath>
using namespace std;
double input()
{
	double x;
	cout << "input accuracy:";
	cin >> x;
	cout << endl;
	return (x);
}
double picalculator(double x)
{
	double sch = 1.0;
	double result = 1.0;
	for (double i = 3.0; (1.0 / i) >= x; i=i+2)
	{
		sch = sch*(-1);
		result = result + (sch / i);
		cout << result << endl;
	}
	result = result * 4;
	return (result);
}
double output(double x)
{
	cout << "pi = " << x << endl;
	return(x);
}
int main()
{
	output(picalculator(input()));
	return 0;
}