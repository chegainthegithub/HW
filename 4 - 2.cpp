#include <iostream>
#include <fstream>
using namespace std;
void func(char *argv[])
{
	char numerals[10][7] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nein" };
	char chr;
	ifstream fin(argv[1]);
	char symb;
	while (true)
	{
		fin.get(symb);
		if ((symb >= '0') && (symb <= '9'))
		{
			for (int j = 0; j < 10; j++)
				if (symb - '0' == j)
				{
				cout << numerals[j];
				}
		}
		else
			if ((symb >= 'a') && (symb <= 'z'))
			{
			chr = symb - 32;
			cout << chr;
			}
			else
				if ((symb >= 'A') && (symb <= 'Z'))
				{
			      chr = symb + 32;
				  cout << chr;
				}
				else
					cout << symb;
		if (fin.eof() == true)
			break;
	}
	fin.close();
}
int main(int argc, char* argv[])
{
	func( argv );
	system("pause");
	return 0;
}