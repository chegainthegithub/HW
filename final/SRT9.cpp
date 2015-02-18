#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int strsr(string a, string b){
	int n;
	if (a.length() < b.length())n = a.length();
	else n = b.length();
	int j = 0;
	while (j < n & a[j] == b[j])j++;
	if (j == n){
		if (a.length() >= b.length())return 1;
		else return 2;
	}
	else{
		if (a[j] >= b[j])return 1;
		else return 2;
	}

}
void strswap(string &a, string &b){
	string c = a;
	a = b;
	b = c;
}
void merge(string *str, size_t l, size_t r, size_t m){
	size_t i1 = l;
	size_t i2 = m + 1;
	int in = 0;
	string *a = new string[r - l + 1];
	while ((i1 <= m)&(i2 <= r)){
		if (strsr(str[i1], str[i2]) == 2){
			a[in] = str[i1];
			i1++;
		}
		else{
			a[in] = str[i2];
			i2++;
		}
		in++;
	}
	while (i1 <= m){
		a[in] = str[i1];
		i1++;
		in++;
	}
	while (i2 <= r){
		a[in] = str[i2];
		i2++;
		in++;
	}
	for (int i = l; i <= r; ++i){
		str[i] = a[i - l];
	}
	delete[]a;
}
void MergeSort(string *str, size_t l, size_t r)
{
	//! Условие выхода из рекурсии
	if (l >= r) return;

	size_t m = (l + r) / 2;

	//! Рекурсивная сортировка полученных массивов
	MergeSort(str, l, m);
	MergeSort(str, m + 1, r);
	merge(str, l, r, m);
}
void nineask(){
	cout << "Write file name" << endl;
	string filename;
	cin >> filename;
	fstream file(filename);
	if (file.is_open() == false){
		cout << "file not found" << endl;
		return;
	}
	int a;
	//опр колва строк
	int n = 0;
	int le = 0;
	while (true){
		a = file.get();
		if (a == (int)'\n'){
			n++;
			le = 0;
		}
		else le++;
		if (a == EOF){
			if (le > 1)n++;
			break;
		}
	}
	file.close();
	file.open(filename);
	string *m = new string[n];
	for (int i = 0; i < n; ++i){
		getline(file, m[i]);
	}
	for (int i = 0; i < n; ++i){
		cout << m[i] << endl;
	}
	cout << "==================================" << endl;
	fstream out("out.txt", ios_base::trunc | ios_base::out);
	MergeSort(m, 0, n - 1);
	for (int i = 0; i < n; ++i){
		cout << m[i] << endl;
	}
	for (int i = 0; i < n; ++i){
		out << m[i] << endl;
	}
	file.close();
	out.close();
}
int main(){
	nineask();
}