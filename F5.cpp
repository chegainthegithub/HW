#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char m[256];
	cin >> m;
	char c;
	int k = 0;
	fstream fs("F5.txt");
	while (fs.eof() == false) {
		fs.get(c);
		if (fs.eof()) break;
		++k;
	}
	fs.close();
	char*pa = new char[k];
	fstream fs1("F5.txt");
	for (int i = 0; i < k; ++i)
		fs1.get(pa[i]);
	fs1.close();
	int j = 0;
	int l = 0;
	for (int i = 0; i < k + 1; ++i) {
			if (((pa[i] >= 65) && (pa[i] <= 90)) || ((pa[i] >= 97) && (pa[i] <= 122))) {
				if ((m[j] == pa[i]) || (m[j] == pa[i] + 32)) {
					++j;
					if (((pa[i + 1] < 65) || (pa[i + 1] > 90)) && ((pa[i + 1] < 97) || (pa[i + 1] > 122)) && (m[j] == '\0')) {
						++l;
						j = 0;
					}
				}
				else
					j = 0;
			}
	}
	cout << l;
	delete[] pa;
	return 0;
}