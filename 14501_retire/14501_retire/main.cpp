#include <iostream>

using namespace std;

int retire = 0;							//����� �Է¹޴� ����
int takes[20] = { 0 };					//�� ���� �ɸ��� �ð��� �Է¹޴� �����迭
int pay[20] = { 0 };					//�� ���� �ϰ� ���� �� �ִ� ���� �Է¹޴� �����迭

int max_pay = 0;						//�� case ���� ���� �� �ִ� �ִ� �ݾ��� �����ϴ� ����

void works(int date, int cur_pay)
{
	if (date > retire)			//���� �� ���ϴ� ���(���� ��¥�� ����Ϻ��� �Ѿ ���)
	{
		if (max_pay < cur_pay)		//���� �� �̻� ���� ���, ������� ���� �ݾ��� �ִ� �ݾ����� �˻�
			max_pay = cur_pay;
		return;
	}

	for (date; date <= retire; date++)
	{
		if (date + takes[date] <= retire+1)		//���� ���� �� �� �ִ� ���, ���� ���� �ް� �� ���� �������� �̵�
			works(date+takes[date], cur_pay+pay[date]);
		else                                    //���� ���� �� �� ���� ���, �������� �̵�
			works(date + 1, cur_pay);
	}
}


int main()
{
	cin >> retire;								//��� ��¥�� �Է¹���

	for (int i = 1; i <= retire; i++)			//�� ��¥�� �ɸ��� �ð�(Ti)�� ����(Pi)�� �Է¹���
	{
		cin >> takes[i];
		cin >> pay[i];
	}

	works(1, 0);								//1���� ���, ����ݾ� 0��

	cout << max_pay;

	return 0;
}