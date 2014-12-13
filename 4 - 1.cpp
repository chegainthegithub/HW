#include <iostream>
#include <fstream>
using namespace std;
float func(char *argv[])
{
	char chr;
	ifstream fin(argv[1]);
	int num = 0;
	float sum = 0;
	int length = 0;
	while (!fin.eof())
	{
	 fin >> num;
		 length++;
		 cout << num << endl;
		 cout << "(" << length << ")" << endl;
	}
	fin.close();
	fin.open(argv[1]);
	cout << "==============" << endl;
	while (!fin.eof())
	{
		fin >> num;
		cout << num << endl;
		sum = sum + num *1.0 / (length*1.0);
	}
	fin.close();
	return (sum);
}
int main(int argc, char* argv[])
{
	cout << func(argv) << endl;
	system("pause");
	return 0;
}