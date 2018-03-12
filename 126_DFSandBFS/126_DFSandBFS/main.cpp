#include <iostream>

using namespace std;

int n_node, n_edge, stt, n_1, n_2;
int map[1001][1001] = { 0 };
int dfs_visited[1001] = { 0 };
int bfs_visited[1001] = { 0 };
int bfs_queue[10001] = { 0 };
int q_f = 0;
int q_r = 0;

void my_dfs(int visited)
{
	dfs_visited[visited] = 1;
	cout << visited << " ";

	for (int i = 1; i <= n_node; i++)
	{
		if (map[visited][i] == 1 && !dfs_visited[i])
			my_dfs(i);
	}

	return;
}

void my_bfs(int visited)
{
	bfs_visited[visited] = 1;
	bfs_queue[q_r++] = visited;

	while (q_f < q_r)
	{
		visited = bfs_queue[q_f++];
		cout << visited << " ";
		for (int i = 1; i <= n_node; i++)
		{
			if (map[visited][i] == 1 && !bfs_visited[i])
			{
				bfs_visited[i] = 1;
				bfs_queue[q_r++] = i;
			}
		}
	}

	return;
}

int main()
{
	cin >> n_node >> n_edge >> stt;

	for (int i = 1; i <= n_edge; i++)
	{
		cin >> n_1 >> n_2;
		map[n_1][n_2] = 1;
		map[n_2][n_1] = 1;
	}

	my_dfs(stt);
	cout << "\n";
	my_bfs(stt);
	
	return 0;
}