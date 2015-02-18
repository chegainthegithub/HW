#include <iostream>
using namespace std;
char  *romans(int arab)
{
	int numers = 0;
	char *romannum = new char[15];
	int num10[7] = { 1, 5, 10, 50, 100, 500, 1000 };
	char numeralrom[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	int i = 0;
	int j = 0;
	for (i = 6; i >= 0; i--)
	{
		if (arab - num10[i] >= 0)
		{
			if ((i == 5) | (i == 3) | (i == 1))
				if ((arab - num10[i] >= 4 * num10[i - 1]) | (arab - num10[i]<0))
				{
				arab = arab - num10[i] - 4 * num10[i - 1];
				romannum[j] = numeralrom[i - 1];
				j++;
				romannum[j] = numeralrom[i + 1];
				j++;
				numers = numers + 2;
				}
			while (arab - num10[i] >= 0)
			{
				arab = arab - num10[i];
				numers++;
				romannum[j] = numeralrom[i];
				j++;
			}
		}
		else
			if (arab - 4 * num10[i - 1] >= 0)
			{
			arab = arab - 4 * num10[i - 1];
			romannum[j] = numeralrom[i - 1];
			j++;
			romannum[j] = numeralrom[i];
			j++;
			numers = numers + 2;
			}

	}
	return(romannum);
}
int length(int arab)
{
	int numers = 0;
	int num10[7] = { 1, 5, 10, 50, 100, 500, 1000 };
	char numeralrom[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	int i = 0;
	int j = 0;
	for (i = 6; i >= 0; i--)
	{
		if (arab - num10[i] >= 0)
		{
			if ((i == 5) | (i == 3) | (i == 1))
				if ((arab - num10[i] >= 4 * num10[i - 1]) | (arab - num10[i]<0))
				{
				arab = arab - num10[i] - 4 * num10[i - 1];
				j++;
				j++;
				numers = numers + 2;
				}
			while (arab - num10[i] >= 0)
			{
				arab = arab - num10[i];
				numers++;
				j++;
			}
		}
		else
			if (arab - 4 * num10[i - 1] >= 0)
			{
			arab = arab - 4 * num10[i - 1];
			j++;
			j++;
			numers = numers + 2;
			}
	}
	return(numers);
}
int main()
{
	int leng;
	int num;
	cin >> num;
	leng = length(num);
	char *roman = new char[leng];
	roman = romans(num);
	cout << endl;
	for (int i = 0; i < leng; i++)
		cout << roman[i];
	cout << endl;
}