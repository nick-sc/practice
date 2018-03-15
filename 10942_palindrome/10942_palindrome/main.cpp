#include <iostream>

using namespace std;

int n, m, s, e;
int nums[2001];
int dp[2001][2001];

int palin(int a, int b)
{
	if (a == b)
		return dp[a][b] = 1;
	if (a == b + 1)
	{
		if (nums[a] == nums[b])
			return dp[a][b] = 1;
		else
			return dp[a][b] = 0;
	}
	if (dp[a][b] > -1)
		return dp[a][b];
	if (nums[a] != nums[b])
		return dp[a][b] = 0;
	else
		return dp[a][b] = palin(a + 1, b - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> nums[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			dp[i][j] = -1;
	}

	cin >> m;

	while (m--)
	{
		cin >> s >> e;
		cout << palin(s, e) << "\n";
	}

	return 0;
}