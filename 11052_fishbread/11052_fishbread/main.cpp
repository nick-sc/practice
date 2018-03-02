#include <iostream>

using namespace std;

int prices[1001];
int dp[1001];
int num_bread;


int main()
{
	cin >> num_bread;

	for (int i = 1; i <= num_bread; i++)
		cin >> prices[i];


	for (int i = 1; i <= num_bread; i++)
	{
		for (int k = 1; k <= i; k++)
		{
			if (dp[i] < dp[i - k] + prices[k])
				dp[i] = dp[i - k] + prices[k];
		}
	}

	cout << dp[num_bread];

	return 0;
} 