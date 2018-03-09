#include <iostream>

using namespace std;

int houses[1000][3] = { 0 };
int num_house;
int minc = 99999999;

void painting(int cnt, char prev, int cst)
{
	if (cnt == num_house)
	{
		if (cst < minc)
			minc = cst;
		return;
	}
	if (cst > minc)
		return;

	if (prev == 'r')
	{
		painting(cnt + 1, 'g', cst + houses[cnt + 1][1]);
		painting(cnt + 1, 'b', cst + houses[cnt + 1][2]);
	}
	else if (prev == 'g')
	{
		painting(cnt + 1, 'r', cst + houses[cnt + 1][0]);
		painting(cnt + 1, 'b', cst + houses[cnt + 1][2]);
	}
	else if (prev == 'b')
	{
		painting(cnt + 1, 'r', cst + houses[cnt + 1][0]);
		painting(cnt + 1, 'g', cst + houses[cnt + 1][1]);
	}
}

int main()
{
	cin >> num_house;

	for (int i = 0; i < num_house; i++)
		cin >> houses[i][0] >> houses[i][1] >> houses[i][2];

	painting(0, 'r', houses[0][0]);
	painting(0, 'g', houses[0][1]);
	painting(0, 'b', houses[0][2]);

	cout << minc;
	cin >> num_house;
	return 0;
}