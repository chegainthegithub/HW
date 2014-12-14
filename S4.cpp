#include <iostream>
#include <clocale>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	char*s = new char[]; 
	int n = 0;
	int	c = 0;
	int	c1;
	int i;
	int a;
	int k;
	cout << "¬ведите римское число" << endl;
	cin >> s;
	k = strlen(s);
	for (i = 0; i < k; ++i) {
		c1 = c;
		if (s[i] == 'I')
			c = 1;
		if (s[i] == 'V')
			c = 5;
		if (s[i] == 'X')
			c = 10;
		if (s[i] == 'L')
			c = 50;
		if (s[i] == 'C')
			c = 100;
		if (s[i] == 'D')
			c = 500;
		if (s[i] == 'M')
			c = 1000;
		if (c > c1)
			a = -2 * c1;
		else
			a = 0;
		n = n + a + c;
	}
	cout << n;
	return 0;
}