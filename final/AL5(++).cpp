#include <iostream>
#include <clocale>
using namespace std;
void AL5(unsigned k, float p, float g, unsigned m, float fast){
	double fraction = k / (g * 12) * m;
	double rest = k;
	if (fast < g && fast > 0)
	{
		fraction = k / (fast * 12) * m;
		cout << "�� ������ ��������� ������ �� ����� " << fast << " �����.\n ����������\n";
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
	cout << "����� ������� ";
	cin >> k;
	cout << "������� ������� ";
	cin >> p;
	cout << "���� ";
	cin >> g;
	cout << "������� ";
	cin >> m;
	cout << "������ ��������� �������?(0 if NO) �� ��� ";
	cin >> fast;
	AL5(k, p, g, m, fast);
	return;
}