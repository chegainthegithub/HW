#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

void quickSort(unsigned e, unsigned f, double *arr)
{
	long i = e, j = f;
	double q = arr[(e + f) / 2];
	do
	{
		while (arr[i] < q) { i++; }
		while (q < arr[j]) { j--; }
		if (i <= j)
		{
			double temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (e < j){ quickSort(e, j, arr); }
	if (i < f){ quickSort(i, f, arr); }
}
void quickSort(unsigned e, unsigned f, int *arr)
{
	long i = e, j = f;
	int q = arr[(e + f) / 2];
	do
	{
		while (arr[i] < q) { i++; }
		while (q < arr[j]) { j--; }
		if (i <= j)
		{
			double temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (e < j){ quickSort(e, j, arr); }
	if (i < f){ quickSort(i, f, arr); }
}
char* ConvCharToStringNumber(char c){
	char *text;
	switch (c)
	{
	case '0': {text = "zero"; break; };
	case '1': {text = "one"; break; };
	case '2': {text = "two"; break; };
	case '3': {text = "three"; break; };
	case '4': {text = "four"; break; };
	case '5': {text = "five"; break; }
	case '6': {text = "six"; break; }
	case '7': {text = "seven"; break; }
	case '8': {text = "eight"; break; }
	case '9': {text = "nine"; break; }
	default:
		return "";
	}
	return text;
}
unsigned StrToNum(char c){
	switch (c)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case 'A': return 10;
	case 'B': return 11;
	case 'C': return 12;
	case 'D': return 13;
	case 'E': return 14;
	case 'F': return 15;
	default:
		return -1;
	}
}
char NumToStr(unsigned a){
	switch (a)
	{
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';
	default:
		return NULL;
	}
}
unsigned TransTo10(string s, unsigned A){
	unsigned s10_return = 0;
	for (unsigned i = 0; i < s.length(); i++)
	{
		s10_return = s10_return * A + StrToNum(s[i]);
	}
	return s10_return;
}
string TransToB(unsigned s10, unsigned B)
{
	string s_return;
	unsigned i = 0;
	while (s10 > 0)
	{
		s_return[i] = NumToStr(s10 % B);
		s10 /= B;
		if (B == 1) { s10--; }
		i++;
	}
	for (unsigned j = 0; j < s_return.length(); j++)//переворачиваем строку
	{
		char tempc = s_return[j];
		s_return[j] = s_return[s_return.length() - j];
		s_return[s_return.length() - j] = tempc;
	}
	return s_return;
}
int file_copy(fstream *file1, fstream *file2)
{
	char a;
	unsigned y = (*file1).tellg();
	(*file1).seekg(0, (*file1).beg);
	while (1)
	{
		(*file1).get(a);
		if ((*file1).eof()) break;
		(*file2) << a;
	}
	(*file1).seekg(y, (*file1).beg);
	return 0;
}

void A1(int h1, int m1, int s1, int h2, int m2, int s2, int *h, int *m, int *s){

	if (h1 < h2) //облегчение счета
	{
		int temp = 0;
		temp = h1;
		h1 = h2;
		h2 = temp;
		temp = m1;
		m1 = m2;
		m2 = temp;
		temp = s1;
		s1 = s2;
		s2 = temp;
	}
	else
	{
		if ((m1 < m2) && (h1 = h2))
		{
			int temp = 0;
			temp = h1;
			h1 = h2;
			h2 = temp;
			temp = m1;
			m1 = m2;
			m2 = temp;
			temp = s1;
			s1 = s2;
			s2 = temp;
		}
		else
		{
			if ((m1 = m2) && (h1 = h2) && (s1 < s2))
			{
				int temp = 0;
				temp = h1;
				h1 = h2;
				h2 = temp;
				temp = m1;
				m1 = m2;
				m2 = temp;
				temp = s1;
				s1 = s2;
				s2 = temp;
			}
		}
	}
	
	/*/cout << h1 << "h " << m1 << "m " << s1 << "s " << endl;
	//cout << h2 << "h " << m2 << "m " << s2 << "s " << endl;
	/////////////////////////*/

	*s = s1 - s2;
	if (*s < 0)
	{
		m1 -= 1;
		*s += 60;
	}
	*m = m1 - m2;
	if (*m < 0)
	{
		h1 -= 1;
		*m += 60;
	}
	*h = h1 - h2;
	return;
}

void A2(float a, float *z1, float *z2){
	*z1 = (1 - 2 * sin(a) * sin(a)) / (1 + sin(2 * a));
	*z2 = (1 - tan(a)) / (1 + tan(a));
	return;
}

void A3(double A, double B, double C, double *x1, double *x2, bool *c){
	double d = 0;
	d = B * B - 4 * A * C;
	if (d>0)
	{
		*x1 = (-B + sqrt(d)) / A / 2;
		*x2 = (-B - sqrt(d)) / A / 2;
		*c = 0;
		return;
	}
	if (d=0)
	{
		*x1 = -B / A / 2;
		*x2 = *x1;
		*c = 0;
		return;
	}
	if (d < 0)
	{
		*x1 = sqrt(-d) / A / 2;
		*x2 = -B / A / 2;
		*c = 1;
		return;
	}
	return;
}

bool A4(double x, double y)
{
	if (y >= 0)
	{
		if (((y - 2.0 * x - 2) <= 0) && ((y + 2.0 * x - 2) <= 0)) 
			return true;
		else 
			return false;
	}
	else
	{
		if (((pow(x - 1, 2) + pow(y, 2) - 1) <= 0) || ((pow(x + 1, 2) + pow(y, 2) - 1) <= 0))
			return true;
		else
			return false;
	}
}

char * A5(int N){
	switch (N){
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	case 7:
		return "Sunday";
	default:
		return "ERROR: Wrong input";
	}
}

char* A6(int d, int m, int y, int c)
{
	int N = (d + static_cast<int>(0.2 * (13 * m - 1.0)) + y + static_cast<int>(y / 4.0) + static_cast<int>(c / 4.0) - 2 * c + 777) % 7;
	return A5(N);
}

string A7(int n)
{
	string text_out = "";
	if (n >= 4000)
	{
		text_out = "0";
	}
	else
	{
		int M = n / 1000;
		n = n - M * 1000;
		for (int i = 0; i < M; ++i)
		{
			 text_out += "M";
		}

		int C = n / 100;
		n = n - C * 100;
		if (C == 9)
		{
			C = 0;
			text_out += "CM";
		}
		if (C >= 5)
		{
			C = C - 5;
			text_out += "D";
		}
		if (C == 4)
		{
			C = 0;
			text_out += "CD";
		}
		for (int i = 0; i < C; ++i)
		{
			text_out += "C";
		}

		int X = n / 10;
		n = n - X * 10;
		if (X == 9)
		{
			X = 0;
			text_out += "XC";
		}
		if (X >= 5)
		{
			X = X - 5;
			text_out += "L";
		}
		if (X == 4)
		{
			X = 0;
			text_out += "XL";
		}
		for (int i = 0; i < X; ++i)
		{
			text_out += "X";
		}

		int I = n;
		if (I == 9)
		{
			I = 0;
			text_out += "IX";
		}
		if (I >= 5)
		{
			I = I - 5;
			text_out += "V";
		}
		if (I == 4)
		{
			I = 0;
			text_out += "IV";
		}
		for (int i = 0; i < I; ++i)
		{
			text_out += "I";
		}
	}
	return text_out;
}
//care
void AL1(){
	srand(time(0));
	int count = rand() % 30 + 10;
	int j = 1;
	int y = rand() % 24;
	int x = rand() % 24;
	int sum = y;
	bool check = false;
	if (x >= y)
	{
		check = true;
	}
	else
	{
		check = false;
	}
	cout << y << " ";
	for (int i = 0; i < count - 2; i++)
	{
		sum += x;
		cout << x << " ";
		if (check && x < y)
		{
			j++;
			check = false;
		}
		else
		{
			if (!check && x > y)
			{
				j++;
				check = true;
			}
		}
		y = x;
		x = rand() % 24;
	}
	cout << endl << "Subsequence= " << j << endl << "Average = " << static_cast<float>(sum) / static_cast<float>(count) << endl;

	count = rand() % 30 + 10;
	j = 1;
	y = rand() % 10 + 50;
	x = rand() % 10 + 50;
	sum = y;
	if (x >= y)
	{
		check = true;
	}
	else
	{
		check = false;
	}
	cout << y << " ";
	for (int i = 0; i < count - 2; i++)
	{
		sum += x;
		cout << x << " ";
		if (check && x < y)
		{
			j++;
			check = false;
		}
		else
		{
			if (!check && x > y)
			{
				j++;
				check = true;
			}
		}
		y = x;
		x = rand() % 10 + 50;
	}
	cout << endl << "Subsequence= " << j << endl << "Average = " << static_cast<float>(sum) / static_cast<float>(count) << endl;

	count = rand() % 30 + 10;
	j = 1;
	y = rand() % 14 - 7;
	x = rand() % 14 - 7;
	sum = y;
	if (x >= y)
	{
		check = true;
	}
	else
	{
		check = false;
	}
	cout << y << " ";
	for (int i = 0; i < count - 2; i++)
	{
		sum += x;
		cout << x << " ";
		if (check && x < y)
		{
			j++;
			check = false;
		}
		else
		{
			if (!check && x > y)
			{
				j++;
				check = true;
			}
		}
		y = x;
		x = rand() % 14 - 7;
	}
	cout << endl << "Subsequence= " << j << endl << "Average = " << static_cast<float>(sum) / static_cast<float>(count) << endl;

	return;
}

double AL2(double x, unsigned n){
	double ans = sin(x);
	for (unsigned i = 0; i < n-1; i++)
	{
		ans = ans + sin(ans);
	}
	return ans;
}

double AL3(float n)
{
	double p = 4.0;
	int b = -1;
	int i = 1;
	while (1 / (2.0 * i + 1) > n)
	{
		p = p + 4 * b / (2.0 * i + 1);
		b = -b;
		i++;
	}
	return p;
}

void AL4(double x1, double x2, double dx, double e){
	while (x1 <= x2)
	{
		double temp = (x1 - 1);
		double sum = 0;
		unsigned n = 1;
		while (abs(temp) > e)
		{
			sum += temp;
			temp = pow(-1, n) * pow(x1 - 1, n + 1) / (n + 1);
			n++;
		}
		cout << x1 << " | " << sum << endl;
	}
	return;
}

void AL5(unsigned k, float p, float g, unsigned m, float fast){
	double fraction = k / (g * 12) * m;
	double rest = k;
	if (fast < g && fast > 0)
	{
		fraction = k / (fast * m);
		cout << "You want repay the credit in " << fast << " years.\nrecalculating...\n";
	}
	while (rest > fraction - 1)
	{
		cout <</* "rest=" << rest << " | " <<*/ fraction + rest * m * 30 * p / 36000 /*<< " " << rest * m * 30 * p / 36500 */<< endl;
		rest -= fraction;
	}
	return;
}

void AL6(int *t){
	for (unsigned i = 0; i < 10; i++)
	{
		int temp = t[i];
		t[i] = t[19 - i];
		t[19 - i] = temp;
	}
	return;
}

unsigned AL7(unsigned m){
	unsigned arr[20];
	for (unsigned i = 0; i < 20; i++)
	{
		arr[i] = i+1;
	}
	unsigned k = 20;
	unsigned i = 0;
	while (k > 1)
	{
		i += m;
		if (i >= k)
		{
			i = i%k;
		}
		for (unsigned j = i; j < k-1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[k-1] = 0;
		k--;
	}
	return arr[0];
}
//m = 7;

void AL8(double *arr, unsigned k)
{
	quickSort(0, k - 1, arr);
	cout << "min = " << arr[0] + arr[1] + arr[2] << endl;
	cout << "max = " << arr[k-1] + arr[k-2] + arr[k-3] << endl;
	return;
}

bool S1(string s){
	for (unsigned i = 0; i < s.length(); i++)
	{
		if (s[i] != '0' || s[i] != '1')
		{
			return false;
		}
	}
	return true;
}

string S2(string s, unsigned A, unsigned B){
	bool negative = false;
	if (s[0] = '-')//удаление минуса в начале строки
	{
		negative = true; 
		for (unsigned i = 0; i < s.length() / 2; i++)
		{
			char temp = s[i];
			s[i] = s[s.length() - i];
			s[s.length() - i] = temp;
		}
		s.pop_back();
		for (unsigned i = 0; i < s.length() / 2; i++)
		{
			char temp = s[i];
			s[i] = s[s.length() - i];
			s[s.length() - i] = temp;
		}
	}
	string s_return;
	if (s.find('.') == -1)
	{
		unsigned s10 = TransTo10(s, A);
		s_return = TransToB(s10, B);
	}
	else
	{
		//double s10 = TransTo10(s, A);
	}
	return s_return;
}

string S3(string text)
{
	string s_return;
	s_return.clear();
	unsigned i = 0;
	while (i != text.size())
	{
		if ((text[i] == 'A') || (text[i] == 'a'))
		{
			s_return += ".-";
		}
		if ((text[i] == 'B') || (text[i] == 'b'))
		{
			s_return += "-...";
		}
		if ((text[i] == 'C') || (text[i] == 'c'))
		{
			s_return += "-.-.";
		}
		if ((text[i] == 'D') || (text[i] == 'd'))
		{
			s_return += "-..";
		}
		if ((text[i] == 'E') || (text[i] == 'e'))
		{
			s_return += ".";
		}
		if ((text[i] == 'F') || (text[i] == 'f'))
		{
			s_return += "..-.";
		}
		if ((text[i] == 'G') || (text[i] == 'g'))
		{
			s_return += "--.";
		}
		if ((text[i] == 'H') || (text[i] == 'h'))
		{
			s_return += "....";
		}
		if ((text[i] == 'I') || (text[i] == 'i'))
		{
			s_return += "..";
		}
		if ((text[i] == 'J') || (text[i] == 'j'))
		{
			s_return += ".---";
		}
		if ((text[i] == 'K') || (text[i] == 'k'))
		{
			s_return += "-.-";
		}
		if ((text[i] == 'L') || (text[i] == 'l'))
		{
			s_return += ".-..";
		}
		if ((text[i] == 'M') || (text[i] == 'm'))
		{
			s_return += "--";
		}
		if ((text[i] == 'N') || (text[i] == 'n'))
		{
			s_return += "-.";
		}
		if ((text[i] == 'O') || (text[i] == 'o'))
		{
			s_return += "---";
		}
		if ((text[i] == 'P') || (text[i] == 'p'))
		{
			s_return += ".--.";
		}
		if ((text[i] == 'Q') || (text[i] == 'q'))
		{
			s_return += "--.-";
		}
		if ((text[i] == 'R') || (text[i] == 'r'))
		{
			s_return += ".-.";
		}
		if ((text[i] == 'S') || (text[i] == 's'))
		{
			s_return += "...";
		}
		if ((text[i] == 'T') || (text[i] == 't'))
		{
			s_return += "-";
		}
		if ((text[i] == 'U') || (text[i] == 'u'))
		{
			s_return += "..-";
		}
		if ((text[i] == 'V') || (text[i] == 'v'))
		{
			s_return += "...-";
		}
		if ((text[i] == 'W') || (text[i] == 'w'))
		{
			s_return += ".--";
		}
		if ((text[i] == 'X') || (text[i] == 'x'))
		{
			s_return += "-..-";
		}
		if ((text[i] == 'Y') || (text[i] == 'y'))
		{
			s_return += "-.--";
		}
		if ((text[i] == 'Z') || (text[i] == 'z'))
		{
			s_return += "--..";
		}
		if (text[i] == '1')
		{
			s_return += ".----";
		}
		if (text[i] == '2')
		{
			s_return += "..---";
		}
		if (text[i] == '3')
		{
			s_return += "...--";
		}
		if (text[i] == '4')
		{
			s_return += "....-";
		}
		if (text[i] == '5')
		{
			s_return += ".....";
		}
		if (text[i] == '6')
		{
			s_return += "-....";
		}
		if (text[i] == '7')
		{
			s_return += "--...";
		}
		if (text[i] == '8')
		{
			s_return += "---..";
		}
		if (text[i] == '9')
		{
			s_return += "----.";
		}
		if (text[i] == '0')
		{
			s_return += "-----";
		}
		if (text[i] == '.')
		{
			s_return += ".-.-.-";
		}
		if (text[i] == ',')
		{
			s_return += "--..--";
		}
		if (text[i] == ':')
		{
			s_return += "---...";
		}
		if (text[i] == '?')
		{
			s_return += "..--..";
		}
		if (text[i] == '-')
		{
			s_return += "-....-";
		}
		if (text[i] == '/')
		{
			s_return += "--..-.";
		}
		i++;
	}
	return s_return;
}

unsigned S4(char *text)
{
	int Num = 0;
	while (*text != 0)
	{
		if (*text == 'V')
		{
			Num += 5;
			text++;
		}

		if (*text == 'I')
		{
			if (*(text + 1) == 'X')
			{
				Num += 9;
				text++;
			}
			else
			{
				if (*(text + 1) == 'V')
				{
					Num += 4;
					text++;
				}
				else Num += 1;
			}
			text++;
		}

		if (*text == 'L')
		{
			Num += 50;
			text++;
		}

		if (*text == 'X')
		{
			if (*(text + 1) == 'C')
			{
				Num += 90;
				text++;
			}
			else
			{
				if (*(text + 1) == 'L')
				{
					Num += 40;
					text++;
				}
				else Num += 10;
			}
			text++;
		}

		if (*text == 'D')
		{
			Num += 500;
			text++;
		}

		if (*text == 'C')
		{
			if (*(text + 1) == 'M')
			{
				Num += 900;
				text++;
			}
			else
			{
				if (*(text + 1) == 'D')
				{
					Num += 400;
					text++;
				}
				else Num += 100;
			}
			text++;
		}

		if (*text == 'M')
		{
			Num += 1000;
			text++;
		}
	}
	cout << Num << endl;
	return Num;
}

void S5(string text, int *retUrn)
{
	unsigned max = 0, position = 0;
	unsigned current = 0;
	unsigned i = 0;
	while (i < text.size())
	{
		if (text[i] == '0'){
			current++;
		}
		if (text[i] == '1')
		{
			if (current > max)
			{
				max = current;
				position = i - current;
			}
			current = 0;
		}
		i++;
	}
	if (current > max)
	{
		max = current;
		position = i - current;
	}
	retUrn[0] = max;
	retUrn[1] = position;
	return;
}

double F1(string file_name){
	fstream file(file_name);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return -1;
	}
	double ans = 0, a = 0;
	unsigned i = 0;
	while (1)
	{
		file >> a;
		ans += a;
		i++;
		if (file.eof()) break;
	}
	file.close();
	return ans / i;
}

void F2(string file_name){
	fstream file(file_name);
	cout << endl;
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	char c;
	while (1)
	{
		file.get(c);
		if ('A' <= c && c <= 'Z')
		{
			cout << ('a' + c - 'A');
		}
		else
		{
			if ('a' <= c && c <= 'z')
			{
				cout << ('A' + c - 'a');
			}
			else
			{
				if ('0' <= c && c <= '9')
				{
					cout << ConvCharToStringNumber(c);
				}
				else
				{
					cout << c;
				}
			}
		}

		if (file.eof()) break;
	}
	cout << endl;
	return;
}

bool check_date(char *text)
{
	if (text[2] != '.' && text[5] != '.') return false;
	else
	{
		if ('0' > text[6] || text[6] > '9' || '0' > text[7] || text[7] > '9' 
			|| '0' > text[8] || text[8] > '9' || '0' > text[9] || text[9] > '9')
			return false;
		else
		{
			int date = atoi((char*)text[0]) * 10 + atoi((char*)text[1]);
			if (date >= 32 || date == 0) return false;
			else
			{
				int month = atoi((char*)text[3]) * 10 + atoi((char*)text[4]);
				if (month >= 13 || month == 0) return false;
			}
		}
	}
	return true;
}
//for F3

void F3(string file_name){
	fstream file(file_name);
	fstream tempfile;
	tempfile.open("temp.txt", ios_base::out | ios_base::trunc);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		remove("temp.txt");
		return;
	}
	char c[10];
	int i = 0;
	while (1)
	{
		file.get(c[i]);
		i++;
		if (file.eof() || i >= 9) break;
	}
	if (!file.eof())
	{
		while (1)
		{
			file.get(c[9]);
			if (file.eof()) break;
			if (check_date(c))
			{
				tempfile << c[0] << c[1] << c[2] << c[3] << c[4] << c[5];
				int tempi = (c[6] - '0') * 1000 + (c[7] - '0') * 100 + (c[8] - '0') * 10 + c[9] - '0';
				string temps = A7(tempi);
				tempfile << temps;
				c[0] = (char)temps[temps.size() - 10];
				c[1] = (char)temps[temps.size() - 9];
				c[2] = (char)temps[temps.size() - 8];
				c[3] = (char)temps[temps.size() - 7];
				c[4] = (char)temps[temps.size() - 6];
				c[5] = (char)temps[temps.size() - 5];
				c[6] = (char)temps[temps.size() - 4];
				c[7] = (char)temps[temps.size() - 3];
				c[8] = (char)temps[temps.size() - 2];
				c[9] = 0;
			}
			tempfile << c[9];
			for (int j = 0; j < 9; j++)
			{
				c[j] = c[j + 1];
			}
		}
	}
	else
	{
		for (int j = 0; j <= i; j++)
		{
			tempfile << c[j];
		}
	}
	file.close();
	tempfile.close();
	/*file.open(file_name, ios_base::out | ios_base::trunc);
	tempfile.open("temp.temp", ios_base::in | ios_base::binary);
	file_copy(&tempfile, &file);
	file.close();
	tempfile.close();
	remove("temp.temp");*/
	cout << "Done.\n";
	return;
}
//doesnt work

void F4(string file_name, string word)
{
	fstream file(file_name);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	string strin;
	int j = 0;
	while (1)
	{
		getline(file, strin);
		j = strin.find(word);
		if (j != -1)
		{
			cout << strin << endl;
		}
		if (file.eof()) break;
	}
	file.close();
	return;
}

unsigned F5(string file_name, string find){
	fstream file(file_name);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return 0;
	}
	string strin;
	unsigned j = 0;
	while (1)
	{
		unsigned i = 0;
		int pos = 0;
		getline(file, strin);
		while (pos != -1 && i < strin.size())
		{
			pos = strin.find(find, i);
			if (pos != -1)
			{
				if (pos + find.size() < strin.size() && pos - 1 >= 0)
				{
					if ((strin[pos - 1] == ' ' || strin[pos - 1] == '\"' || strin[pos - 1] == '\'' || strin[pos - 1] == '\t') 
						&& (strin[pos + find.size()] == ' ' || strin[pos + find.size()] == ','
						|| strin[pos + find.size()] == '.' || strin[pos + find.size()] == '!' || strin[pos + find.size()] == '?'
						|| strin[pos + find.size()] == '\"' || strin[pos + find.size()] == '\'' || strin[pos + find.size()] == '\n'))
					{
						j++;
					}
				}
				else
				{
					if (pos - 1 < 0 && pos == 0 && (pos + find.size()) >= strin.size())
						if (strin[pos + find.size()] == ' ' || strin[pos + find.size()] == ','
							|| strin[pos + find.size()] == '.' || strin[pos + find.size()] == '!' || strin[pos + find.size()] == '?'
							|| strin[pos + find.size()] == '\"' || strin[pos + find.size()] == '\'' || strin[pos + find.size()] == '\n')
							j++;
					if ((strin[pos - 1] == ' ' || strin[pos - 1] == '\"' || strin[pos - 1] == '\''))
						j++;
				}
			}
			i += pos+1;
		}
		if (file.eof()) break;
	}
	file.close();
	return j;
}

void F6(string file_name){
	fstream file;
	file.open(file_name);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	unsigned max = 0;
	char **word = new char*[1];
	word[0] = new char[1];
	unsigned words = 1;
	unsigned *entry = new unsigned[1];
	entry[0] = 0;
	char *temp = new char[1];
	//temp = "\0";
	unsigned tempsize = 0;
	char c;
	while (1)
	{
		file.get(c);
		if (c != ' ' && c != '!' && c != '.' && c != ',' && c != '?' && c != '\"' && c != '\'')
		{
			char *temp2 = new char[tempsize + 1];
			strcpy(temp2, temp);
			temp2[tempsize] = c;
			delete[] temp;
			tempsize++;
			temp = new char[tempsize];
			strcpy(temp, temp2);
			delete[] temp2;
		}
		else
		{
			if (tempsize > max) //новое большое слово
			{
				for (int i = 0; i < words; i++)
				{
					delete[] word[i];
				}
				delete[] word;
				delete[] entry;
				entry = new unsigned[1];
				entry[0] = 1;
				word = new char*[1];
				word[0] = new char[max];
				strcpy(word[0], temp);
				max = tempsize;
				words = 1;
			}
			else
			{
				if (tempsize == max) //одинаково большое слово
				{
					int i;
					for (i = 0; i < words; i++)
					{
						if (!strcmp(temp, word[i]))
						{
							entry[i]++;
							break;
						}
					}
					if (!(i < words))
					{
						words++;
						//========================
						char **temp2 = new char*[words];
						for (int j = 0; j < words; j++)
						{
							temp2[j] = new char[max];
						}
						for (int j = 0; j < words - 1; j++)
						{
							temp2[j] = word[j];
						}
						temp2[words-1] = temp;
						for (int j = words; j > 0; j--)
						{
							delete[] word[j];
						}
						delete[] word;
						word = new char*[words];
						for (int j = 0; j < words; j++)
						{
							word[j] = new char[max];
						}
						for (int j = words; j > 0; j--)
						{
							delete[] temp2[j];
						}
						delete[] temp2;
						//========================
						unsigned *tempint = new unsigned[words];
						for (int j = 0; j < words - 1; j++)
						{
							tempint[j] = entry[j];
						}
						tempint[words - 1] = 1;
						delete[] entry;
						entry = new unsigned[words];
						for (int j = 0; j < words; j++)
						{
							entry[j] = tempint[j];
						}
						delete[] tempint;
						//========================
					}
				}
			}
			delete[] temp;
			temp = new char[1];
			tempsize = 1;
		}
		if (file.eof()) break;
	}
	delete[] temp;
	for (int j = 0; j < words; j++)
	{
		cout << word[j] << " " << entry[j] << " times" << endl;
	}
	for (int j = 0; j < words; j++)
	{
		delete[] word[j];
	}
	delete[] word;
	delete[] entry;
	file.close();
	return;
}
//doesnt work

void F7(string file_name){
	fstream file;
	file.open(file_name);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	char *sentence = new char[1];
	unsigned sentencesize = 0;
	char c;
	while (1)
	{
		file.get(c);
		if (c == '?')
		{
			cout << sentence << endl;
			delete[] sentence;
			sentencesize = 1;
			sentence = new char[1];
		}
		else
		{
			if (c == '.' || c == '!')
			{
				delete[] sentence;
				sentence = new char[1];
				sentencesize = 1;
			}
			else
			{
				sentencesize++;
				char *temp = new char[sentencesize];
				strcpy(temp, sentence);
				temp[sentencesize - 1] = c;
				delete[] sentence;
				sentence = new char[sentencesize];
				strcpy(sentence, temp);
				delete[] temp;
			}
		}
		if (file.eof()) break;
	}
	file.close();
	return;
}
//doesnt work

void F10(string file_in_name, string file_out_name){
	fstream file_in;
	fstream file_out;
	file_in.open(file_in_name);
	if (file_in.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_in_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	file_out.open(file_out_name, ios_base::out | ios_base::trunc);
	string text;
	text.clear();
	string text_out;
	while (1)
	{
		text_out.clear();
		getline(file_in, text);
		unsigned words = 0;
		unsigned i = 0;
		while (text[i] == ' ')
		{
			i++;
		}
		while (i < text.size())
		{
			while (text[i] != ' ' && i < text.size())
			{
				if (text[i] != '\t')
				{
					text_out.push_back(text[i]);
				}
				i++;
			}
			if (text[i] == ' ')
			{
				text_out.push_back(' '); //разделяем слова
				words++;
			}
			while (text[i] == ' ' && i < text.size())
			{
				i++;
			}
		}
		if (words > 0)
		{
			unsigned need = (80 - text_out.size()) / words;
			i = 0;
			//unsigned leng = text_out.size();
			while (i < text_out.size())
			{
				while (text_out[i] != ' ' && i < text_out.size())
				{
					i++;
				}
				if (text_out[i] == ' ')
				{
					for (int j = 0; j < need; j++)
						text_out.insert(i, " ");
					i += need;
				}
				i++;
			}
		}
		else text_out = text;
		file_out << text_out << endl;
		if (file_in.eof()) break;
	}
	file_in.close();
	file_out.close();
	cout << "Done.";
	return;
}

void F9(string file_name){
	fstream file;
	file.open(file_name);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	string text;
	while (1)
	{
		getline(file, text);
		unsigned i = 0;
		while (text[i] == ' ')
		{
			i++;
		}
		unsigned need = (80 - text.size()) / 2 - i;
		for (int j = 0; j < need; j++)
		{
			cout << " ";
		}
		cout << text;
		if (file.eof()) break;
	}
	file.close();
	cout << "Done.";
	return;
}
//имхо не работает

void F8(string file_in_name, string file_out_name)
{
	fstream file_in;
	fstream file_out;
	file_in.open(file_in_name, ios_base::in | ios_base::binary);
	file_out.open(file_out_name, ios_base::out | ios_base::trunc);
	if (file_in.is_open() != true)
	{
		cout << "File '" << file_in_name << "' not found." << endl;
		return;
	}
	char a1, a2;
	file_in.get(a1);
	bool should_write_b = true, should_write_m = true, delay = false; // b base m multi
	while (1)
	{
		file_in.get(a2);
		if (a1 == a2 && a1 == '/' && should_write_m)
		{
			should_write_b = false;
		}
		if (a1 == 10 && !should_write_b)
		{
			should_write_b = true;   
		}
		if (a1 == '/' && a2 == '*' && should_write_b)
		{
			should_write_m = false;
		}
		if (delay)
		{
			delay = false;
			should_write_m = true;
		}
		if (a1 == '*' && a2 == '/' && !should_write_m)
		{
			delay = true;
			a2 = '\0';
		}
		if (should_write_b && should_write_m)
		{
			file_out << a1;
		}
		a1 = a2;
		if ((file_in).eof()) break;
	}
	cout << "Done.";
	file_in.close();
	file_out.close();
	return;
}

void F11(string file_name){
	fstream file;
	file.open(file_name, ios_base::in | ios_base::binary);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	char a;
	unsigned i = 0;
	unsigned j = 0;
	while (1)
	{
		//char *a = new char[82];
		file.get(a);
		//j++;
		if (a == 10)
		{
			i++;
		}
		if (!(i % 26))
		{
			cin.get();
			i = 1;
		}
		cout << a;
		//delete[] a;
		if (file.eof()) break;
	}
	file.close();
	return;
}

void F12(string file_name)
{
	fstream file;
	file.open(file_name);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	fstream tempfile;
	tempfile.open("temp.temp", ios_base::out | ios_base::trunc);
	char table[] = "([{";
	char table1[] = "})]";
	char *stackp = 0;
	char *stackd = 0;
	char c;
	int tbli = 0;
	while (1)
	{
		file.get(c);
		if (file.eof()) break;
		if (c != '(')
		{
			if (c == ')')
			{
				c = table1[tbli % 3];
				tbli--;
			}
			tempfile << c;
		}
		else
		{
			tempfile << table[tbli % 3];
			tbli++;
		}
		if (tbli < 0)
		{
			break;
		}
	}
	file.close();
	tempfile.close();
	if (tbli != 0)
	{
		cout << "Can't convert stream. Wrong data.\n";
	}
	else
	{
		file.open(file_name, ios_base::out | ios_base::trunc);
		tempfile.open("temp.temp", ios_base::in | ios_base::binary);
		file_copy(&tempfile, &file);
		file.close();
		tempfile.close();
		cout << "Done.\n";
	}
	remove("temp.temp");
	return;
}

unsigned Getfilesize(fstream *file)
{
	if ((*file).is_open())
	{
		unsigned y = (*file).tellg();
		(*file).seekg(0, (*file).end);
		unsigned x = (*file).tellg();
		(*file).seekg(y, ios_base::beg);
		return x;
	}
	return 0;
}
void F13_1(string file_name, unsigned n)
{
	fstream file;
	file.open(file_name, ios_base::in | ios_base::binary);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	fstream file_s;
	unsigned long filesize = Getfilesize(&file);
	unsigned long curr_file_n = 0;
	char c;
	while (filesize > 0)
	{
		string files_name = file_name + '.';
		files_name += to_string(curr_file_n);
		file_s.open(files_name, ios_base::out | ios_base::trunc);
		unsigned long i = 0;
		while (filesize > 0 && i < n)
		{
			file.get(c);
			if (file.eof()) break;
			file_s << c;
			i++;
			filesize--;
		}
		curr_file_n++;
		file_s.close();
	}
	file.close();
	remove(file_name.c_str());
	cout << "Done.";
	return;
}

void F13_2(string file_name)
{
	fstream file;
	file.open(file_name, ios_base::out | ios_base::trunc);
	unsigned long curr_file_n = 0;
	char c;
	while (1)
	{
		fstream file_in;
		string files_name = file_name + '.';
		files_name += to_string(curr_file_n);
		file_in.open(files_name, ios_base::in | ios_base::binary);
		if (file_in.is_open() != true)
			break;
		while (1)
		{
			file_in.get(c);
			if (file_in.eof())
			{
				file_in.close();
				remove(files_name.c_str());
				curr_file_n++;
				break;
			}
			file << c;
		}
	}
	file.close();
	cout << "Done.";
	return;
}

void F14(string file_name){
	fstream file;
	file.open(file_name, ios_base::in | ios_base::binary);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	string list;
	list = file_name + ".list.txt";
	fstream file_out;
	file_out.open(list, ios_base::out | ios_base::trunc);
	char c;
	unsigned i = 0;
	file_out << 0 << "\t" << hex;
	while (1)
	{
		file.get(c);
		if (file.eof()) break;
		i++;
		if (((int)c & 0xff) < 0x10)
			file_out << "0" << ((int)c & 0xff) << " ";
		else
			file_out << ((int)c & 0xff) << " ";
		if (!(i % 16))
		{
			file_out << endl << dec << i << "\t" << hex;
		}
	}
	file.close();
	file_out.close();
	cout << "------------File created------------\n";
	F11(list);
	return;
}

void b64e(char *a, char* out)
{
	if (a == 0 || out == 0) return;
	char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	bool f1 = false, f2 = false;
	if (a[1] == -1) { a[1] = 0; f1 = true; }
	if (a[2] == -1) { a[2] = 0; f2 = true; }
	out[0] = table[a[0] >> 2];
	out[1] = table[(a[0] & 3) << 4 | a[1] >> 4];
	out[2] = table[(a[1] & 15) << 2 | a[2] >> 6];
	out[3] = table[a[2] & 63];
	if (f1) a[1] = -1;
	if (f2) a[2] = -1;
	return;
}
//for F15_1

void b64de(char *in, char *out)
{
	if (in == 0 || out == 0) return;
	char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
	char in_point[4];
	int j = 0;
	for (unsigned i = 0; i < 4; i++)
	{
		j = 0;
		while (in[i] != table[j] && j < 65)
		{
			j++;
		}
		if (j == 64) return;
		in_point[i] = j;
	}
	out[0] = (in_point[0] & 63) << 2 | (in_point[1] & 48) >> 4;
	out[1] = (in_point[1] & 15) << 4 | (in_point[2] & 60) >> 2;
	out[2] = (in_point[2] & 3) << 6 | (in_point[3] & 63);
	return;
}
//for F_15_2
void F15_1(string file_in_name, string file_out_name)
{
	fstream file_in;
	fstream file_out;
	file_in.open(file_in_name, ios_base::in | ios_base::binary);
	file_out.open(file_out_name, ios_base::out | ios_base::trunc);
	if (file_in.is_open() != true)
	{
		cout << "File '" << file_in_name << "' not found." << endl;
		return;
	}
	while (1)
	{
		char a[3] = { -1, -1, -1 };
		char out[4] = { 0, 0, 0, 0 };
		(file_in).get(a[0]);
		if (!(file_in).eof())
		{
			(file_in).get(a[1]);
			if (!(file_in).eof())
			{
				(file_in).get(a[2]);
			}
		}
		if (!(file_in).eof() || a[0] != -1){
			b64e(a, out);
			(file_out) << out[0] << out[1] << out[2] << out[3];
			if (a[1] == -1)
			{
				(file_out) << "=";
				if (a[2] == -1)
				{
					(file_out) << "=";
				}
			}
		}
		if ((file_in).eof()) break;
	}
	file_in.close();
	file_out.close();
	cout << "Encryption done.\n";
	return;
}

void F15_2(string file_in_name, string file_out_name)
{
	fstream file_in;
	fstream file_out;
	file_in.open(file_in_name, ios_base::in | ios_base::binary);
	file_out.open(file_out_name, ios_base::out | ios_base::trunc);
	if (file_in.is_open() != true)
	{
		cout << "File '" << file_in_name << "' not found." << endl;
		return;
	}
	while (1)
	{
		char in[4] = { 0, 0, 0, 0 };
		char out[3] = { 0, 0, 0 };
		(file_in).get(in[0]);
		if (!(file_in).eof())
		{
			(file_in).get(in[1]);
			if (!(file_in).eof())
			{
				(file_in).get(in[2]);
				if (!(file_in).eof())
				{
					(file_in).get(in[3]);
				}
			}
		}
		if (!(file_in).eof())
		{
			b64de(in, out);
			(file_out) << out[0] << out[1] << out[2];
		}
		if ((file_in).eof()) break;
	}
	return;
	file_in.close();
	file_out.close();
	cout << "Decryption done.\n";
	return;
}

void DES(char *in)
{
	char tempt[64];
	char out[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	unsigned k = 128;
	for (unsigned i = 0; i < 64; i++)
	{
		tempt[i] = in[i / 8] & k;
		k /= 2;
		if (!k) k = 128;
	}
	int table[] = {
		58, 50, 42, 34, 26, 18, 10, 2,
		60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6,
		64, 56, 48, 40, 32, 24, 16, 8,
		57, 49, 41, 33, 25, 17, 9, 1,
		59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5,
		63, 55, 47, 39, 31, 23, 15, 7
	};
	for (unsigned i = 0; i < 8; i++)
	{
		for (unsigned j = 0; j < 8; j++)
			out[i] += tempt[table[i * 8 + j] - 1];
	}

	strncpy(in, out, 8);
	return;
}

void deDES(char *in)
{
	char tempt[64];
	char out[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	unsigned k = 128;
	for (unsigned i = 0; i < 64; i++)
	{
		tempt[i] = in[i / 8] & k;
		k /= 2;
		if (!k) k = 128;
	}
	for (unsigned i = 0; i < 64; i++)
	{
		cout << hex << (int)tempt[i] << " ";
		if (!(i % 8)) cout << endl;
	}
	int table[] = {
		40, 8, 48, 16, 56, 24, 64, 32,
		39, 7, 47, 15, 55, 23, 63, 31,
		38, 6, 46, 14, 54, 22, 62, 30,
		37, 5, 45, 13, 53, 21, 61, 29,
		36, 4, 44, 12, 52, 20, 60, 28,
		35, 3, 43, 11, 51, 19, 59, 27,
		34, 2, 42, 10, 50, 18, 58, 26,
		33, 1, 41, 9, 49, 17, 57, 25,
	};
	for (unsigned i = 0; i < 8; i++)
	{
		for (unsigned j = 0; j < 8; j++)
			out[i] += tempt[table[i * 8 + j] - 1];
	}

	strncpy(in, out, 8);
	return;
}

void F16_1(string file_in_name, string file_out_name)
{
	fstream file_in;
	fstream file_out;
	file_in.open(file_in_name, ios_base::in | ios_base::binary);
	file_out.open(file_out_name, ios_base::out | ios_base::trunc);
	if (file_in.is_open() != true)
	{
		cout << "File '" << file_in_name << "' not found." << endl;
		return;
	}
	char c;
	unsigned i = 0;
	char a[8];
	while (1)
	{
		(file_in).get(c);
		if ((file_in).eof())
		{
			if (i != 0)
			{
				for (unsigned j = i + 1; j < 8; j++)
					a[j] = 0;
				DES(a);
				for (unsigned n = 0; n < 8; n++)
					file_out << a;
			}
			break;
		}
		a[i] = c;
		i++;
		if (i == 8)
		{
			i = 0;
			DES(a);
			for (unsigned n = 0; n < 8;n++)
				file_out << a[n];
		}
	}
	file_in.close();
	file_out.close();
	cout << "Encryption done.\n";
	return;
}

void F16_2(string file_in_name, string file_out_name)
{
	fstream file_in;
	fstream file_out;
	file_in.open(file_in_name, ios_base::in | ios_base::binary);
	file_out.open(file_out_name, ios_base::out | ios_base::trunc);
	if (file_in.is_open() != true)
	{
		cout << "File '" << file_in_name << "' not found." << endl;
		return;
	}
	char c;
	unsigned i = 0;
	char a[8];
	while (1)
	{
		(file_in).get(c);
		if ((file_in).eof())
		{
			if (i != 0)
			{
				for (unsigned j = i + 1; j < 8; j++)
					a[j] = 0;
				deDES(a);
				for (unsigned n = 0; n < 8; n++)
					file_out << a;
			}
			break;
		}
		a[i] = c;
		i++;
		if (i == 8)
		{
			i = 0;
			deDES(a);
			for (unsigned n = 0; n < 8; n++)
				file_out << a[n];
		}
	}
	file_in.close();
	file_out.close();
	cout << "Decryption done.\n";
	return;
}

bool F17(string file_name)
{
	fstream file;
	file.open(file_name, ios_base::in | ios_base::binary);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return false;
	}
	stack <string> ckeck;
	string s;
	string tags;
	bool tag = false;
	while (1)
	{
		getline(file, s);
		if (file.eof()) break;
		tags.clear();
		for (unsigned k = 0; k < s.size(); k++)
		{
			if (tag)
			{
				tags.push_back(s[k]);
			}
			if (s[k] == '<')
			{
				if (tag) return false;
				tag = true;
				tags.push_back(s[k]);
			}
			if (s[k] == '>')
			{
				if (tag)
				{
					tags.push_back(s[k]);
					tag = false;
					if (tags[1] == '/')//opening or closing
					{
						tags.erase(1);
						if (tags == ckeck.top())
							ckeck.pop();
						else
							return false;
						tags.clear();
					}
					else
					{
						ckeck.push(tags);
						tags.clear();
					}
				}
			}

		}
	}
	if (!ckeck.empty()) return false;
	return true;
}
//не учитывается содержание откр тега

void SRT1(int *arr, unsigned n)
{
	for (unsigned i = 0; i < n-1; i++)
	{
		int min = arr[i], mini = i;
		for (unsigned j = i+1; j < n; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				mini = j;
			}
		}
		if (mini != i)
		{
			int temp = arr[i];
			arr[i] = arr[mini];
			arr[mini] = temp;
		}
	}
}

void SRT2(int *arr, unsigned n){
	for (unsigned i = 1; i < n; i++)
	{
		unsigned j = 0;
		while (j < i && arr[j] <= arr[i])
		{
			j++;
		}
		int temp = arr[i];
		for (unsigned e = i; e > j; e--)
		{
			arr[e] = arr[e - 1];
		}
		arr[j] = temp;
	}
	return;
}

void SRT3(int *arr, unsigned n){
	for (unsigned i = 1; i < n; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			unsigned e = 0, f = i - 1;
			do
			{
				if (arr[(e + f) / 2] >= arr[i])
				{
					f = (e + f) / 2;
				}
				else
				{
					e = (e + f) / 2;
				}
			} while (e + 1 != f && e != f);
			int temp = arr[i];
			for (unsigned ti = i; ti > f; ti--)
			{
				arr[ti] = arr[ti - 1];
			}
			arr[f] = temp;
		}
	}
	return;
}

void SRT4(int *arr, unsigned n){
	int t;
	for (unsigned k = n / 2; k > 0; k /= 2)
		for (unsigned i = k; i < n; i++)
		{
		unsigned j = 0;
		t = arr[i];
		for (j = i; j >= k; j -= k)
		{
			if (t < arr[j - k])
				arr[j] = arr[j - k];
			else
				break;
		}
		arr[j] = t;
		}
	return;
}

unsigned SRT5(int *arr, unsigned n){

	int *temparr = new int[n];
	unsigned i = 1, k = 1;
	temparr[0] = arr[0];
	while (i < n)
	{
		if (arr[i] > temparr[k])
		{
			k++;
			temparr[k] = arr[i];
		}
		i++;
	}
	for (unsigned j = 0; j < k; j++)
	{
		arr[j] = temparr[j];
	}
	for (unsigned j = k; j < n; j++)
	{
		arr[j] = 0;
	}
	delete[] temparr;
	return k;
}

int SRT6(int *arr, int find, unsigned n)
{
	int mid, left = 0, right = n - 1;
	while (arr[left] <= find && arr[right] >= find)
	{
		mid = left + ((find - arr[left])*(right - left)) / (arr[right] - arr[left]);
		if (arr[mid]<find) left = mid + 1;
		else 
			if (arr[mid]>find) right = mid - 1;
			else 
				return mid;
	}
	if (arr[left] == find) 
		return left;
		else 
			return -1;
}

unsigned SRT7(int *arr, unsigned n){
	//unsigned *temparr = new unsigned[n];
	unsigned ans = 0;
	for (unsigned i = 0; i < n; i++)
	{
		unsigned j = 0;
		for (; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				break;
			}
		}
		if (i == j)
		{
			ans++;
		}
	}
	return ans;
}

