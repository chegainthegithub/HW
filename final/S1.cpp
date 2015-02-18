#include <iostream>
#include <string>
using namespace std;
int main() {
	string a;
	cin >> a;
	int b = a.length()+1;
	char*pa = new char[b + 1];
	strcpy(pa, a.c_str());
	for (int i = 0; i < b; ++i) {
		if (pa[i] == '\0') {
			cout << "true" << endl;
			break;
		}
		if ((pa[i] != 48) && (pa[i] != 49)) {
			cout << "false" << endl;
			break;
		}
	}
}