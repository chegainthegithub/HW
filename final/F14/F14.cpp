#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void F11(string file_name){
	fstream file;
	file.open(file_name, ios_base::in | ios_base::binary);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	char a;
	unsigned i = 0;
	unsigned j = 0;
	while (1)
	{
		file.get(a);
		if (a == 10)
		{
			i++;
		}
		if (!(i % 26))
		{
			cin.get();
			i = 1;
		}
		cout << a;
		if (file.eof()) break;
	}
	file.close();
	return;
}
void F14(string file_name){
	fstream file;
	file.open(file_name, ios_base::in | ios_base::binary);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	string list;
	list = file_name + ".list.txt";
	fstream file_out;
	file_out.open(list, ios_base::out | ios_base::trunc);
	char c;
	unsigned i = 0;
	file_out << 0 << "\t" << hex;
	while (1)
	{
		file.get(c);
		if (file.eof()) break;
		i++;
		if (((int)c & 0xff) < 0x10)
			file_out << "0" << ((int)c & 0xff) << " ";
		else
			file_out << ((int)c & 0xff) << " ";
		if (!(i % 16))
		{
			file_out << endl << dec << i << "\t" << hex;
		}
	}
	file.close();
	file_out.close();
	cout << "------------File created------------\n";
	F11(list);
	return;
}
int main(int argc, char*argv[]){
	string s = argv[1];
	cout << "--------------Start-----------------\n";
	F14(s);
	return 0;
}