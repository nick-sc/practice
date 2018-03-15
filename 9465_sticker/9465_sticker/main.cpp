#include <iostream>

using namespace std;

int tc, n, ans;
int sticker[2][100001];
int dp[3][100001];

int max(int a, int b)
{
	return a > b ? a : b;
}


int main()
{
	cin >> tc;

	while (tc--)
	{
		cin >> n;
		ans = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j <= n; j++)
				dp[i][j] = 0;
		}
		
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
				cin >> sticker[i][j];
		}

		for (int i = 1; i <= n; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + sticker[0][i];
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + sticker[1][i];
		}
		
		for (int i = 0; i < 3; i++)
			ans = max(ans, dp[i][n]);
				
		cout << ans << "\n";
	}	

	return 0;
}