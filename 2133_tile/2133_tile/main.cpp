#include <iostream>

using namespace std;

int main()
{
	int n;
	int dp[31] = { 0 };

	cin >> n;

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 2; i <= n; i += 2)
	{
		dp[i] = dp[i - 2] * 3;
		for (int j = i-4; j >= 0; j -= 2)
			dp[i] += dp[j] * 2;
	}
	
	cout << dp[n];

	return 0;
}