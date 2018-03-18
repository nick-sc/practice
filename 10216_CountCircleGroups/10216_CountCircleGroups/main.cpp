#include <iostream>

using namespace std;

int n, x, y, r;
int bases[3001][3];
int map[5001][5001];
int radar[5001][5001];
int q_x[3001];
int q_y[3001];
int q_f, q_r;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void init()
{
	q_f = 0;
	q_r = 0;
	for (int i = 1; i <= 5000; i++)
	{
		for (int j = 1; j <= 5000; j++)
		{
			map[i][j] = 0;
			radar[i][j] = 0;
		}
	}
}

void bfs()
{
	while (q_f < q_r)
	{
		x = 



	}
}

int main()
{
	int tc;

	cin >> tc;

	while (tc--)
	{
		init();
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> x >> y >> r;
			bases[i][0] = x;
			bases[i][1] = y;
			bases[i][2] = r;
		}
			



	}

	return 0;
}