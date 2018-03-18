#include <iostream>

using namespace std;

int n, m;
int vsit[101][101];
char maze[101][101];
int q_x[20000];
int q_y[20000];
int q_f, q_r, x, nx, ny, y;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs()
{
	q_f = 10000;
	q_r = 10000;

	q_x[q_r] = 1;
	q_y[q_r++] = 1;
	vsit[1][1] = 0;

	while (q_f < q_r)
	{
		x = q_x[q_f];
		y = q_y[q_f];

		for (int d = 0; d < 4; d++)
		{
			nx = x + dx[d];
			ny = y + dy[d];

			if (nx > 0 && nx < 101 && ny > 0 && ny < 101)
			{
				if (maze[nx][ny] == '0' && vsit[nx][ny] == -1)
				{
					vsit[nx][ny] = vsit[x][y];
					q_x[q_f] = nx;
					q_y[q_f--] = ny;
				}
				if (maze[nx][ny] == '1' && vsit[nx][ny] == -1)
				{
					vsit[nx][ny] = vsit[x][y] + 1;
					q_x[q_r] = nx;
					q_y[q_r++] = ny;
				}
			}
		}
		q_f++;
	}

}


int main()
{
	cin >> m >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> maze[i][j];
			vsit[i][j] = -1;
		}	
	}
	
	bfs();

	cout << vsit[n][m];

	return 0;
}