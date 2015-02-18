#include <iostream>
#include <fstream>
#include <string>
using namespace std;
unsigned Getfilesize(fstream *file)
{
	if ((*file).is_open())
	{
		unsigned y = (*file).tellg();
		(*file).seekg(0, (*file).end);
		unsigned x = (*file).tellg();
		(*file).seekg(y, ios_base::beg);
		return x;
	}
	return 0;
}
void F13_1(string file_name, unsigned n)
{
	fstream file;
	file.open(file_name, ios_base::in | ios_base::binary);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return;
	}
	fstream file_s;
	unsigned long filesize = Getfilesize(&file);
	unsigned long curr_file_n = 0;
	char c;
	while (filesize > 0)
	{
		string files_name = file_name + '.';
		files_name += to_string(curr_file_n);
		file_s.open(files_name, ios_base::out | ios_base::trunc | ios_base::binary);
		unsigned long i = 0;
		while (filesize > 0 && i < n)
		{
			file.get(c);
			if (file.eof()) break;
			file_s << c;
			i++;
			filesize--;
		}
		curr_file_n++;
		file_s.close();
	}
	file.close();
	remove(file_name.c_str());
	cout << "Done.";
	return;
}

void F13_2(string file_name)
{
	fstream file;
	file.open(file_name, ios_base::out | ios_base::trunc | ios_base::binary);
	unsigned long curr_file_n = 0;
	char c;
	while (1)
	{
		fstream file_in;
		string files_name = file_name + '.';
		files_name += to_string(curr_file_n);
		file_in.open(files_name, ios_base::in | ios_base::binary);
		if (file_in.is_open() != true)
			break;
		while (1)
		{
			file_in.get(c);
			if (file_in.eof())
			{
				file_in.close();
				remove(files_name.c_str());
				curr_file_n++;
				break;
			}
			file << c;
		}
	}
	file.close();
	cout << "Done.";
	return;
}
int main(int argc, char*argv[]) {
	string file_in_name = argv[1];
	bool choose = 0;
	cout << "Cut(0) or repair(1)?\n = ";
	cin >> choose;
	if (choose)
	{
		cout << "Output: ";
		F13_2(file_in_name);
	}
	else
	{
		cout << "Capasity = ";
		string temp;
		cin >> temp;
		if (temp[temp.length() - 1] == 'K')
		{
			temp.pop_back();
			long m = atol(temp.c_str());
			if (m <= 0)
			{
				cout << "Wrong capasity\n";
			}
			else
			{
				m *= 1024;
				cout << "Output: ";
				F13_1(file_in_name, m);
			}
		}
		else
		{
			long m = atol(temp.c_str());
			if (m <= 0)
			{
				cout << "Wrong capasity\n";
			}
			else
			{
				F13_1(file_in_name, m);
			}
		}
	}
	return 0;
}