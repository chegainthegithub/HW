//a2
#include <iostream>
#include <cmath>
using namespace std;
double func1(double a)
{
	return (cos(2 * a) / (1 - sin(2 * a)));
}
double func2(double a)
{
	return ((cos(a) - sin(a)) / (cos(a) + sin(a)));
}

int main()
{
	double a;
	cin >> a;
	cout << "(1 - sin^2(a))/(1-sin(2a))=" << func1(a)<<endl;
	cout << "(1-tg(a))/(1+tg(a))=" << func2(a) << endl;

}
