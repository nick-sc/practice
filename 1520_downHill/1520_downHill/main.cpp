#include <iostream>
#define IOSFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int M, N;
int visited[502][502] = { 0 };
int map[502][502] = { 0 };
int dp[502][502] = { 0 };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


int downHill(int x, int y)
{
	if (x == 1 && y == 1)
		return dp[1][1] = 1;
	else if (visited[x][y])
		return dp[x][y];
	else
	{
		visited[x][y] = 1;
		for (int k = 0; k < 4; k++)
		{
			if (map[x][y] < map[x + dx[k]][y + dy[k]])
				dp[x][y] += downHill(x + dx[k], y + dy[k]);
		}
		return dp[x][y];
	}
}

int main()
{
	cin >> M >> N;
	
	
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	}
	
	cout << downHill(M, N);
	
	cin >> M;

	return 0;
}