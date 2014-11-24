#include <ctime>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string arr[20];
string input()
{
	for (int i = 0; i <20; i++)
		cin >> arr[i];
	return arr;
}
string compare()
{
	string a;
	for (int i = 0; i < 10; i++)
	{
		a = arr[i];
		arr[i] = arr[19 - i];
		arr[19 - i] = a;
	}
	return arr;
}
string output()
{
	cout << arr;
}
int main()
{
	input();
	compare();
	output();
}