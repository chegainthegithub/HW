#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void b64e(char *a, char* out)
{
	if (a == 0 || out == 0) return;
	char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	bool f1 = false, f2 = false;
	if (a[1] == -1) { a[1] = 0; f1 = true; }
	if (a[2] == -1) { a[2] = 0; f2 = true; }
	out[0] = table[a[0] >> 2];
	out[1] = table[(a[0] & 3) << 4 | a[1] >> 4];
	out[2] = table[(a[1] & 15) << 2 | a[2] >> 6];
	out[3] = table[a[2] & 63];
	if (f1) a[1] = -1;
	if (f2) a[2] = -1;
	return;
}

void b64de(char *in, char *out)
{
	if (in == 0 || out == 0) return;
	char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
	char in_point[4];
	int j = 0;
	for (unsigned i = 0; i < 4; i++)
	{
		j = 0;
		while (in[i] != table[j] && j < 65)
		{
			j++;
		}
		if (j == 64) return;
		in_point[i] = j;
	}
	out[0] = (in_point[0] & 63) << 2 | (in_point[1] & 48) >> 4;
	out[1] = (in_point[1] & 15) << 4 | (in_point[2] & 60) >> 2;
	out[2] = (in_point[2] & 3) << 6 | (in_point[3] & 63);
	return;
}
void F15_1(string file_in_name, string file_out_name)
{
	fstream file_in;
	fstream file_out;
	file_in.open(file_in_name, ios_base::in | ios_base::binary);
	file_out.open(file_out_name, ios_base::out | ios_base::trunc);
	if (file_in.is_open() != true)
	{
		cout << "File '" << file_in_name << "' not found." << endl;
		return;
	}
	while (1)
	{
		char a[3] = { -1, -1, -1 };
		char out[4] = { 0, 0, 0, 0 };
		(file_in).get(a[0]);
		if (!(file_in).eof())
		{
			(file_in).get(a[1]);
			if (!(file_in).eof())
			{
				(file_in).get(a[2]);
			}
		}
		if (!(file_in).eof() || a[0] != -1){
			b64e(a, out);
			(file_out) << out[0] << out[1] << out[2] << out[3];
			if (a[1] == -1)
			{
				(file_out) << "=";
				if (a[2] == -1)
				{
					(file_out) << "=";
				}
			}
		}
		if ((file_in).eof()) break;
	}
	file_in.close();
	file_out.close();
	cout << "Encryption done.\n";
	return;
}

void F15_2(string file_in_name, string file_out_name)
{
	fstream file_in;
	fstream file_out;
	file_in.open(file_in_name, ios_base::in | ios_base::binary);
	file_out.open(file_out_name, ios_base::out | ios_base::trunc);
	if (file_in.is_open() != true)
	{
		cout << "File '" << file_in_name << "' not found." << endl;
		return;
	}
	while (1)
	{
		char in[4] = { 0, 0, 0, 0 };
		char out[3] = { 0, 0, 0 };
		(file_in).get(in[0]);
		if (!(file_in).eof())
		{
			(file_in).get(in[1]);
			if (!(file_in).eof())
			{
				(file_in).get(in[2]);
				if (!(file_in).eof())
				{
					(file_in).get(in[3]);
				}
			}
		}
		if (!(file_in).eof())
		{
			b64de(in, out);
			(file_out) << out[0] << out[1] << out[2];
		}
		if ((file_in).eof()) break;
	}
	return;
	file_in.close();
	file_out.close();
	cout << "Decryption done.\n";
	return;
}
int main(int argc, char*argv[]){
	string file_in_name, file_out_name;
	bool chose = 0;
	file_in_name = argv[1];
	file_out_name = argv[2];
	cout << "Encrypt (0) or decrypt(1)?\n = ";
	cin >> chose;
	fstream check_file;
	check_file.open(file_in_name);
	if (check_file.is_open())
	{
		if (chose)
		{
			F15_2(file_in_name, file_out_name);
		}
		else
		{
			F15_1(file_in_name, file_out_name);
		}
	}
	else
	{
		cout << "Output: " << "File '" << file_in_name << "'not found.\n";
	}
	return 0;
}