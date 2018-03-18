#include <iostream>

using namespace std;

int n, m, ans;
int vsit[10001];
int cnt[10001];
int map[10001][10001];
int que[100001];
int q_f = 0;
int q_r = 0;
int x, y;

void init()
{
	q_f = 0;
	q_r = 0;
	for (int i = 1; i <= n; i++)
		vsit[i] = 0;
}

void bfs(int num)
{
	int cur;
	cnt[num]++;
	vsit[num] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (map[num][i] == 1)
		{
			vsit[i] = 1;
			que[q_r++] = i;
			cnt[num]++;
		}
	}

	while (q_f < q_r)
	{
		cur = que[q_f++];

		for (int j = 1; j <= n; j++)
		{
			if (map[cur][j] == 1 && vsit[j] == 0)
			{
				vsit[j] = 1;
				que[q_r++] = j;
				cnt[num]++;
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		map[y][x] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		init();
		bfs(i);
		if (ans < cnt[i])
			ans = cnt[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == ans)
			cout << i << " ";
	}


	return 0;
}