#include <iostream>

using namespace std;

int main()
{
	int dp[11][1001] = { 0 };
	int n;
	int ans = 0;

	for (int i = 1; i < 11; i++)
		dp[i][1] = 1;

	cin >> n;

	for (int j = 2; j <= n; j++)
	{
		for (int i = 1; i <= 10; i++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
	}

	for (int i = 1; i <= 10; i++)
		ans = (ans + dp[i][n]) % 10007;

	cout << ans;

	return 0;
}