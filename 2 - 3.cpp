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
	int sch = 1;
	double result = 1;
	for (int i = 3; (1/i) >= x; i + 2)
	{
		sch = sch*(-1);
		result = result + (sch/i);
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