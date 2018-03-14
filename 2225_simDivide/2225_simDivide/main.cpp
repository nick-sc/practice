#include <iostream>

using namespace std;

long long dp[201][201];


int main()
{
	int N, K;
	
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		dp[i][1] = 1;

	for (int i = 2; i <= K; i++)
		dp[1][i] = dp[1][i - 1] + 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
	}

	cout << dp[N][K];

	cin >> N;

	return 0;
}