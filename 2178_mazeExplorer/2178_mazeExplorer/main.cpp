#include <iostream>

using namespace std;

int r, c;
char maze[102][102];
int vsit[102][102];
int cnt[102][102];
int q_x[10001];
int q_y[10001];
int q_f = 0;
int q_r = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
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
				if (maze[nx][ny] == '1' && vsit[nx][ny] == 0)
				{
					q_x[q_r] = nx;
					q_y[q_r++] = ny;
					vsit[nx][ny] = 1;
					cnt[nx][ny] = cnt[x][y] + 1;
				}
			}
		}
	}
}


int main()
{
	cin >> r >> c;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> maze[i][j];
			vsit[i][j] = 0;
		}
	}

	cnt[1][1] = 1;
	vsit[1][1] = 1;
	q_x[q_r] = 1;
	q_y[q_r++] = 1;

	bfs();

	cout << cnt[r][c];

	return 0;
}