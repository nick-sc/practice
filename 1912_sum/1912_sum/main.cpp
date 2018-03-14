#include <iostream>

using namespace std;

int n;
int nums[1000001];
int dp[1000001];

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> nums[i];

	for (int i = 1; i <= n; i++)
	{
		if (nums[i] < dp[i - 1] + nums[i])
			dp[i] = dp[i - 1] + nums[i];
		else
			dp[i] = nums[i];
	}

	int ans = dp[1];

	for (int i = 1; i <= n; i++)
	{
		if (ans < dp[i])
			ans = dp[i];
	}

	cout << ans;

	cin >> ans;

	return 0;
}