#include <iostream>
#include <string>
using namespace std;
string weekday(int a)
{
	int arr1[7] = { 1, 2, 3, 4, 5, 6, 7 };
	string arr2[7] = { "mon", "tues", "wed", "thu", "fr", "sat", "sun" };
	for (int i = 0; i < 7; i++)
		if (arr1[i] == a)
			return arr2[i];
	return "error";
}
int main()
{
	int a;
	cin >> a;
	cout << weekday(a) << endl;
}