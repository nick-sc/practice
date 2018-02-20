#include <iostream>

using namespace std;

int target, num_broken, tmp;
int broken[10] = { 0 };
int min_push = 500000;
int cnt = 0;
int digits = 0;
int push = 0;


int possible(int num)
{
	int dit = 0;

	if (num == 0)			//0�� ä���� ���
	{
		if (!broken[0])
			return 1;
		else
			return 0;
	}

	while (num > 0)
	{
		push = num % 10;
		if (broken[push])		//�������� �ϴ°� ���峵�� ���
			return 0;

		num = num / 10;
		dit++;
	}

	return dit;
}

int main()
{
	cin >> target;
	cin >> num_broken;
	
	for (int i = 0; i < num_broken; i++)
	{
		cin >> tmp;
		broken[tmp] = 1;
	}

	if (target < 100)				//+,- ��ư���θ� �̵��ϴ� ����� �ּҰ�
		min_push = 100 - target;
	else
		min_push = target - 100;


	for (int i = 0; i < 1000000; i++)
	{
		digits = possible(i);

		if (digits > 0)			//�ϳ��� ��ư�� ���� ���
		{
			if (i > target)
			{
				cnt = i - target;
			}
			else
			{
				cnt = target - i;
			}

			if (min_push > cnt + digits)
				min_push = cnt + digits;
		}
	}

	cout << min_push;

	return 0;
}