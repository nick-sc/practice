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

void prev_p()
{
	int cnt_i = 0;
	int cnt_j;

	for (int i = num - 1; i > 0; i--)	//�� �ڿ������� �� ���� �� ������ ū ���� ã��
	{
		if (input[i - 1] > input[i])
		{
			cnt_i = i;
			break;
		}
	}

	if (cnt_i == 0)
	{
		cout << "-1";
		return;
	}
	else
	{
		for (int j = num - 1; j > cnt_i - 1; j--)	// �ڿ������� (i��°���� ���ʿ� �ִ� �� ��) input[i]���� ���� ���� ã��
		{
			if (input[j] < input[cnt_i - 1])		// ã������, i-1 ��°�� �ٲ��ְ�, i��°���ʹ� ��������
			{
				swap(j, cnt_i - 1);
				flod(cnt_i);
				break;
			}
		}
		for (int k = 0; k < num; k++)
			cout << input[k] << " ";
	}
}

int main()
{
	cin >> num;

	for (int i = 0; i < num; i++)
		cin >> input[i];

	prev_p();
	
	return 0;
}