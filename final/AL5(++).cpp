#include <iostream>
#include <clocale>
using namespace std;
void AL5(unsigned k, float p, float g, unsigned m, float fast){
	double fraction = k / (g * 12) * m;
	double rest = k;
	if (fast < g && fast > 0)
	{
		fraction = k / (fast * 12) * m;
		cout << "Вы хотите выплатить кредит за время " << fast << " годов.\n перерасчет\n";
	}
	while (rest > fraction - 1)
	{
		cout <</* "rest=" << rest << " | " <<*/ fraction + rest * m * 30 * p / 36000 /*<< " " << rest * m * 30 * p / 36500 */ << endl;
		rest -= fraction;
	}
	return;
}
int main(){
	setlocale(LC_ALL, "rus");
	unsigned k, m;
	float p, g, fast;
	cout << "Сумма кредита ";
	cin >> k;
	cout << "Процент кредита ";
	cin >> p;
	cout << "Года ";
	cin >> g;
	cout << "Месяцев ";
	cin >> m;
	cout << "Хотите выплатить быстрее?(0 if NO) За лет ";
	cin >> fast;
	AL5(k, p, g, m, fast);
	return;
}