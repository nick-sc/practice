#include <iostream>

using namespace std;

int target;
int is_min = 999999;

void calc(int num, int cnt)
{
	if (cnt > is_min)
		return;
	
	if (num == 1)
	{
		if (cnt < is_min)
			is_min = cnt;
		return;
	}
	
	if (num % 3 == 0)
		calc(num / 3, cnt + 1);

	if (num % 2 == 0)
		calc(num / 2, cnt + 1);

	calc(num-1, cnt + 1);
}


int main()
{
	cin >> target;

	calc(target, 0);

	cout << is_min;

	return 0;
}