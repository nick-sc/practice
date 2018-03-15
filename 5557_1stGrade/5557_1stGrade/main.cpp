#include <iostream>

using namespace std;

long long dp[101][21];
int nums[101];

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	int ans = nums[n-1];

	dp[0][nums[0]] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (j - nums[i] >= 0)
				dp[i][j] += dp[i - 1][j - nums[i]];
			if (j + nums[i] <= 20)
				dp[i][j] += dp[i - 1][j + nums[i]];
		}
	}

	cout << dp[n-2][ans];

	return 0;
}