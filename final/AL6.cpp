#include <iostream>
using namespace std;
int main() {
	int const N = 20;
	double T[N];
	for (int i = 0; i < N; ++i)
		cin >> T[i];
	for (int i = 0; i < N/2; ++i)
		swap(T[i], T[N - 1 - i]);
	for (int i = 0; i < N; ++i)
		cout << T[i];
}