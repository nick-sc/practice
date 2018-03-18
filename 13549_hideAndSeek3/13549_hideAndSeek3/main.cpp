#include <iostream>

using namespace std;

int n, k;
int vsit[200001];
int cnt[200001];
int que[1000000];
int q_f = 500000;
int q_r = 500000;

void bfs()
{
	vsit[n] = 1;
	cnt[n] = 0;
	que[q_r++] = n;

	while (q_f < q_r)
	{
		int cur = que[q_f];

		if (2 * cur <= 200000 && vsit[2 * cur] != 1)
		{
			vsit[2 * cur] = 1;
			cnt[2 * cur] = cnt[cur];
			que[q_f--] = 2 * cur;
		}
		if (cur - 1 >= 0 && vsit[cur - 1] != 1)
		{
			vsit[cur - 1] = 1;
			cnt[cur - 1] = cnt[cur] + 1;
			que[q_r++] = cur - 1;
		}
		if (cur + 1 <= 200000 && vsit[cur + 1] != 1)
		{
			vsit[cur + 1] = 1;
			cnt[cur + 1] = cnt[cur] + 1;
			que[q_r++] = cur + 1;
		}
		
		q_f++;
	}
}


int main()
{
	cin >> n >> k;

	bfs();

	cout << cnt[k];

	return 0;
}