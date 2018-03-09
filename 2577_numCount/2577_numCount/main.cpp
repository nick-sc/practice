#include <iostream>

using namespace std;

int main()
{
	int input[3];
	int nums[10] = { 0 };

	cin >> input[0] >> input[1] >> input[2];

	long long tmp = input[0] * input[1] * input[2];
	int is_num;

	while (tmp > 0)
	{
		is_num = tmp % 10;
		nums[is_num]++;
		tmp /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << nums[i] << "\n";

	return 0;
}