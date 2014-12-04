#include <iostream>
#include <cmath>
using namespace std;
float ability(float pay, float kapital, int month, int years, float percent)   //рассчет достаточности суммы для погашения кредита в срок
{
	int local1 = years * 12 / month;
	float p1, p2 = 1.0 + percent *1.0/ 100.0;
	p1 = p2;
	float local2 = p2;                                                              
	for (int i = 1; i < local1; i++)
	{
		p1 = p1 * local2;
		p2 = p2 + p1;
	}
	if (pay < kapital*p1 / p2) return (0);
	if (pay >= kapital*p1 / p2) return (kapital*p1/p2);
}
void output(float pay, float kapital, int month, int years, float percent,float check)     //вывод вариантов (если не достаточна выплата,если выплата впритык,если больше)
{
	int loc = month;
	if (check == 0)
		cout << "the payment doesn't equal the amount of the loan" << endl;
	else
	{
		cout << "minimal payment is " << check << endl;
		while (kapital >0)
		{
			kapital = (kapital - pay)*(1 + percent*1.0 / 100);
			cout << month << " " << pay << endl;
			month = month + loc;
		}
	}
}
int main()
{
	int pay, month, years, percent, kapital;
	cout << "input first payment:";
	cin >> pay;
	cout << endl;
	cout << "input month: ";
	cin >> month;
	cout << endl;
	cout << "input amount of years: ";
	cin >> years;
	cout << endl;
	cout << "input percent: ";
	cin >> percent;
	cout << endl;
	cout << "input the amount of money: ";
	cin >> kapital;
	cout << endl;
	output(pay, kapital, month, years, percent, ability(pay, kapital, month, years, percent));
}

