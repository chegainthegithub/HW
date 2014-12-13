#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<vector<int>> matrix_creator(int *true_arr, int num, int size)
{
	vector<vector<int>> matrix;
	vector <int> local_arr;
	int *arr = new int[num];
	int *full_arr = new int[size];
	for (int i = 0; i < num; i++)
		arr[i] = i + 1;
	for (int i = 0; i < size; i++)
		full_arr[i] = i + 1;	       //int full_arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };     
	int n, m;                          //int true_arr[8] = { 0, 1, 3, 5, 7, 9, 11, 13 };
	n = size - 1;
	int k = num - 1;
	int l = 0;
	for (int i = 0; i < num; i++)
		local_arr.push_back(true_arr[i]);
	matrix.push_back(local_arr);
	int i;
	while (true)
	{
		for (i = k; i >= 0; i--)
		{
			while (arr[i] < full_arr[n - l])
			{
				arr[i]++;
				for (int f = i + 1; f <= k; f++)
					arr[f] = arr[i] + f - i;
				vector<int> local_arr1;
				for (int s = 0; s <= k; s++)
					local_arr1.push_back(true_arr[arr[s] - 1]);
				matrix.push_back(local_arr1);
				for (int f = k; f >= i + 1; f--)
				{
					if (arr[f] < full_arr[f + n - k])
					{
						++arr[f];
						vector<int> local_arr1;
						for (int s = 0; s <= k; s++)
							local_arr1.push_back(true_arr[arr[s] - 1]);
						matrix.push_back(local_arr1);
					}
				}
			}
			++l;
		}
		if (i == -1)
			break;
	}
	return(matrix);
}
vector<int> the_arr(int All_Goods, int num, int Number_Trades)
{
	int Trade_Goods;
	int *True_arr1 = new int[All_Goods];
	for (int i = 0; i < All_Goods; i++)
		True_arr1[i] = i + 1;
	vector<vector<int>> Matrix_full = matrix_creator(True_arr1, num, All_Goods);
	int Great_limit = Matrix_full.size();
	int *Full_Arr = new int[Great_limit];
	int buffer;// ���������� ��������� ��������� � ����� �� ������� ����� ����� 2 �����
	ifstream file("filename.txt", ios::in);
	file >> buffer; //
	file >> buffer; // ����� ��2 ����� �� ������ ����� (�� ������� ������ ������)
	for (int i = 1; i <= Number_Trades; i++) //��� ���������� ����������-������-���(������� ���� ������)
	{
		int Trade_Goods;
		file >> Trade_Goods; //���������� 
		int *True_arr2 = new int[Trade_Goods];  //���������� ������� True_arr2 ��� ������� ������� ��� ������ ������ - ���������� ������� �������� ������� �� ������ (��� ����������� �� �����������)
		for (int local1 = 0; local1 < Trade_Goods; local1++) //���� �� 0 �� Trade_Goods ��������� � True_arr2 �����
		{
			file >> buffer;
			True_arr2[local1] = buffer;
		}
		vector<vector<int>> Matrix_local = matrix_creator(True_arr2, num, Trade_Goods); // ������� ��������� ������ ������
		int limit = Matrix_local.size();
		int count = 0;
		for (int j = 0; j < limit; j++)   //��������� ��������� �� ����� ������� ������� � ������� ��������� �������,��������� ��������������� ����� ������� ����� ������������� ����������
		{
			for (int count = 0; count < Great_limit; count++)
				if (Matrix_full[count] == Matrix_local[j]);
			{
				++Full_Arr[count];
				break;
			}
		}
	}
	int max = 0;
	vector <int> Max_number = Matrix_full[0];
	for (int i = 0; i < Great_limit; i++)  //����� ����� ���� ��������� ������� �������������,���������� ������ �� ������� ���� ��������� ���������� � ������ ������� - ���������
	{
		if (Full_Arr[i]>max)
		{
			max = Full_Arr[i];
			Max_number = Matrix_full[i];
		}
	}
	return (Max_number);
}
int main()
{
	int All_Goods;
	int num = 1;
	int All_Trades;
	
	ifstream file("nameofthefile.txt", ios::in);
	file.open("nameofthefile.txt", ios::in);
	char chr = '1';
	if (!file.is_open())
	{
		cout << "file isnt found";
		return 0;
	}
	while (!file.eof())
	{
		file >> chr;
		if (chr <'0'&&chr>'9')
		{
			cout << "there are wrong symbols in the file.the information cannot be read properly"; //�������� �� ������ �����
			return 0;
		}
	}
	file.close();
	/*file.open("nameofthefile.txt", ios::in);
	file >> All_Goods;
	file >> All_Trades; //���� ���������� �������,���������� ������
	for (int i = 1; i <= All_Goods; i++)
	{
		int size = the_arr(All_Goods, num, All_Trades).size();
		for (int j = 0; j < size; j++)    //���� ������ ���� ��������,��������������� ����� ����� ������������� ���������� ����� �� ��������� �� i
		{
			cout << the_arr(All_Goods, i, All_Trades)[j] << endl;
		}
	}*/
	return 0;
}