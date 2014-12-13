#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double sum = 0, sr = 0, m[100];
	int i = 0;
	fstream fs("F1.txt");
	if (fs.is_open() == false)
		cout << "Файл не открыт!" << endl;
	while (fs.eof() == false)
	{
		fs >> m[i];
		i++;
	}
	for (int j = 0; j < i; j++)
	{
		sum = sum + m[j];
	}
	sr = sum / i;
	cout << "Среднее арифметическое = " << sr << endl;
	fs.close();
	return 0;
}