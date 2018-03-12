#include <iostream>

using namespace std;

int s[500][500] = { 0 };
int tri[500][500] = { 0 };
int n;
int ans = 0;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];
	}

	s[0][0] = tri[0][0];
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				if (s[i][j] < s[i - 1][j] + tri[i][j])
					s[i][j] = s[i - 1][j] + tri[i][j];
			}
			else if (j == i)
			{
				if (s[i][j] < s[i - 1][j-1] + tri[i][j])
					s[i][j] = s[i - 1][j-1] + tri[i][j];
			}
			else
			{
				if (s[i][j] < s[i - 1][j] + tri[i][j])
					s[i][j] = s[i - 1][j] + tri[i][j];
				if (s[i][j] < s[i - 1][j - 1] + tri[i][j])
					s[i][j] = s[i - 1][j - 1] + tri[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (ans < s[n - 1][i])
			ans = s[n - 1][i];
	}

	cout << ans;

	return 0;
}