void SRT8(int *arr, unsigned n)
{
	quickSort(0, n - 1, arr);
	unsigned j = 0;
	for (unsigned i = 0; i < arr[n-1]; i++)
	{
		if (i != arr[j])
		{
			cout << i << " ";
		}
		else
		{
			j++;
		}
	}
}

void MergeSort(string *str, unsigned l, unsigned r)
{
	if (l >= r) return;

	unsigned m = (l + r) / 2;

	MergeSort(str, l, m);
	MergeSort(str, m + 1, r);
	unsigned i1 = l;
	unsigned i2 = m + 1;
	int in = 0;
	string *a = new string[r - l + 1];
	while ((i1 <= m)&(i2 <= r)){
		if (strcmp(str[i1].c_str(), str[i2].c_str()))
		{
			a[in] = str[i1];
			i1++;
		}
		else
		{
			a[in] = str[i2];
			i2++;
		}
		in++;
	}
	while (i1 <= m)
	{
		a[in] = str[i1];
		i1++;
		in++;
	}
	while (i2 <= r)
	{
		a[in] = str[i2];
		i2++;
		in++;
	}
	for (int i = l; i <= r; ++i)
	{
		str[i] = a[i - l];
	}
	delete[] a;
}
//for SRT9
void SRT9(string file_name){
	fstream file_in;
	fstream file_out;
	file_in.open(file_name, ios_base::in | ios_base::binary);
	file_out.open("out.txt", ios_base::out | ios_base::trunc);
	if (file_in.is_open() != true)
	{
		cout << "File '" << file_name << "' not found." << endl;
		return;
	}
	char a;
	unsigned lines = 0;
	while (1)
	{
		file_in.get(a);
		if (file_in.eof()) break;
		if (a == '\n') lines++;
	}
	file_in.close();
	file_in.open(file_name, ios_base::in | ios_base::binary);
	if (file_in.is_open() != true)
	{
		cout << "File '" << file_name << "' not found." << endl;
		return;
	}
	string *str = new string[lines++];
	unsigned i = 0;
	while (1)
	{
		getline(file_in, str[i]);
		i++;
	}
	file_in.close();
	MergeSort(str, 0, lines - 1);
	for (unsigned j = 0; j < lines; j++)
	{
		file_out << str[i] << endl;
	}
	delete[] str;
	file_out.close();
	cout << "Done.";
	return;
}