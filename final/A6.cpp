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
	cout << "������� ����� ������ ";
	cin >> d;
	cout << "������� ����� ������ ";
	cin >> m;
	if ((m == 1) || (m == 2))
		m = m + 10;
	else
		m = m - 2;
	cout << "������� ��� ";
	cin >> y;
	switch (func(d, m, y)) {
	case 1:
		cout << "�����������" << endl;
		break;
	case 2:
		cout << "�������" << endl;
		break;
	case 3:
		cout << "�����" << endl;
		break;
	case 4:
		cout << "�������" << endl;
		break;
	case 5:
		cout << "�������" << endl;
		break;
	case 6:
		cout << "�������" << endl;
		break;
	case 0:
		cout << "�����������" << endl;
		break;
	}
	return 0;
}