#include <iostream>

using namespace std;

int ans[201];
int vsit[201][201];
int bottles[3];
int from[6] = { 0,0,1,1,2,2 };
int to[6] = { 1,2,0,2,0,1 };
int que[40001][2];
int q_f = 0;
int q_r = 0;


int main()
{
	for (int i = 0; i < 3; i++)
		cin >> bottles[i];

	int tot = bottles[2];

	que[q_r][0] = 0;
	que[q_r++][1] = 0;
	vsit[0][0] = 1;
	ans[bottles[2]] = 1;

	while (q_f < q_r)
	{
		int cur[3];
		cur[0] = que[q_f][0];
		cur[1] = que[q_f++][1];
		cur[2] = tot - cur[0] - cur[1];

		for (int i = 0; i < 6; i++)
		{
			int nxt[3] = { cur[0], cur[1], cur[2] };
			nxt[to[i]] = nxt[to[i]] + nxt[from[i]];
			nxt[from[i]] = 0;

			if (nxt[to[i]] >= bottles[to[i]])
			{
				nxt[from[i]] = nxt[to[i]] - bottles[to[i]];
				nxt[to[i]] = bottles[to[i]];
			}
			if (vsit[nxt[0]][nxt[1]] == 0)
			{
				vsit[nxt[0]][nxt[1]] = 1;
				que[q_r][0] = nxt[0];
				que[q_r++][1] = nxt[1];
				if (nxt[0] == 0)
					ans[nxt[2]] = 1;
			}
		}
	}

	for (int i = 0; i <= bottles[2]; i++)
	{
		if (ans[i])
			cout << i << " ";
	}

	return 0;
}