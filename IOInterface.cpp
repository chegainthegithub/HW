#include <iostream>
#include <string>
#include <fstream>
#include "tasks.h"

using namespace std;

void A1_face(){
	unsigned h1, h2, m1, m2, s1, s2;
	int h, s, m;
	cout << endl << "h1= ";
	cin >> h1;
	cout << endl << "m1= ";
	cin >> m1;
	cout << endl << "s1= ";
	cin >> s1;
	cout << endl << "h2= ";
	cin >> h2;
	cout << endl << "m2= ";
	cin >> m2;
	cout << endl << "s2= ";
	cin >> s2;

	A1(h1, m1, s1, h2, m2, s2, &h, &m, &s);

	cout << "Output: " << h << "h " << m << "m " << s << "s" << endl;

	return;
}
void A2_face(){
	float a;
	cout << "a = ";
	cin >> a;
	float z1, z2;
	A2(a, &z1, &z2);
	cout << "Output: " << z1 << " " << z2 << endl;
	return;
}
void A3_face(){
	cout << "Ax^2 + Bx + C = 0" << endl;
	cout << "A= ";
	double A;
	cin >> A;
	cout << "B= ";
	double B;
	cin >> B;
	cout << "C= ";
	double C;
	cin >> C;
	double x1, x2;
	bool c;
	A3(A, B, C, &x1, &x2, &c);
	cout << "Output: " << endl;
	if (c)
	{
		cout << "x1= " << x2 << "+ i" << x1 << endl;
		cout << "x2= " << x2 << "- i" << x1 << endl;
	}
	else
	{
		if (x1 == x2)
		{
			cout << "x= " << x1 << endl;
		}
		else
		{
			cout << "x1= " << x1 << endl;
			cout << "x2= " << x2 << endl;
		}
	}
	return;
}
void A4_face(){
	double x, y;
	cout << "x= ";
	cin >> x;
	cout << "y= ";
	cin >> y;
	cout << "Output: " << A4(x, y) << endl;
	return;
}
void A5_face(){
	unsigned a;
	cout << "Day= ";
	cin >> a;
	cout << "Output: " << A5(a) << endl;
	return;
}
void A6_face(){
	int d, m, y, c;
	cout << "d= ";
	cin >> d;
	cout << "m= ";
	cin >> m;
	cout << "y= ";
	cin >> y;
	cout << "c= ";
	cin >> c;
	cout << "Output: " << A6(d, m, y, c) << endl;
	return;
}
void A7_face(){
	int a = 0;
	cout << "Input= ";
	cin >> a;
	cout << "Output: ";
	cout << A7(a);
	return;
}
void AL1_face(){
	cout << "Output: " << endl;
	AL1();
	return;
}
void AL2_face(){
	unsigned n;
	double x;
	cout << "x= ";
	cin >> x;
	cout << "n= ";
	cin >> n;
	cout << "Output: " << AL2(x, n) << endl;
	return;
}
void AL3_face(){
	float n;
	cout << "accuracy= ";
	cin >> n;
	cout << "Output: " << AL3(n) << endl;
	return;
}
void AL4_face(){
	double x1, x2, dx, e;
	cout << "x1= ";
	cin >> x1;
	cout << "x2= ";
	cin >> x2;
	cout << "dx= ";
	cin >> dx;
	cout << "e= ";
	cin >> e;
	cout << "Output: " << endl;
	AL4(x1, x2, dx, e);
	return;
}
void AL5_face(){
	unsigned k, m;
	float p, g, fast;
	cout << "Amount of credit($)= ";
	cin >> k;
	cout << "Percentage(%)= ";
	cin >> p;
	cout << "Years= ";
	cin >> g;
	cout << "Months= ";
	cin >> m;
	cout << "Do you want repay faster?(0 if NO) Years= ";
	cin >> fast;
	cout << "Output: " << endl;
	AL5(k, p, g, m, fast);
	return;
}
void AL6_face(){
	int arr[20];
	for (unsigned i = 0; i < 20; i++)
	{
		cout << "[" << i << "]= ";
		cin >> arr[i];
	}
	AL6(arr);
	cout << "Output: ";
	for (unsigned i = 0; i < 20; i++)
	{
		cout << "[" << i << "]= " << arr[i];
	}
	return;
}
void AL7_face(){
	cout << "m= ";
	unsigned m;
	cin >> m;
	cout << "Output: " << AL7(m) << endl;
	return;
}
void AL8_face(){
	cout << "n= ";
	unsigned n;
	cin >> n;
	double *arr = new double[n];
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "]= ";
		cin >> arr[i];
	}
	cout << "Output: " << endl;
	AL8(arr, n);
	delete[] arr;
	return;
}
void S1_face(){
	string s;
	cin >> s;
	cout << "Output: " << S1(s) << endl;
	return;
}
void S2_face(){
	string s;
	unsigned A, B;
	cout << "X= ";
	cin >> s;
	cout << "A= ";
	cin >> A;
	cout << "B= ";
	cin >> B;
	if (A == B)
	{
		cout << s << endl;
	}
	else
	{
		if (A*A + B*B <= 2)
		{
			cout << "ERROR, task closing...\n";
			return;
		}
		else
		{
			cout << "Output: " << S2(s, A, B) << endl;
		}
	}
	return;
}
void S3_face(){
	string s;
	cin >> s;
	cout << "Output: " << S3(s) << endl;
	return;
}
void S4_face(){
	char *s;
	cout << "Rom number= ";
	cin >> s;
	cout << "Output: " << S4(s) << endl;
	return;
}
void S5_face(){
	string s;
	cout << "Sequence= ";
	cin >> s;
	int arr[2];
	S5(s, arr);
	cout << "Output: Max '0' sequence= " << arr[0] << " from " << arr[1] << " position." << endl;
	return;
}
void F1_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Output: " << F1(s) << endl;
	return;
}
void F2_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Output: " << endl;
	F2(s);
	return;
}
void F3_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Output: " << endl;
	F3(s);
	return;
}
void F4_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Word= ";
	string find;
	cin >> find;
	cout << "Output: \n";
	F4(s, find);
	return;
}
void F5_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Need find= ";
	string find;
	cin >> find;
	cout << "Output: " << F5(s, find) << endl;
	return;
}
void F6_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Output: " << endl;
	F6(s);
	return;
}
void F7_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Output: " << endl;
	F7(s);
	return;
}
void F8_face(){
	string in, out;
	cout << "Input file name = ";
	cin >> in;
	fstream check_file;
	check_file.open(in);
	if (check_file.is_open())
	{
		cout << "Output file name = ";
		cin >> out;
		cout << "Output: ";
		F8(in, out);
	}
	return;
}
void F10_face(){
	string s, s1;
	cout << "Input file name= ";
	cin >> s;
	cout << "Output file name= ";
	cin >> s1;
	cout << "Output: " << endl;
	F10(s, s1);
	return;
}
void F9_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Output: " << endl;
	F9(s);
	return;
}
void F11_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Output: \n-----------Start reading.-----------\n";
	F11(s);
	return;
}
void F12_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Output: " << endl;
	F12(s);
	return;
}
void F13_face()
{
	string file_in_name;
	bool choose = 0;
	cout << "Cut(0) or repair(1)?\n = ";
	cin >> choose;
	cout << "Input file name = ";
	cin >> file_in_name;
	if (choose)
	{
		cout << "Output: ";
		F13_2(file_in_name);
	}
	else
	{
		cout << "Capasity = ";
		string temp;
		cin >> temp;
		if (temp[temp.length() - 1] == 'K')
		{
			temp.pop_back();
			long m = atol(temp.c_str());
			if (m <= 0)
			{
				cout << "Wrong capasity\n";
			}
			else
			{
				m *= 1024;
				cout << "Output: ";
				F13_1(file_in_name, m);
			}
		}
		else
		{
			long m = atol(temp.c_str());
			if (m <= 0)
			{
				cout << "Wrong capasity\n";
			}
			else
			{
				cout << "Output: ";
				F13_1(file_in_name, m);
			}
		}
	}
	return;
}
void F14_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Output: " << endl;
	cout << "--------------Start-----------------\n";
	F14(s);
	return;
}
void F15_face(){
	string file_in_name, file_out_name;
	bool chose = 0;
	cout << "Encrypt (0) or decrypt(1)?\n = ";
	cin >> chose;
	cout << "Input file name = ";
	cin >> file_in_name;
	fstream check_file;
	check_file.open(file_in_name);
	if (check_file.is_open())
	{
		cout << "Output file name = ";
		cin >> file_out_name;
		cout << "Output: ";
		if (chose)
		{
			F15_2(file_in_name, file_out_name);
		}
		else
		{
			F15_1(file_in_name, file_out_name);
		}
	}
	else
	{
		cout << "Output: " << "File '" << file_in_name << "'not found.\n";
	}
	return;
}
void F16_face(){
	string file_in_name, file_out_name;
	bool chose = 0;
	cout << "Encrypt (0) or decrypt(1)?\n = ";
	cin >> chose;
	cout << "Input file name = ";
	cin >> file_in_name;
	fstream check_file;
	check_file.open(file_in_name);
	if (check_file.is_open())
	{
		cout << "Output file name = ";
		cin >> file_out_name;
		cout << "Output: ";
		if (chose)
		{
			F16_2(file_in_name, file_out_name);
		}
		else
		{
			F16_1(file_in_name, file_out_name);
		}
	}
	else
	{
		cout << "Output: " << "File '" << file_in_name << "'not found.\n";
	}
	return;
}
void F17_face(){
	string s;
	cout << "File name= ";
	cin >> s;
	cout << "Output: ";
	if (F17(s))
		cout << "It's XML file" << endl;
	else
		cout << "It's not XML file" << endl;
	return;
}
void SRT1_face(){
	unsigned n;
	cout << "Number of array's elements = ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	SRT1(arr, n);
	cout << "Output: " << endl;
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = " << arr[i] << " ";
	}
	delete[] arr;
	return;
}
void SRT2_face(){
	unsigned n;
	cout << "Number of array's elements = ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	SRT2(arr, n);
	cout << "Output: " << endl;
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = " << arr[i] << " ";
	}
	delete[] arr;
	return;
}
void SRT3_face(){
	unsigned n;
	cout << "Number of array's elements = ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	SRT3(arr, n);
	cout << "Output: " << endl;
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = " << arr[i] << " ";
	}
	delete[] arr;
	return;
}
void SRT4_face(){
	unsigned n;
	cout << "Number of array's elements = ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n;i++)
	{ 
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	SRT4(arr, n);
	cout << "Output: " << endl;
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = " << arr[i] << " ";
	}
	delete[] arr;
	return;
}
void SRT5_face(){
	unsigned n;
	cout << "Number of array's elements = ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	n = SRT5(arr, n);
	cout << "Output: " << endl;
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = " << arr[i] << " ";
	}
	delete[] arr;
	return;
}
void SRT6_face(){
	unsigned n;
	cout << "Number of array's elements = ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	cout << "Need find = ";
	int find;
	cin >> find;
	int ans = SRT6(arr, find, n);
	delete[] arr;
	cout << "Output: ";
	if (ans == -1)
	{
		cout << "element not found." << endl;
	}
	else
	{
		cout << ans << endl;
	}
	return;
}
void SRT7_face(){
	unsigned n;
	cout << "Number of array's elements = ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	n = SRT7(arr, n);
	cout << "Output: " << n << endl;
	delete[] arr;
	return;
}
void SRT8_face(){
	unsigned n;
	cout << "Number of array's elements = ";
	cin >> n;
	int *arr = new int[n];
	for (unsigned i = 0; i < n; i++)
	{
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
	cout << "Output: " << endl;
	SRT8(arr, n);
	delete[] arr;
	return;
}
void SRT9_face(){
	string file_name;
	cout << "Input file name = ";
	cin >> file_name;
	cout << "Output: " << endl;
	SRT9(file_name);
	return;
}