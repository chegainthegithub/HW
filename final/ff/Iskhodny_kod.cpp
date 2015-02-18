#include <iostream>
#include <string>
using namespace std;

int dec(string n,int osn){
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
void secondask(){
	int osn1,osn2;
	string a;
	cout << "Введите основание перой и второй системы счисления" << endl;
	cin >> osn1 >> osn2;
	cout << "Введите число" << endl;
	cin >> a;
	char *q = new char[10 * a.length()];
	int b = dec(a, osn1); int i = 0;
	while (b > 0){
		char c = 0;
		if (b%osn2 < 10 & b%osn2>=0)c = b%osn2 + '0';
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
	for (int j = i-1; j >=0; --j){
		cout << q[j];
	}
	delete[]q;
}

void firstask(){
	cout << "Введите строку" << endl;
	string a;
	cin >> a;
	bool b=1;
	for (int i = 0; i < a.length(); ++i){
		if (a[i] != '0' & a[i] != '1')b = 0;
	}
	if (b == 1)cout << "Да, данная строка есть двоичное число";
	else cout << "Нет";
}
void thirdask()
{
	string a;
	cout << "Введите текст\n";
	cin >> a;
	int i = 0;
	while (i<a.length())
	{
		char *text = &a[i];
		if ((*text == 'A') || (*text == 'a'))
		{
			cout << ".-";
		}
		if ((*text == 'B') || (*text == 'b'))
		{
			cout << "-...";
		}
		if ((*text == 'C') || (*text == 'c'))
		{
			cout << "-.-.";
		}
		if ((*text == 'D') || (*text == 'd'))
		{
			cout << "-..";
		}
		if ((*text == 'E') || (*text == 'e'))
		{
			cout << ".";
		}
		if ((*text == 'F') || (*text == 'f'))
		{
			cout << "..-.";
		}
		if ((*text == 'G') || (*text == 'g'))
		{
			cout << "--.";
		}
		if ((*text == 'H') || (*text == 'h'))
		{
			cout << "....";
		}
		if ((*text == 'I') || (*text == 'i'))
		{
			cout << "..";
		}
		if ((*text == 'J') || (*text == 'j'))
		{
			cout << ".---";
		}
		if ((*text == 'K') || (*text == 'k'))
		{
			cout << "-.-";
		}
		if ((*text == 'L') || (*text == 'l'))
		{
			cout << ".-..";
		}
		if ((*text == 'M') || (*text == 'm'))
		{
			cout << "--";
		}
		if ((*text == 'N') || (*text == 'n'))
		{
			cout << "-.";
		}
		if ((*text == 'O') || (*text == 'o'))
		{
			cout << "---";
		}
		if ((*text == 'P') || (*text == 'p'))
		{
			cout << ".--.";
		}
		if ((*text == 'Q') || (*text == 'q'))
		{
			cout << "--.-";
		}
		if ((*text == 'R') || (*text == 'r'))
		{
			cout << ".-.";
		}
		if ((*text == 'S') || (*text == 's'))
		{
			cout << "...";
		}
		if ((*text == 'T') || (*text == 't'))
		{
			cout << "-";
		}
		if ((*text == 'U') || (*text == 'u'))
		{
			cout << "..-";
		}
		if ((*text == 'V') || (*text == 'v'))
		{
			cout << "...-";
		}
		if ((*text == 'W') || (*text == 'w'))
		{
			cout << ".--";
		}
		if ((*text == 'X') || (*text == 'x'))
		{
			cout << "-..-";
		}
		if ((*text == 'Y') || (*text == 'y'))
		{
			cout << "-.--";
		}
		if ((*text == 'Z') || (*text == 'z'))
		{
			cout << "--..";
		}
		if (*text == '1')
		{
			cout << ".----";
		}
		if (*text == '2')
		{
			cout << "..---";
		}
		if (*text == '3')
		{
			cout << "...--";
		}
		if (*text == '4')
		{
			cout << "....-";
		}
		if (*text == '5')
		{
			cout << ".....";
		}
		if (*text == '6')
		{
			cout << "-....";
		}
		if (*text == '7')
		{
			cout << "--...";
		}
		if (*text == '8')
		{
			cout << "---..";
		}
		if (*text == '9')
		{
			cout << "----.";
		}
		if (*text == '0')
		{
			cout << "-----";
		}
		if (*text == '.')
		{
			cout << ".-.-.-";
		}
		if (*text == ',')
		{
			cout << "--..--";
		}
		if (*text == ':')
		{
			cout << "---...";
		}
		if (*text == '?')
		{
			cout << "..--..";
		}
		if (*text == '-')
		{
			cout << "-....-";
		}
		if (*text == '/')
		{
			cout << "--..-.";
		}
		++i;
	}
	cout << endl;
}

void fifthask(){
	cout << "Введите строку" << endl;
	string a;
	cin >> a;
	int mlen, mbeg;
	mlen = 0;
	mbeg = 0;
	for (int i = 0; i < a.length();++i){
		int j = i;
		while (a[j] == '0')++j;
		if (j-i > mlen){
			mlen = j - i;
			mbeg = j;
		}
		i = j;
	}
	cout << "begin = " << mbeg << endl << "length = " << mlen << endl;
}

int main(){
	setlocale(LC_ALL, "Russian");
	cout << "Введите номер задачи" << endl;
	short questionnumber;
	bool b = 0;
	while (b == 0){
		cin >> questionnumber;
		switch (questionnumber)
		{
		case 1:firstask();
			b = 1;
			break;
		case 2:secondask();
			b = 1;
			break;
		case 3:thirdask();
			b = 1;
			break;
		/*case 4:fourthask();
			b = 1;
			break;*/
		case 5:fifthask();
			b = 1;
			break;
		/*case 6:sixthask();
			b = 1;
			break;
		case 7:seventhask();
			b = 1;
			break;*/
		default:cout << "Такой задачи не существует в базе, повторите попытку" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}