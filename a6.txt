#include <iostream>
#include <string>
using namespace std;
string weekday(int a)
{
	int arr1[7] = { 1, 2, 3, 4, 5, 6, 0 };
	string arr2[7] = { "mon", "tues", "wed", "thu", "fr", "sat", "sun" };
	for (int i = 0; i < 7; i++)
		if (arr1[i] == a)
			return arr2[i];
	return "error";
}

void calculatetheday(int a)
{
	cout << "the day is - " << weekday(a) << endl;
}
int calculation(int day, int month, int year,int century)
{
	int localmonth = (13*((month + 10) % 12)-1)/5;
	int localyear = year / 4;
	int localcentury = century / 4;
	return ((day + localmonth + year + localyear + localcentury - 2 * century + 777) % 7);
}
int main()
{
	int day, month, year, century;
	cout << "input the date , pls:" << endl;
	cout << "day :"; cin >> day; cout << endl;
	cout << "month :"; cin >> month; cout << endl;
	cout << "year :"; cin >> year; cout << endl;
	cout << "century :"; cin >> century; cout << endl;
	calculatetheday(calculation(day, month, year, century));
}