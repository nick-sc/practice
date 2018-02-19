#include <iostream>

using namespace std;

int test_case, map_size, cons_k, longest, highest;
int map[10][10], visited[10][10];
int direction[4][2] = {{ -1,0 }, { 1,0 }, { 0,-1 }, { 0,1 }};

void dfs(int cur_x, int cur_y, int cur_h, int cur_used_k, int cur_length)
{

	longest = longest > cur_length ? longest : cur_length;

	for (int i = 0; i < 4; i++)
	{
		int nxt_x = cur_x;
		int nxt_y = cur_y;
		int nxt_h;
		int nxt_used_k = cur_used_k;
		int nxt_length = cur_length;

		nxt_x = nxt_x + direction[i][0];
		nxt_y = nxt_y + direction[i][1];

		if (nxt_x < 0 || nxt_x >= map_size || nxt_y < 0 || nxt_y >= map_size)
			continue;						//맵사이즈보다 큰 경우 탐색 할 수 없음
		if (visited[nxt_x][nxt_y] == 1)
			continue;						//이미 방문했던 곳이면 탐색 할 수 없음
		
		nxt_h = map[nxt_x][nxt_y];

		if (nxt_h < cur_h)
		{
			nxt_length++;
			visited[cur_x][cur_y] = 1;
			dfs(nxt_x, nxt_y, nxt_h, nxt_used_k, nxt_length);
			visited[cur_x][cur_y] = 0;
		}									//현재 높이보다 낮은 경우 탐색 진행
		else
		{
			if (cur_used_k == 0 && nxt_h - cons_k < cur_h)
			{
				nxt_h = cur_h - 1;
				nxt_used_k = 1;

				nxt_length++;
				visited[nxt_x][nxt_y] = 1;
				dfs(nxt_x, nxt_y, nxt_h, nxt_used_k, nxt_length);
				visited[nxt_x][nxt_y] = 0;
			}								//현재 높이보다 낮지 않지만, k를 사용해서 낮출 수 있으면 탐색할 수 있음
		}									
	}

	return;
}


int main()
{
	int cur_x, cur_y, cur_h, cur_used_k, cur_length;

	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		longest = 0;
		highest = 0;

		cin >> map_size;
		cin >> cons_k;
		
		for (cur_x = 0; cur_x < map_size; cur_x++)				
		{
			for (cur_y = 0; cur_y < map_size; cur_y++)
			{
				visited[cur_x][cur_y] = 0;
				cin >> map[cur_x][cur_y];
				highest = highest > map[cur_x][cur_y] ? highest : map[cur_x][cur_y];
			}
		}													//문제 초기화 및 세팅

		for (cur_x = 0; cur_x < map_size; cur_x++)
		{
			for (cur_y = 0; cur_y < map_size; cur_y++)
			{
				if (map[cur_x][cur_y] == highest)
				{
					visited[cur_x][cur_y] = 1;
					cur_h = map[cur_x][cur_y];
					cur_used_k = 0;
					cur_length = 1;
					dfs(cur_x, cur_y, cur_h, cur_used_k, cur_length);
					visited[cur_x][cur_y] = 0;
				}
			}
		}													//가장 높은 곳일때만 탐색 시작
		
		printf("#%d %d\n", i+1, longest);
		//cout << "#" + i+1 + " " + longest << endl;
	}
				
	return 0;
}