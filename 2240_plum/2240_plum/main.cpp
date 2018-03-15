#include <iostream>

using namespace std;

int t, w;
int plum[1001];
int dp[1001][31];

int max(int a, int b)
{
	return a > b ? a : b;
}

int eat(int turn, int cng)
{
	if (turn == t + 1 && cng <= w)
		return 0;
	if (cng > w)
		return 0;
	if (dp[turn][cng] != -1)
		return dp[turn][cng];

	int where = cng % 2 + 1;
	
	dp[turn][cng] = max(eat(turn + 1, cng), eat(turn + 1, cng + 1)) + (where == plum[turn] ? 1 : 0);

	return dp[turn][cng];
}

int main()
{
	cin >> t >> w;

	for (int i = 1; i <= t; i++)
		cin >> plum[i];	

	for (int i = 0; i <= t; i++)
	{
		for (int j = 0; j <= 30; j++)
			dp[i][j] = -1;
	}
	
	cout << max(eat(1, 0), eat(1, 1));

	return 0;
}