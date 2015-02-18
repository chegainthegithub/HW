#include <iostream>
#include <string>
using namespace std;
int romannum(string numeral)
{
	int num10[7] = { 1, 5, 10, 50, 100, 500, 1000 };
	int summ = 0;
	char numeralrom[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	int nextnumeral = 0;
	for (int i = numeral.size() - 1; i >= 0; i--)
	{
		for (int k = 0; k < 7; k++)
		{
			if (numeral[i] == numeralrom[k])
			{
				if (nextnumeral > num10[k])
					summ = summ - num10[k];
				else summ = summ + num10[k];
				nextnumeral = num10[k];
			}
		}

	}
	cout << summ;
	return(0);
}
int main()
{
	string numeral;
	cin >> numeral;
	romannum(numeral);

}