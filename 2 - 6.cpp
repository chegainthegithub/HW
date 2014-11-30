#include <ctime>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string arr[20];
void input()
{
	for (int i = 0; i <20; i++)
		cin >> arr[i];
}
void change()
{
	string a;
	for (int i = 0; i < 10; i++)
	{
		a = arr[i];
		arr[i] = arr[19 - i];
		arr[19 - i] = a;
	}
}
void output()
{
	for (int i = 0; i < 20; i++)
		cout << arr[i] << endl;
}
int main()
{
	input();
	change();
	output();
}