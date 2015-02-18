#include <iostream>
#include <string>
using namespace std;
int dec(string n, int osn){
	int a = 0;
	int t = 1;
	for (int i = n.length(); i > 0;){
		--i;
		int c = 0;
		if (n[i] > '0'&n[i] < '9')c = n[i] - '0';
		else{
			if (n[i] == 'A')c = 10;
			if (n[i] == 'B')c = 11;
			if (n[i] == 'C')c = 12;
			if (n[i] == 'D')c = 13;
			if (n[i] == 'E')c = 14;
			if (n[i] == 'F')c = 15;
		}
		a = a + c * t;
		t *= osn;
	}
	return a;
}
int main(){
	setlocale(LC_ALL, "rus");
	int osn1, osn2;
	string a;
	cout << "¬ведите основание первой и второй системы счислени€" << endl;
	cin >> osn1 >> osn2;
	cout << "¬ведите число" << endl;
	cin >> a;
	char *q = new char[10 * a.length()];
	int b = dec(a, osn1); int i = 0;
	while (b > 0){
		char c = 0;
		if (b%osn2 < 10 & b%osn2 >= 0)c = b%osn2 + '0';
		if (b%osn2 == 10) c = 'A';
		if (b%osn2 == 11) c = 'B';
		if (b%osn2 == 12) c = 'C';
		if (b%osn2 == 13) c = 'D';
		if (b%osn2 == 14) c = 'E';
		if (b%osn2 == 15) c = 'F';
		q[i] = c;
		b = b / osn2;
		++i;
	}
	for (int j = i - 1; j >= 0; --j){
		cout << q[j];
	}
	delete[]q;
	return 0;
}