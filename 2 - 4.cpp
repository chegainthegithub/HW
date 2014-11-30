#include <iostream>
#include <cmath>
using namespace std;
float calculation(float x, float E)
{
	float sum = 0;
	float loc1 = 1;
	float loc2 = x - 1;
	float loc3 = loc2;
	float n = 0;
	while (abs(loc3) > abs(E))
	{
		if (x == 1)
			return 0;
		sum = sum + loc3;
		n = n + 1;
		loc1 = loc1 *(-1);
		loc2 = loc2*(x - 1);
		loc3 = (loc1*loc2) / (n + 1.0);
	}
	return sum;
}
int cycle()
{
	float x1, x2, E, dx;
	cin >> x1;
	cin >> x2;
	cin >> E;
	cin >> dx;
	while (x1 <= x2+dx)
	{
		cout << "f(" << x1 << ") = " << calculation(x1, E) << endl;
		x1 = x1 + dx;
	}
	return 0;
}
int main()
{
	cycle();
	return(0);
}