#include <iostream>

using namespace std;

int n;
int ans = 0;
int wine[10001] = { 0 };
int dp[10001] = { 0 };

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> wine[i];

	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1];

		if (dp[i] < dp[i - 2] + wine[i])
			dp[i] = dp[i - 2] + wine[i];
		if (dp[i] < dp[i - 3] + wine[i - 1] + wine[i])
			dp[i] = dp[i - 3] + wine[i - 1] + wine[i];
	}

	cout << dp[n];

	return 0;
}