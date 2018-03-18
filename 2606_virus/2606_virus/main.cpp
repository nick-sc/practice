#include <iostream>

using namespace std;

int num, lin;
int map[101][101];
int vsit[101];
int cnt = 0;
int q_x[10000];
int q_y[10000];
int q_f = 0;
int q_r = 0;
int x, y;

void bfs()
{
	vsit[1] = 1;
	while (q_f < q_r)
	{
		x = q_x[q_f];
		y = q_y[q_f++];
		cnt++;
		
		for (int i = 1; i <= num; i++)
		{
			if (map[y][i] == 1 && vsit[i] == 0)
			{
				vsit[i] = 1;
				q_x[q_r] = y;
				q_y[q_r++] = i;
			}
		}
	}
}


int main()
{
	cin >> num;
	cin >> lin;

	for (int i = 1; i <= lin; i++)
	{
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;

		if (x == 1)
		{
			q_x[q_r] = x;
			q_y[q_r++] = y;
			vsit[y] = 1;
		}
		if (y == 1)
		{
			q_x[q_r] = y;
			q_y[q_r++] = x;
			vsit[x] = 1;
		}
	}

	bfs();

	cout << cnt;

	return 0;
}