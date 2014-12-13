#include <iostream>;
#include <fstream>;
#include <string>
using namespace std;
int main() {
	fstream fs;
	fs.open("F9.txt");
	int k = 0, n = 0;
	char c;
	while (fs.eof() == false) {
		fs.get(c);
		if (c == '\n' || fs.eof() == true) k++;
		if (fs.eof()) break;
	}
	string*a = new string[k];
	fs.close();
	cout << k << endl;
	int*m = new int[k];
	fs.open("F9.txt");
	int i = 0;
	while (fs.eof() == false) {
		for (int i = 0; i < k; ++i) {
			c = ' ';
			while (c != '\n') {
				fs.get(c);
				if (fs.eof()) break;
				a[i] = a[i] + c;
				n++;
			}
			m[i] = n;
			n = 0;
		}
		if (fs.eof()) break;
		fs.get(c);
	}
	fs.close();
	fs.open("F9.txt", ios_base::out|ios_base::trunc);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < (40 - m[i] / 2); ++j)
			fs << ' ';
		fs << a[i];
	}
	fs.close();
	return 0;
}
