#include <iostream>

using namespace std;

int num;
int numbers[8] = { 0 };
int order[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
int largest;

int calc()
{
	int sum = 0;
	int tmp;
	for (int i = 0; i < num - 1; i++)
	{
		tmp = numbers[order[i]] - numbers[order[i + 1]];
		if (tmp < 0)
			tmp = -tmp;
		sum += tmp;
	}

	return sum;
}

void swap(int a, int b)
{
	int tmp;
	tmp = order[a];
	order[a] = order[b];
	order[b] = tmp;
}

void fold(int a)
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

	for (int i = num - 1; i > 0; i--)	//���� ���� ���������� ���� i�� ã��
	{
		if (order[i - 1] < order[i])
		{
			cnt_i = i;
			break;
		}
	}

	if (cnt_i == 0)
		return 0;
	else
	{
		for (int j = num - 1; j > cnt_i - 1; j--)	// �ڿ������� (i��°���� ���ʿ� �ִ� �� ��) input[i]���� ū ���� ã��
		{
			if (order[j] > order[cnt_i - 1])		// ã������, i-1 ��°�� �ٲ��ְ�, i��°���ʹ� ��������
			{
				swap(j, cnt_i - 1);
				fold(cnt_i);
				break;
			}
		}

		return 1;
	}
}

int main()
{
	int candi;

	cin >> num;

	for (int i = 0; i < num; i++)
		cin >> numbers[i];

	do
	{
		candi = calc();

		if (largest < candi)
			largest = candi;

	} while (next_p());

	cout << largest;

	return 0;
} 