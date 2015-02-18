#include <iostream>
#include <fstream>
#include <string>
//fs.read(unsigned char *m,n);cчитать n символов
//int pos=fs.tellag()
// fs.seekg(poss+10)
//fs.seekg(offset,ios_base::beg)
//					        cur
//							end

void perevod(unsigned char *m1, unsigned char *m2){
	char *a = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	m2[0] = a[m1[0] >> 2];
	m2[1] = a[((m1[0]&3)<<4)+(m1[1]>>4)];
	m2[2] = a[((m1[1] & 15) << 2) + (m1[2] >> 6)];
	m2[3] = a[m1[2] & 63];
}
void dep(char *n, unsigned char *out,int &k){
	char *b = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int*in = new int[4];
	k = 0;
	for (int i = 0; i < 4; ++i){
		if (n[i] == '=')
		{
			in[i] = 0;
			k++;
		}
		else{
			for (int j = 0; j < 64; ++j){
				if (n[i] == b[j]){
					in[i] = j;
					break;
				}
			}
		}
	}
	out[0] = (in[0] << 2) | (in[1] >> 4);
	out[1] = ((in[1] & 15) << 4) | (in[2] >> 2);
	out[2] = ((in[2] & 3) << 6) | in[3];
	delete[]in;
}
//111111
//543210
using namespace std;


/*int main(int argc, char *argv[]){
	//cout << "argc = " << argc << endl;
	//cout << "argv[0] = " << argv[0] << endl;
	//if (argc == 2)cout << argv[1]<<endl;
	if (argc < 2){
		cout << "Write file name ---------file not found\n";
		return -1;
	}
	string name=argv[1];
	//cout << name << '\n';
	//cout << "Write file name\n";
	//cin >> name;
	//cin >> name;
	//string name = "1.txt";
	ifstream file(name,ios_base::binary);
	fstream fileout("out1",ios::out|ios::trunc);
	if (file.is_open() == false){
		cout << 1;
		return-1;
	}
	if (fileout.is_open() == false){
		cout << 2;
		return-2;
	}

	unsigned unsigned char*m1 = new unsigned char[3];
	unsigned char*m2 = new unsigned char[4];
	unsigned char c;
	int i = 0;
	///*while(file.eof()==false){
	//	file.read(m1, 3);
	//	int q = file.gcount();
	//	if (q == 3){
	//		perevod(m1, m2);
	//		for (int i = 0; i < 4; ++i){
	//			fileout << m2[i];
	//		}
	//	}
	//	else{
	//		for (int i = q; i < 3; ++i){
	//			m1[i] = 0;
	//		}
	//		perevod(m1, m2);
	//		for (int i = 0; i < q+1; ++i){
	//			fileout << m2[i];
	//		}
	//		for (int i = 0; i < 3 - q; ++i){
	//			fileout << '=';
	//		}
	//		break;

	//	}
	//}
	//
	i = 0;
	m1[0] = file.get();
	while (file.eof() == false){
		//i++;
		//m1[i % 3] = (unsigned char)file.get();
		if (i % 3 == 2){
			perevod(m1, m2);
			for (int j = 0; j < 4; j++)fileout.put(m2[j]);
		}
		i++;
		m1[i % 3] = (unsigned char)file.get();
	}
	--i;
	//TQ==
	//TWE=
	//for (int j = 0; j < 3; ++j)cout << m1[j];
	if (i % 3 != 2){
		for (int j = i%3 + 1; j < 3; ++j){
			m1[j] = 0;
		}
		perevod(m1, m2);
		for (int j = 0; j < i%3 + 2; ++j){
			fileout << m2[j];
		}
		for (int j = i%3 + 2; j < 4; ++j){
			fileout << '=';
		}
	}
	
	//-----------------------------------
	delete[]m1;
	delete[]m2;
	file.close();
	fileout.close();
	system("pause");
	return 0;
}
*/

////==--------------------------------------------------------------

int main(int argc,char *argv[]){
	if (argc < 2){
		cout << "Write file name ---------file not found\n";
		return -1;
	}
	string name=argv[1];
	//string name;
	//cin >> name;
	fstream file(name, ios::binary | ios::in);
	fstream fileout("out", ios::out | ios::trunc|ios::binary);
	if (file.is_open() == false){
		cout << 1;
		return-1;
	}
	if (fileout.is_open() == false){
		cout << 2;
		return-2;
	}

	char*m1 = new char[4];
	unsigned char*m2 = new unsigned char[3];

	unsigned char c;
	int i = 0;
	while (file.eof()==false){
		int k=0;
		file.read(m1, 4);
		dep(m1, m2,k);
		for (int j = 0; j < (3 - k); ++j){
			fileout << m2[j];
		}
		if (k != 0)break;
		if (file.peek() == EOF)break;
	}	
	delete[]m1;
	delete[]m2;
	file.close();
	fileout.close();
	system("pause");
	return 0;
}