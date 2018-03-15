#include <iostream>

using namespace std;

int n;
long long dp[101][101];
int map[101][101];

int main()
{
	cin >> n;

	dp[1][1] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == n && j == n)
				break;
			if(i + map[i][j] <= n)
				dp[i + map[i][j]][j] += dp[i][j];
			if (j + map[i][j] <= n)
				dp[i][j + map[i][j]] += dp[i][j];
		}
	}

	cout << dp[n][n] << " ";
	
	return 0;
}