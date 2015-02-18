#include <iostream>
#include <clocale>
#include <string>
using namespace std;
void S5(string text, int *retUrn)
{
	unsigned max = 0, position = 0;
	unsigned current = 0;
	unsigned i = 0;
	while (i < text.size()) {
		if (text[i] == '0') {
			current++;
		}
		if (text[i] == '1') {
			if (current > max) {
				max = current;
				position = i - current;
			}
			current = 0;
		}
		i++;
	}
	if (current > max) {
		max = current;
		position = i - current;
	}
	retUrn[0] = max;
	retUrn[1] = position;
}

int main(){
	setlocale(LC_ALL, "rus");
	string s;
	cin >> s;
	int arr[2];
	S5(s, arr);
	cout << "ћаксимальное количество нулей " << arr[0] << "  " << arr[1] << " позици€" << endl;
	return 0;
}