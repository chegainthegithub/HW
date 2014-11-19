#include <iostream>
#include <cmath>
using namespace std;
float sinfunc(float x, int n)
{
	float result = 0;
	float sinus = x;
	for (int i = 1; i <= n; i++)
	{
		result = result + sin(sinus);
		sinus = sin(sinus);
	}
	return (result);
}
int main()
{
	float x;
	int n;
	cin >> x;
	cin >> n;
	cout << "result=" << sinfunc(x, n) << endl;

}