#include <iostream>
#include <cmath>
using namespace std;
int array[20];
int moisej(int step,bool choise)
{
	if (choise == 0)
	{
		for (int i = 0; i < 20; i++)
			array[i] = i + 1;
		int man = 0;
		int dead = 0;
		for (int i = 0; i < 19; i++)
		{
			array[(man + step) % (20 - dead)] = -1;
			for (int j = (man + step) % (20 - dead); j < 19; j++)
				swap(array[j], array[j + 1]);
			man = (man + step) % (20 - dead);
			dead++;
		}
		return(array[0]);
	}
	else
	{
		for (int counter = 2; counter < 20; counter++)
		{
			for (int i = 0; i < 20; i++)
				array[i] = i + 1;
			int man = 0;
			int dead = 0;
			for (int i = 0; i < 19; i++)
			{
				array[(man + counter) % (20 - dead)] = -1;
				for (int j = (man + counter) % (20 - dead); j < 19; j++)
					swap(array[j], array[j + 1]);
				man = (man + counter) % (20 - dead);
				dead++;
			}
			if (array[0] == 1)
				return(counter);
		}
	}
}
int main()
{
	int step;
	cout << "choose what do you want me to do: 0 - calculate the number of alive person " << endl;
	cout << "                                  1 - calculate the step for the 1st guy " << endl;
	bool choise = 0;
	cin >> choise;
	if (choise == 0)
	{
		cout << "input the step ";
		cin >> step;
		cout << moisej(step, choise) << " will stay alive" << endl;
	}
		if (choise == 1)
			cout << moisej(1, choise) << " - the step 1st one needs to survive" << endl;
	return(0);
}