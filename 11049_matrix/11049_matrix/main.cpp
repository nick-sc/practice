#include <iostream>

using namespace std;

int n = 0;
int mat[2][501];
long long dp[501][501];

int multip(int x, int y)
{
	if (dp[x][y])
		return dp[x][y];
	if (x == y)
		return 0;
	if (x + 1 == y)
		return mat[0][x] * mat[1][x] * mat[1][y];

	dp[x][y] = -1;

	for (int k = x; k <= y - 1; k++)
	{
		int tmp1 = multip(x, k);
		int tmp2 = multip(k + 1, y);
		if (dp[x][y] == -1 || dp[x][y] > tmp1 + tmp2 + mat[0][x] * mat[1][k] * mat[1][y])
			dp[x][y] = tmp1 + tmp2 + mat[0][x] * mat[1][k] * mat[1][y];
	}
	return dp[x][y];
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> mat[0][i] >> mat[1][i];

	cout << multip(1, n);

	return 0;
}