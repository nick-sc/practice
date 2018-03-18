#include <iostream>

using namespace std;

int r, c, h;
int tmt[101][101][101];
int vsit[101][101][101];
int cnt[101][101][101];
int q_x[1000001];
int q_y[1000001];
int q_z[1000001];
int q_f = 0;
int q_r = 0;
int dx[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 1, -1, 0, 0, 0, 0 };
int x, y, z, nx, ny, nz;


void bfs()
{
	while (q_f < q_r)
	{
		x = q_x[q_f];
		y = q_y[q_f];
		z = q_z[q_f++];

		for (int i = 0; i < 6; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			nz = z + dz[i];

			if (nx < 1 || nx > r || ny < 1 || ny > c || nz < 1 || nz > h)
				continue;
			else
			{
				if (tmt[nx][ny][nz] == 0 && vsit[nx][ny][nz] == 0)
				{
					vsit[nx][ny][nz] = 1;
					q_x[q_r] = nx;
					q_y[q_r] = ny;
					q_z[q_r++] = nz;
					cnt[nx][ny][nz] = cnt[x][y][z] + 1;
				}
			}
		}
	}
}


int main()
{
	cin >> c >> r >> h;

	for (int k = 1; k <= h; k++)
	{
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				cin >> tmt[i][j][k];

				if (tmt[i][j][k] == 1)		//익은 토마토가 있으면 큐에 넣기
				{
					q_x[q_r] = i;
					q_y[q_r] = j;
					q_z[q_r++] = k;
					vsit[i][j][k] = 1;
					cnt[i][j][k] = 1;
				}
				else if (tmt[i][j][k] == -1)	//토마토가 없는 부분
					cnt[i][j][k] = -1;
			}
		}
	}

	if (q_f == q_r)			//다 안익은 것들만 있을 때
	{
		cout << "-1";
		return 0;
	}
	if (q_r == r*c*h)			//다 익은 것들만 있을 때
	{
		cout << "0";
		return 0;
	}

	bfs();

	int ans = 0;
	for (int k = 1; k <= h; k++)
	{
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (cnt[i][j][k] == 0)
				{
					cout << "-1";
					return 0;
				}
				if (ans < cnt[i][j][k])
					ans = cnt[i][j][k];
			}
		}
	}

	cout << ans - 1;

	return 0;
}