#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
void DES(unsigned char *in, unsigned char *out)
{
	int table[] = {
		58, 50, 42, 34, 26, 18, 10, 2,
		60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6,
		64, 56, 48, 40, 32, 24, 16, 8,
		57, 49, 41, 33, 25, 17, 9, 1,
		59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5,
		63, 55, 47, 39, 31, 23, 15, 7
	};
	for (int i = 0; i < 8; i++) out[i] = 0;
	int k = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((in[(table[8 * k + j] - 1) / 8] & (int)pow(2, 7 - (table[8 * k + j] - 1) % 8)) != 0)
			{
				out[i] = out[i] | (int)pow(2, (8 - j - 1));
			}
		}
		k++;
	}
	return;
}


void deDES(unsigned char *in, unsigned char *out)
{
	int table[] = {
		40, 8, 48, 16, 56, 24, 64, 32,
		39, 7, 47, 15, 55, 23, 63, 31,
		38, 6, 46, 14, 54, 22, 62, 30,
		37, 5, 45, 13, 53, 21, 61, 29,
		36, 4, 44, 12, 52, 20, 60, 28,
		35, 3, 43, 11, 51, 19, 59, 27,
		34, 2, 42, 10, 50, 18, 58, 26,
		33, 1, 41, 9, 49, 17, 57, 25,
	};
	for (int i = 0; i < 8; i++) out[i] = 0;
	int k = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((in[(table[8 * k + j] - 1) / 8] & (int)pow(2, 7 - (table[8 * k + j] - 1) % 8)) != 0)
			{
				out[i] = out[i] | (int)pow(2, (8 - j - 1));
			}
		}
		k++;
	}
	return;
}

void F16_1(string file_in_name, string file_out_name)
{
	fstream file_in;
	fstream file_out;
	file_in.open(file_in_name, ios_base::in | ios_base::binary);
	file_out.open(file_out_name, ios_base::out | ios_base::trunc | ios_base::binary);
	if (file_in.is_open() != true)
	{
		cout << "File '" << file_in_name << "' not found." << endl;
		return;
	}
	char c;
	unsigned i = 0;
	unsigned char a[8], b[8];
	while (1)
	{
		(file_in).get(c);
		if ((file_in).eof())
		{
			if (i != 0)
			{
				for (unsigned j = i + 1; j < 8; j++)
					a[j] = 0;
				for (unsigned j = 0; j < 8; j++)
					b[j] = 0;
				DES(a, b);
				for (unsigned n = 0; n < 8; n++)
					file_out << b[n];
			}
			break;
		}
		a[i] = c;
		i++;
		if (i == 8)
		{
			i = 0;
			for (unsigned j = 0; j < 8; j++)
				b[j] = 0;
			DES(a, b);
			for (unsigned n = 0; n < 8; n++)
				file_out << b[n];
		}
	}
	file_in.close();
	file_out.close();
	cout << "Encryption done.\n";
	return;
}

void F16_2(string file_in_name, string file_out_name)
{
	fstream file_in;
	fstream file_out;
	file_in.open(file_in_name, ios_base::in | ios_base::binary);
	file_out.open(file_out_name, ios_base::out | ios_base::trunc | ios_base::binary);
	if (file_in.is_open() != true)
	{
		cout << "File '" << file_in_name << "' not found." << endl;
		return;
	}
	char c;
	unsigned i = 0;
	unsigned char a[8], b[8];
	while (1)
	{
		(file_in).get(c);
		if ((file_in).eof())
		{
			if (i != 0)
			{
				for (unsigned j = i + 1; j < 8; j++)
					a[j] = 0;
				for (unsigned j = 0; j < 8; j++)
					b[j] = 0;
				deDES(a, b);
				for (unsigned n = 0; n < 8; n++)
					file_out << b[n];
			}
			break;
		}
		a[i] = c;
		i++;
		if (i == 8)
		{
			i = 0;
			for (unsigned j = 0; j < 8; j++)
				b[j] = 0;
			deDES(a, b);
			for (unsigned n = 0; n < 8; n++)
				file_out << b[n];
		}
	}
	file_in.close();
	file_out.close();
	cout << "Decryption done.\n";
	return;
}
int main(int argc, char*argv[]) {
	string file_in_name, file_out_name;
	bool chose = 0;
	cout << "Encrypt (0) or decrypt(1)?\n = ";
	cin >> chose;
	file_in_name = argv[1];
	fstream check_file;
	check_file.open(file_in_name);
	if (check_file.is_open())
	{
		file_out_name = argv[2];
		if (chose)
		{
			F16_2(file_in_name, file_out_name);
		}
		else
		{
			F16_1(file_in_name, file_out_name);
		}
	}
	else
	{
		cout << "Output: " << "File '" << file_in_name << "'not found.\n";
	}
	return 0;
}