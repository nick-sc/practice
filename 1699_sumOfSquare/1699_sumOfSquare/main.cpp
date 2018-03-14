#include <iostream>

using namespace std;


int main()
{
	int N;
	int dp[100001];
	cin >> N;

	for (int i = 0; i <= N; i++)
		dp[i] = 999;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j*j <= i; j++)
		{
			if (dp[i] > dp[j*j] + dp[i - j*j])
				dp[i] = dp[j*j] + dp[i - j*j];
			if (j*j == i)
				dp[i] = 1;
		}
	}

	cout << dp[N];
	
	return 0;
}