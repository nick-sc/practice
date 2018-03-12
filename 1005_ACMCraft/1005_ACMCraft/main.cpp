#include <iostream>

using namespace std;

int num_bd, num_inst;
int building[1001];
int dp[1001] = { 0 };
int map[1001][1001] = { 0 };
int x, y, w, ans;


int scv_go(int tar)
{
	if (dp[tar])
		return dp[tar];

	int tmp = building[tar];
	for (int i = 1; i <= num_bd; i++)
	{
		if (map[i][tar])
		{
			if (tmp < scv_go(i) + building[tar])
				tmp = scv_go(i) + building[tar];
		}
	}
	return dp[tar] = tmp;
}


int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		for (int i = 0; i < 1001; i++)
		{
			dp[i] = 0;
			building[i] = 0;
			for (int j = 0; j < 1001; j++)
				map[i][j] = 0;
		}

		cin >> num_bd >> num_inst;

		for (int i = 1; i <= num_bd; i++)
			cin >> building[i];

		for (int i = 1; i <= num_inst; i++)
		{
			cin >> x >> y;
			map[x][y] = 1;
		}

		cin >> w;

		ans = scv_go(w);

		cout << ans << "\n";
	}

	return 0;
}