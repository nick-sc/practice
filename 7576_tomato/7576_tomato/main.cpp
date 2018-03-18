#include <iostream>

using namespace std;

int r, c;
int tmt[1001][1001];
int vsit[1001][1001];
int cnt[1001][1001];
int q_x[1000001];
int q_y[1000001];
int q_f = 0;
int q_r = 0;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int x, y, nx, ny;


void bfs()
{
	while (q_f < q_r)
	{
		x = q_x[q_f];
		y = q_y[q_f++];

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 1 || nx > r || ny < 1 || ny > c)
				continue;
			else
			{
				if (tmt[nx][ny] == 0 && vsit[nx][ny] == 0)
				{
					vsit[nx][ny] = 1;
					q_x[q_r] = nx;
					q_y[q_r++] = ny;
					cnt[nx][ny] = cnt[x][y] + 1;
				}
			}
		}
	}
}


int main()
{
	cin >> c >> r;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> tmt[i][j];

			if (tmt[i][j] == 1)		//익은 토마토가 있으면 큐에 넣기
			{
				q_x[q_r] = i;
				q_y[q_r++] = j;
				vsit[i][j] = 1;
				cnt[i][j] = 1;
			}
			else if (tmt[i][j] == -1)	//토마토가 없는 부분
				cnt[i][j] = -1;
		}
	}

	if (q_f == q_r)			//다 안익은 것들만 있을 때
	{
		cout << "-1";
		return 0;
	}
	if (q_r == r*c)			//다 익은 것들만 있을 때
	{
		cout << "0";
		return 0;
	}

	bfs();

	int ans = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (cnt[i][j] == 0)
			{
				cout << "-1";
				return 0;
			}
			if (ans < cnt[i][j])
				ans = cnt[i][j];
		}
	}
	
	cout << ans-1;

	return 0;
}