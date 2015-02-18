#include <iostream>;
#include <fstream>;
using namespace std;
int main(int argc, char*argv[]) {
	fstream fs(argv[1]);
	int i = 0;
	char c;
	while (fs.eof() == false) {
		fs.get(c);
		if (fs.eof()) break;
		i++;
	}
	fs.close();
	char* ch = new char[i];
	fstream fs1(argv[1]);
	for (int j = 0; j < i; j++)
		fs1.get(ch[j]);
	int k = 0, k1 = 0;
	int l = 0, p = 0;
	int f = 0;
	for (int j = 0; j < i; j++) {
		l = j;
		while (((ch[j] >= 65) && (ch[j] <= 90)) || ((ch[j] >= 97) && (ch[j] <= 122))) {
			k++;
			++j;
		}
		if (k>k1) k1 = k;
		k = 0;
	}

	char* ch1 = new char[k1];
	for (int j = 0; j < i; j++) {
		l = j;
		while (((ch[j] >= 65) && (ch[j] <= 90)) || ((ch[j] >= 97) && (ch[j] <= 122))) {
			++j;
			k++;
		}
		if (k == k1) {
			for (; l < j; l++) {
				ch1[f] = ch[l];
				++f;
			}
		}
		f = 0;
		k = 0;
	}
	for (int i = 0; i < k1; i++)
		cout << ch1[i];
	cout << endl;
	int r = 0;
	int z = 0;
	for (int j1 = 0; j1 < i; j1++) {
		if (((ch[j1] >= 65) && (ch[j1] <= 90)) || ((ch[j1] >= 97) && (ch[j1] <= 122))) {
			if ((ch1[z] == ch[j1]) || (ch1[z] == ch[j1] + 32)) {
				z++;
				if (((ch[j1 + 1]<65) || (ch[j1 + 1]>90)) && ((ch[j1 + 1] < 97) || (ch[j1 + 1] > 122))
					&& (((ch1[z]<65) || (ch1[z]>90)) && ((ch1[z] < 97) || (ch1[z] > 122)))) {
					r++;
					z = 0;
				}
			}
			else z = 0;
		}
	}
	cout << "Kolichestvo povtorenii " << r << endl;
	return 0;
}