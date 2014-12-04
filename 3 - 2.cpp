#include <iostream>
using namespace std;
char abc[16] = { '0', '1', '2', '3', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
void any_any()
{
	int sum = 0;
	int sys1;
	int sys2;
	char num = ' ';
	cout << "sys1 = ";
	cin >> sys1;
	bool sign = 0;
	cout << "sys2 = ";
	cin >> sys2;
	cout << "input the numeral you want to translate with symbol '=' in the end pls ";
	while (num != '=')
	{
		cin >> num;
		if (num == '=')
			break;
		cout << num;
		if (num == '-')
			sign = 1;
		for (int i = 0; i < 16; i++)
			if (num == abc[i])
				sum = sum*sys1 + i;
	}
	cout << " in " << sys1 << " = ";
	if (sign == 1) cout << "-";
	cout << sum <<" in dex "<<" = ";
	int clone1 = sum;
	int size = 0;
	while (clone1 != 0)
	{
		clone1 = clone1 / sys2;
		size = size + 1;
	}
	char *result = new char[size];
	int i = 0;
	while (sum != 0)
	{
		for (int j = 0; j < 16; j++)
			if (sum % sys2 == j)
				result[size - 1 - i] = abc[j];
		i++;
		sum = sum / sys2;
	}
	if (sign == 1)
	cout << '-';
	for (int i = 0; i < size; i++)
		cout << result[i]; 
	cout << " in " << sys2 << endl;
}
int main()
{
	any_any();
	return(0);
}
