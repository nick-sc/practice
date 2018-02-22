#include <iostream>

using namespace std;

int visited[25][25] = { 0 };
char map[25][25] = { 0 };
int map_size = 0;
int danji = 0;
int cnt = 1;

void  find_danji(int r, int c)
{
	if (r - 1 > -1)			//위로 올라 갈 수 있을 때
	{
		if (map[r-1][c] == '1' && visited[r-1][c] == 0)
		{
			visited[r-1][c] = cnt;
			find_danji(r - 1, c);
		}
	}
	
	if (r + 1 < map_size)	//아래로 내려 갈 수 있을 때
	{
		if (map[r+1][c] == '1' && visited[r+1][c] == 0)
		{
			visited[r+1][c] = cnt;
			find_danji(r+1, c);
		}
	}
	
	if (c - 1 > -1)		//왼쪽으로 갈 수 있을 때
	{
		if (map[r][c-1] == '1' && visited[r][c-1] == 0)
		{
			visited[r][c-1] = cnt;
			find_danji(r, c-1);
		}
	}
	
	if (c + 1 < map_size)	//오른쪽으로 갈 수 있을 때
	{
		if (map[r][c+1] == '1' && visited[r][c+1] == 0)
		{
			visited[r][c+1] = cnt;
			find_danji(r, c+1);
		}
	}	
}

int main()
{
	int tmp;

	cin >> map_size;

	for (int r = 0; r < map_size; r++)
	{
		for (int c = 0; c < map_size; c++)
			cin >> map[r][c];
	}

	for (int r = 0; r < map_size; r++)
	{
		for (int c = 0; c < map_size; c++)
		{
			if (map[r][c] == '1' && visited[r][c] == 0)
			{
				visited[r][c] = cnt;
				find_danji(r, c);
				cnt++;
			}
		}
	}
	
	cout << cnt - 1 << endl;

	int *ans = new int[cnt-1];

	for (int i = 1; i < cnt; i++)
	{
		int num_danji = 0;
		for (int r = 0; r < map_size; r++)
		{
			for (int c = 0; c < map_size; c++)
			{
				if (visited[r][c] == i)
					num_danji++;
			}
		}
		ans[i-1] = num_danji;
	}

	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = i + 1; j < cnt - 1; j++)
		{
			if (ans[i] > ans[j])
			{
				tmp = ans[i];
				ans[i] = ans[j];
				ans[j] = tmp;
			}
		}
	}

	for (int i = 0; i < cnt - 1; i++)
		cout << ans[i] << endl;

	return 0;
}