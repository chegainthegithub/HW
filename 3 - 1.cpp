#include <iostream>
using namespace std;
int func()
{
	char *arr1 = new char[255];
	cin.getline(arr1, 255);
	char *arr2 = new char[strlen(arr1) + 1];
	strcpy(arr2, arr1);
	delete [] arr1;
	cout<<arr2<<endl;
	for (int i = 0; i < strlen(arr2); i++)
	{
		cout << arr2[i] << endl;
		if ((arr2[i] != '1') && (arr2[i] != '0'))
			return 0;
	}
	return 1;
}
void func2(int i)
{
	if (i == 0)
		cout << "nope" << endl;
	else
		cout << "yep" << endl;
}
int main()
{
	func2(func());
}