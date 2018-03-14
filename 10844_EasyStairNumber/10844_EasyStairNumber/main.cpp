#include <iostream>

using namespace std;

int main()
{
	int tar;
	long long arr[10][101] = { 0 };
	int ans=0;

	cin >> tar;

	for (int i = 1; i <= 9; i++)
		arr[i][1] = 1;


	for (int i = 2; i <= tar; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				arr[j][i] = arr[j + 1][i - 1];
			else if (j == 9)
				arr[j][i] = arr[j - 1][i - 1];
			else
				arr[j][i] = (arr[j - 1][i - 1] + arr[j + 1][i - 1]) % 1000000000;
		}
	}
	
	for (int i = 0; i <= 9; i++)
		ans = (ans + arr[i][tar]) %1000000000;

	cout << ans;

	cin >> tar;

	return 0;
}
