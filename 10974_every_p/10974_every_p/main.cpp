#include <iostream>

using namespace std;

int num = 0;
int input[10000] = { 0 };

void swap(int a, int b)
{
	int tmp;

	tmp = input[a];
	input[a] = input[b];
	input[b] = tmp;
}

void flod(int a)
{
	int b = 1;
	for (int i = a; i < num; i++)
	{
		if (i < num - b)
		{
			swap(i, num - b);
			b++;
		}
	}
}

int next_p()
{
	int cnt_i = 0;
	int cnt_j;

	for (int i = num - 1; i > 0; i--)
	{
		if (input[i - 1] < input[i])
		{
			cnt_i = i;
			break;
		}
	}

	if (cnt_i == 0)
		return 0;
	else
	{
		for (int j = num - 1; j > cnt_i - 1; j--)
		{
			if (input[j] > input[cnt_i - 1])
			{
				swap(j, cnt_i - 1);
				flod(cnt_i);
				break;
			}
		}
		for (int k = 0; k < num; k++)
			cout << input[k] << " ";
		cout << '\n';
		return 1;
	}
}

int main()
{
	cin >> num;
	int w = 1;

	for (int i = 0; i < num; i++)
	{
		input[i] = i + 1;
		cout << input[i] << " ";
	}
	cout << '\n';

	while (w)
		w = next_p();

	return 0;
}