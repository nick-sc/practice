#include <iostream>

using namespace std;

int vsit[2000][2000];
int que[2000][2];
int q_f = 0;
int q_r = 0;
int tar;

void bfs()
{
	vsit[1][0] = 0;
	que[q_r][0] = 1;
	que[q_r++][1] = 0;
	
	while (q_f < q_r)
	{
		int cur = que[q_f][0];
		int clip = que[q_f++][1];

		if (vsit[cur][cur] == -1)
		{
			vsit[cur][cur] = vsit[cur][clip] + 1;
			que[q_r][0] = cur;
			que[q_r++][1] = cur;
		}
		if (cur + clip <= tar && vsit[cur+clip][clip] == -1)
		{
			vsit[cur + clip][clip] = vsit[cur][clip]+1;
			que[q_r][0] = cur + clip;
			que[q_r++][1] = clip;
		}
		if (cur - 1 >= 0 && vsit[cur - 1][clip] == -1)
		{
			vsit[cur - 1][clip] = vsit[cur][clip] + 1;
			que[q_r][0] = cur - 1;
			que[q_r++][1] = clip;
		}
	}

}


int main()
{
	cin >> tar;

	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j < 2000; j++)
			vsit[i][j] = -1;
	}

	bfs();

	int ans = -1;

	for (int i = 0; i <= tar; i++)
	{
		if (vsit[tar][i] > -1) {
			if (ans == -1 || ans > vsit[tar][i])
				ans = vsit[tar][i];
		}
	}

	cout << ans;

	return 0;
}