#include <iostream>

using namespace std;

int n;
int ans = -1000;
int nums[100002];
int dp_1[100002];
int dp_2[100002];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> nums[i];

	for (int i = 1; i <= n; i++)
	{
		if (nums[i] < dp_1[i - 1] + nums[i])
			dp_1[i] = dp_1[i - 1] + nums[i];
		else
			dp_1[i] = nums[i];
	}

	for (int i = n; i >= 1; i--)
	{
		if (nums[i] < dp_2[i + 1] + nums[i])
			dp_2[i] = dp_2[i + 1] + nums[i];
		else
			dp_2[i] = nums[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (ans < dp_1[i])
			ans = dp_1[i];
	}

	for (int i = 1; i <= n-1; i++)
	{
		if (ans < dp_1[i] + dp_2[i + 2])
			ans = dp_1[i] + dp_2[i + 2];
	}

	cout << ans;

	return 0;
}