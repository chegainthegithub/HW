#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char*argv[]) {
	char c;
	int k = 0;
	fstream fs;
	fs.open(argv[1]);
	while (fs.eof() == false) {
		fs.get(c);
		if (fs.eof()) break;
		++k;
	}
	fs.close();
	char*pa = new char[k];
	fs.open(argv[1]);
	for (int i = 0; i < k; ++i)
		fs.get(pa[i]);
	fs.close();
	for (int i = 0; i < k; ++i) {
		if ((pa[i] == '/') && (pa[i + 1] == '/')) {
			while (pa[i] != '\n') {
				pa[i] = 0;
				++i;
			}
		}
		if ((pa[i] == '/') && (pa[i + 1] == '*')) {
			while ((pa[i] != '*') || (pa[i+1] != '/')) {
				if ((pa[i + 1] == '*') && (pa[i + 2] == '/')) {
					pa[i] = 0;
					pa[i + 1] = 0;
					pa[i + 2] = 0;
						break;
				}
				pa[i] = 0;
				++i;
				if (fs.eof()) break;
			}
		}
	}
	fs.open(argv[1], ios_base::out|ios_base::trunc);
	for (int i = 0; i < k; ++i)
		fs << pa[i];
	fs.close();
}