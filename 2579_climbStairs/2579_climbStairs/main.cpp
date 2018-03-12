#include <iostream>

using namespace std;

int s[2][301] = { 0 };
int pts[301] = { 0 };
int num_stairs;
int ans;

int main()
{
	cin >> num_stairs;

	for (int i = 1; i <= num_stairs; i++)
		cin >> pts[i];

	s[0][1] = pts[1];

	for (int i = 2; i <= num_stairs; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (s[0][i] < s[j][i-2] + pts[i])
				s[0][i] = s[j][i-2] + pts[i];
		}

		if (s[1][i] < s[0][i - 1] + pts[i])
			s[1][i] = s[0][i - 1] + pts[i];
	}

	for (int i = 0; i < 2; i++)
	{
		if (ans < s[i][num_stairs])
			ans = s[i][num_stairs];
	}

	cout << ans;
	
	return 0;
}


