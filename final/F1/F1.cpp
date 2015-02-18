#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char*argv[]) {
	double b = 0;
	int i = 0;
	fstream fs;
	fs.open(argv[1]);
	while (fs.eof() == false) { 
		fs >> b;
		++i;
	}
	double buffer,sum= 0;
	fs.close(); 
	fs.open(argv[1]);
	double sr = 0;
	for (int j = 0; j < i; ++j)
	{
		fs >> buffer;
		sum = sum + buffer / i;
	}
	cout << sum << endl;
	fs.close();
	return 0;
}