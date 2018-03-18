#include <iostream>

using namespace std;

int n, m;
int vsit[1001][1001][2];
char map[1001][1001];
int q_x[100000];
int q_y[100000];
int q_z[100000];
int q_f, q_r, x, y, z, nx, ny;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int min(int a, int b)
{
	return a < b ? a : b;
}

void bfs()
{
	q_f = 0;
	q_r = 0;

	q_x[q_r] = 1;
	q_y[q_r] = 1;
	q_z[q_r++] = 1;
	vsit[1][1][0] = 1;
	vsit[1][1][1] = 1;
	
	while (q_f < q_r)
	{
		x = q_x[q_f];
		y = q_y[q_f];
		z = q_z[q_f++];

		for (int d = 0; d < 4; d++)
		{
			nx = x + dx[d];
			ny = y + dy[d];
												//map 범위 이내에서만 탐색
			if (nx > 0 && nx < 1001 && ny > 0 && ny < 1001)
			{									//벽이 없고, 방문하지 않은 경우
				if (map[nx][ny] == '0' && vsit[nx][ny][z] == -1)
				{
					vsit[nx][ny][z] = vsit[x][y][z] + 1;
					q_x[q_r] = nx;
					q_y[q_r] = ny;
					q_z[q_r++] = z;
				}								//벽이 있는데, 부실 수 있는 경우
				if (map[nx][ny] == '1' && vsit[nx][ny][z-1] == -1 && z == 1)
				{
					vsit[nx][ny][z-1] = vsit[x][y][z] + 1;
					q_x[q_r] = nx;
					q_y[q_r] = ny;
					q_z[q_r++] = z-1;
				}
			}
		}
	}

}


int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			vsit[i][j][0] = -1;
			vsit[i][j][1] = -1;
		}
	}

	bfs();

	if (vsit[n][m][0] > -1 && vsit[n][m][1] > -1)
		cout << min(vsit[n][m][0], vsit[n][m][1]);
	else if (vsit[n][m][0] > -1)
		cout << vsit[n][m][0];
	else if (vsit[n][m][1] > -1)
		cout << vsit[n][m][1];
	else
		cout << "-1";


	return 0;
}