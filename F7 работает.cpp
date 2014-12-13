#include <iostream>
#include <fstream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	fstream fs("F7.txt");
	int n = 0;
	char c;
	while (true) {
		if (fs.eof()) break;
		fs.get(c);
		n++;
	}
	char *m = new char[n];
	char *m1 = new char[n];
	fs.close();
	fstream fs1("F7.txt");
	for (int i = 0; i < n; i++)
		fs1.get(m[i]);
	int l = 0, k = 0, q = 0;
	for (int i = 0; i < n; i++) {
		if (m[i] == '.' || m[i] == '!' || (m[i] == '.' && m[i - 1] == '.' && m[i - 2] == '.')) {
			q = i + 1;
		}

		if (m[i] == '?') {
			for (int j = q; j <= i; j++)
				m1[j] = m[j];
			for (int h = q; m1[h] != '?'; h++)
				cout << m1[h];
			q = i + 1;
			cout << "?";
		}

	}
	cout << endl;
	return 0;
}