#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char m[256];
	cin >> m;
	char c;
	int k = 0;
	fstream fs("F4.txt");
	while (fs.eof() == false) {
		fs.get(c);
		if (fs.eof()) break;
		++k;
	}
	fs.close();
	char*pa = new char[k];
	fstream fs1("F4.txt");
	for (int i = 0; i < k; ++i)
		fs1.get(pa[i]);
	fs1.close();
	int j = 0;
	int l = 0;
	int i1 = 0;
	int i2 = 0;
	for (int i = 0; i < k+1; ++i) {
		if ((pa[i] != '\n') && (i != k)) {
			if (((pa[i] >= 65) && (pa[i] <= 90)) || ((pa[i] >= 97) && (pa[i] <= 122))) {
				if ((m[j] == pa[i]) || (m[j] == pa[i] + 32)) {
					++j;
					if (((pa[i + 1] < 65) || (pa[i + 1] > 90)) && ((pa[i + 1] < 97) || (pa[i + 1] > 122)) && (m[j] == '\0')) {
						++l;
					}
				}
				else
					j = 0;
			}
		}
		else {
			i2 = i;
			if (l > 0) {
				j = 0;
				l = 0;
				for (; i1 < i2; ++i1)
					cout << pa[i1];
				cout << endl;
			}
			i1 = i2 + 1;
		}
	}
	delete[] pa;
	return 0;
}