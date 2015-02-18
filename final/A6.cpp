#include <iostream>
#include <clocale>
using namespace std;
int func(int a, int b, int c) {
	int k = 0;
	k = (a + (13 * b - 1) / 5 + (c % 100) + (c % 100) / 4 + (c / 100) / 4 - 2 * (c / 100) + 777) % 7;
	return k;
}
int main(){
	setlocale(LC_ALL, "rus");
	int d, m, y;
	cout << "введите число месяца ";
	cin >> d;
	cout << "введите номер месяца ";
	cin >> m;
	if ((m == 1) || (m == 2))
		m = m + 10;
	else
		m = m - 2;
	cout << "введите год ";
	cin >> y;
	switch (func(d, m, y)) {
	case 1:
		cout << "Понедельник" << endl;
		break;
	case 2:
		cout << "Вторник" << endl;
		break;
	case 3:
		cout << "Среда" << endl;
		break;
	case 4:
		cout << "Четверг" << endl;
		break;
	case 5:
		cout << "Пятница" << endl;
		break;
	case 6:
		cout << "Суббота" << endl;
		break;
	case 0:
		cout << "Воскресенье" << endl;
		break;
	}
	return 0;
}