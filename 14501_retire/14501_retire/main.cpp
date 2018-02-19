#include <iostream>

using namespace std;

int retire = 0;							//퇴사일 입력받는 변수
int takes[20] = { 0 };					//각 일이 걸리는 시간을 입력받는 변수배열
int pay[20] = { 0 };					//각 일을 하고 얻을 수 있는 돈을 입력받는 변수배열

int max_pay = 0;						//각 case 별로 받을 수 있는 최대 금액을 저장하는 변수

void works(int date, int cur_pay)
{
	if (date > retire)			//일을 더 못하는 경우(현재 날짜가 퇴사일보다 넘어간 경우)
	{
		if (max_pay < cur_pay)		//일을 더 이상 못할 경우, 현재까지 받은 금액이 최대 금액인지 검사
			max_pay = cur_pay;
		return;
	}

	for (date; date <= retire; date++)
	{
		if (date + takes[date] <= retire+1)		//현재 일을 할 수 있는 경우, 일한 보수 받고 일 끝난 다음날로 이동
			works(date+takes[date], cur_pay+pay[date]);
		else                                    //현재 일을 할 수 없는 경우, 다음날로 이동
			works(date + 1, cur_pay);
	}
}


int main()
{
	cin >> retire;								//퇴사 날짜를 입력받음

	for (int i = 1; i <= retire; i++)			//각 날짜별 걸리는 시간(Ti)과 수당(Pi)를 입력받음
	{
		cin >> takes[i];
		cin >> pay[i];
	}

	works(1, 0);								//1일차 출근, 현재금액 0원

	cout << max_pay;

	return 0;
}