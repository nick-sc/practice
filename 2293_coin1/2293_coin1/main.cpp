#include <iostream>

using namespace std;

int main()
{
	int n, k;
	int coins[101];
	int dp[10001] = { 0 };

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> coins[i];

	for (int j = 1; j <= n; j++)
	{
		for (int i = coins[j]; i <= k; i++)
		{
			if (i == coins[j])
				dp[i]++;
			else if (i > coins[j])
				dp[i] += + dp[i - coins[j]];
		}
	}

	cout << dp[k];
	
	return 0;
}