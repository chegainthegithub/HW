#include <iostream>
using namespace std;
int *result()
{
	bool check = 1;
	int *res = new int [2];
	int counter, countermax, number, numbermax;
	numbermax = 0;
	countermax = 0;
	counter = 0;
	number = 0;
	char x;
	x = '1';
	cout << "input the string and end it with any symbol you want except 1 and 0" << endl;
	while (check != 0)
	{
		if ((x != '0') && (x != '1'))
		{
			if (counter > countermax)
			{
				countermax = counter-1;
				numbermax = number;
			}
			break;
		}
		number++;
		cin >> x;
		if (x == '1')
		{
			if (counter > countermax)
			{
				countermax = counter;
				numbermax = number;
			}
			counter = 0;
		}
		else
			counter++;
	}
	res[0] = numbermax - countermax;
	res[1] = countermax;
	return res;
}
int main()
{
	int *res = new int[2];
	res = result();
	if (res[1] == 0)
		cout << "no 0-s in the string" << endl;
	else
	{
		cout << res[0] << endl;
		cout << res[1] << endl;
	}
	return(0);
}