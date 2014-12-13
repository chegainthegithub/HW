#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char c;
	int n = 0, t = 0, m = 0;
	int k = 0;
	fstream fs;
	fs.open("F12.txt");
	if (fs.is_open() == false)
		cout << "not open";
	else {
		while (fs.eof() == false) {
			fs.get(c);
			if (fs.eof() == true) break;
			++k;
		}
		fs.close();
		fs.open("F12.txt");
		char* ch = new char[k];
		for (int i = 0; i < k; ++i)
			fs.get(ch[i]);
		fs.close();
		for (int i = 0; i < k; i++) if (ch[i] == '(') n++;
		m = n;
		char s1[4] = { '{', '(', '[', '\0' };
		char s2[4] = { '}', ')', ']', '\0' };
		int j = 0, j1 = 0;
		bool a = 0, b = 0;
		for (int i = 0; i < k; i++) {
			if (ch[i] == '(') {
				if (a == 0) {
					j++;
					if (j == 3) j = 0;
				}
				ch[i] = s1[j];
				a = 0;
			}
			if (ch[i] == ')') {
				if (a == 1) {
					j--;
					if (j == -1) j = 2;
				}
				ch[i] = s2[j];
				a = 1;
			}
		}
		fs.open("F12.txt", ios_base::out | ios_base::trunc);
		for (int i = 0; i < k; i++)
			fs << ch[i];
		fs.close();
	}
	return 0;
}