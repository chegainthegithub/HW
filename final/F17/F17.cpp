#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
bool F17(string file_name)
{
	fstream file;
	file.open(file_name, ios_base::in | ios_base::binary);
	if (file.is_open() != true)
	{
		cout << "------------------------------------\nFile '" << file_name << "' not found.\n------------------------------------" << endl;
		return false;
	}
	stack <string> ckeck;
	string s;
	string tags;
	bool tag = false;
	while (1)
	{
		getline(file, s);
		if (file.eof()) break;
		tags.clear();
		for (unsigned k = 0; k < s.size(); k++)
		{
			if (tag)
			{
				tags.push_back(s[k]);
			}
			if (s[k] == '<')
			{
				if (tag) return false;
				tag = true;
				tags.push_back(s[k]);
			}
			if (s[k] == '>')
			{
				if (tag)
				{
					tag = false;
					if (tags[1] == '/')//opening or closing
					{
						tags.erase(0, 2);
						tags = "<" + tags;
						if (tags == ckeck.top())
							ckeck.pop();
						else
							return false;
						tags.clear();
					}
					else
					{
						ckeck.push(tags);
						tags.clear();
					}
				}
			}

		}
	}
	if (!ckeck.empty()) return false;
	return true;
}
int main(int argc, char*argv[]){
	string s = argv[1];
	if (F17(s))
		cout << "It's XML file" << endl;
	else
		cout << "It's not XML file" << endl;
	return 0;
}