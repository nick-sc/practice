#include <iostream>

using namespace std;

int n, k;
int ways[200001];
int vsit[200001];
int cnt[200001];
int que[300000];
int q_f = 0;
int q_r = 0;

void bfs()
{
	vsit[n] = 1;
	ways[n] = 1;
	cnt[n] = 0;
	que[q_r++] = n;

	while (q_f < q_r)
	{
		int cur = que[q_f++];

		if (cur == k)
			break;

		if (cur - 1 >= 0)
		{
			if (vsit[cur - 1] != 1)
			{
				ways[cur - 1] = ways[cur];
				vsit[cur - 1] = 1;
				cnt[cur - 1] = cnt[cur] + 1;
				que[q_r++] = cur - 1;
			}
			else if (cnt[cur - 1] == cnt[cur] + 1)
				ways[cur - 1] = ways[cur - 1] + ways[cur];
		}
		if (cur + 1 <= 100001)
		{
			if (vsit[cur+1] != 1)
			{
				ways[cur + 1] = ways[cur];
				vsit[cur + 1] = 1;
				cnt[cur + 1] = cnt[cur] + 1;
				que[q_r++] = cur + 1;
			}
			else if (cnt[cur + 1] == cnt[cur] + 1)
				ways[cur + 1] = ways[cur + 1] + ways[cur];
		}
		if (2 * cur <= 100001)
		{
			if (vsit[2 * cur] != 1)
			{
				ways[2 * cur] = ways[cur];
				vsit[2 * cur] = 1;
				cnt[2 * cur] = cnt[cur] + 1;
				que[q_r++] = 2 * cur;
			}
			else if (cnt[2 * cur] == cnt[cur] + 1)
				ways[2 * cur] = ways[2 * cur] + ways[cur];
		}
	}
}


int main()
{
	cin >> n >> k;

	bfs();
	
	cout << cnt[k] << "\n" << ways[k];

	return 0;
}