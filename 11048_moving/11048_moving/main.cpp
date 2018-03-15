#include <iostream>

using namespace std;

int map[1001][1001];
int dp[1001][1001];


int max(int a, int b)
{
	return a > b ? a : b;
}


int main()
{
	int r, c;


	cin >> r >> c;
		
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
			cin >> map[i][j];
	}
	
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + map[i][j];
	}
	
	
	cout << dp[r][c];

	return 0;
}