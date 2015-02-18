#include <iostream>;
#include <fstream>;
using namespace std;
int main(int argc, char*argv[]) {
	char a;
	fstream fs;
	fs.open(argv[1], ios_base::in|ios_base::binary);
	while (fs.eof() == false) {
		fs.get(a);
		if (fs.eof()) break;
		cout << a;
	}
	fs.close();
	return 0;
}