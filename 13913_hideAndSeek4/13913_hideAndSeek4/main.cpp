#include <iostream>

using namespace std;

int n, k;
int routes[200001];
int track[200001];
int vsit[200001];
int cnt[200001];
int que[300000];
int q_f = 0;
int q_r = 0;

void bfs()
{
	routes[n] = -1;
	vsit[n] = 1;
	cnt[n] = 0;
	que[q_r++] = n;

	while (q_f < q_r)
	{
		int cur = que[q_f++];

		if (cur == k)
			break;

		if (cur - 1 >= 0 && vsit[cur - 1] != 1)
		{
			routes[cur - 1] = cur;
			vsit[cur - 1] = 1;
			cnt[cur - 1] = cnt[cur] + 1;
			que[q_r++] = cur - 1;
		}
		if (cur + 1 <= 100001 && vsit[cur + 1] != 1)
		{
			routes[cur + 1] = cur;
			vsit[cur + 1] = 1;
			cnt[cur + 1] = cnt[cur] + 1;
			que[q_r++] = cur + 1;
		}
		if (2 * cur <= 100001 && vsit[2 * cur] != 1)
		{
			routes[2 * cur] = cur;
			vsit[2 * cur] = 1;
			cnt[2 * cur] = cnt[cur] + 1;
			que[q_r++] = 2 * cur;
		}
	}
}

void tracking()
{
	int i = 0;
	int r = k;
	while (routes[r] != -1)
	{
		r = track[i++] = routes[r];
	}
}


int main()
{
	cin >> n >> k;

	bfs();
	tracking();

	cout << cnt[k] << "\n";

	for (int i = cnt[k] - 1; i >= 0; i--)
		cout << track[i] << " ";
	cout << k << " ";


	return 0;
}