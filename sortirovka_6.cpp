#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int m[30];
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		m[i] = rand() % 100;
		cout << m[i] << "  ";
	}
	cout << endl;
	int sch=0;
	int d = 0;
	int u = 29;
	int x;
	cin >> x;
	while (m[d] < x && m[u] > toFind) {
		sch = sch + ceil((x - m[d]) * (u - d)) / (m[u] - m[d]);

		if (m[sch] < x)
			d = sch + 1;
		else if (m[sch] > x)
			u = sch - 1;
		else
			cout << sch << endl;
	}

	if (m[d] == x)
		cout << d << endl;
	else if (m[u] == x)
		cout << u << endl;
	else
		cout << "Not found" << endl;
	}
	return 0;
}