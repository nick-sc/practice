#include <iostream>

using namespace std;

int arr[501] = { 0 };
int dp[501][501] = { 0 };

int fileMerging(int a, int b)
{
	if (a == b)
		return 0;
	if (dp[a][b] != -1)
		return dp[a][b];

	int sum = 0;
	for (int k = a; k <= b; k++)
		sum += arr[k];
	
	for (int i = a; i < b; i++)
	{
		int tmp = fileMerging(a, i) + fileMerging(i + 1, b) + sum;
		if (dp[a][b] > tmp || dp[a][b] == -1)
			dp[a][b] = tmp;
	}

	return dp[a][b];
}

int main()
{
	int tc, n;
	int ans;

	cin >> tc;

	while (tc--)
	{
		cin >> n;

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
				dp[i][j] = -1;
		}

		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		ans = fileMerging(1, n);

		cout << ans << "\n";
	}

	cin >> tc;
	
	return 0;
}