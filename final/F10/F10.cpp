#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void F10(char*argv1, char*argv2){
	fstream file_in;
	fstream file_out;
	file_in.open(argv1);
	if (file_in.is_open() != true)
	{
		cout << "File '" << argv1 << "' not found." << endl;
		return;
	}
	file_out.open(argv2, ios_base::out | ios_base::trunc);
	string text;
	text.clear();
	string text_out;
	while (1)
	{
		text_out.clear();
		getline(file_in, text);
		unsigned words = 0;
		unsigned i = 0;
		while (text[i] == ' ')
		{
			i++;
		}
		while (i < text.size())
		{
			while (text[i] != ' ' && i < text.size())
			{
				if (text[i] != '\t')
				{
					text_out.push_back(text[i]);
				}
				i++;
			}
			if (text[i] == ' ')
			{
				text_out.push_back(' ');
				words++;
			}
			while (text[i] == ' ' && i < text.size())
			{
				i++;
			}
		}
		if (words > 0)
		{
			unsigned need = (80 - text_out.size()) / words;
			i = 0;
			while (i < text_out.size())
			{
				while (text_out[i] != ' ' && i < text_out.size())
				{
					i++;
				}
				if (text_out[i] == ' ')
				{
					for (int j = 0; j < need; j++)
						text_out.insert(i, " ");
					i += need;
				}
				i++;
			}
		}
		else text_out = text;
		file_out << text_out << endl;
		if (file_in.eof()) break;
	}
	file_in.close();
	file_out.close();
	cout << "Done.";
	return;
}
int main(int argc, char*argv[]){
	F10(argv[1], argv[2]);
	return 0;
}