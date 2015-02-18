#include <iostream>
#include <fstream>
#include <iostream>;
using namespace std;
int main(int argc, char*argv[]) {
	char c;
	int k = 0;
	fstream fs("1.txt");
	if (fs.is_open() == false) {
		cout << "not open";
	}
	while (fs.eof() == false) {
		fs.get(c);
		if (fs.eof()) break;
		++k;
	}
	fs.close();
	fstream fs1("1.txt");
	char*pa = new char[k];
	for (int i = 0; i < k; ++i)
		fs1.get(pa[i]);
	fs1.close();
	for (int i = 0; i < k; ++i) {
		if (((pa[i] >= 65) && (pa[i] <= 90)) || ((pa[i] >= 65) && (pa[i] <= 122)) || ((pa[i] >= 48) && (pa[i] <= 57))) {
			if ((pa[i] >= 65) && (pa[i] <= 90)) {
				pa[i] = pa[i] + 32;
				cout << pa[i];
			}
			else
			if ((pa[i] >= 97) && (pa[i] <= 122)) {
				pa[i] = pa[i] - 32;
				cout << pa[i];
			}
			if (pa[i] == '0')
				cout << "zero";
			if (pa[i] == '1')
				cout << "one";
			if (pa[i] == '2')
				cout << "two";
			if (pa[i] == '3')
				cout << "three";
			if (pa[i] == '4')
				cout << "four";
			if (pa[i] == '5')
				cout << "five";
			if (pa[i] == '6')
				cout << "six";
			if (pa[i] == '7')
				cout << "seven";
			if (pa[i] == '8')
				cout << "eight";
			if (pa[i] == '9')
				cout << "nine";
		}
		else
			cout << pa[i];
	}
	return 0;
}