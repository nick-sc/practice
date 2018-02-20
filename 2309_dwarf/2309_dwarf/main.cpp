#include <iostream>

using namespace std;

int dwarfs[9] = { 0 };
int total = 0;
int real_d[7] = { 0 };
int r = 0;
int tmp;

int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> dwarfs[i];
		total = total + dwarfs[i];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if (total - dwarfs[i] - dwarfs[j] == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
						real_d[r++] = dwarfs[k];
				}
				break;
			}
		}
		if (r)
			break;
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = i+1; j < 7; j++)
		{
			if (real_d[i] > real_d[j])
			{
				tmp = real_d[i];
				real_d[i] = real_d[j];
				real_d[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 7; i++)
		cout << real_d[i] << endl;
	

	return 0;
}