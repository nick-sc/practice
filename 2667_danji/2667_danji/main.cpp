#include <iostream>

using namespace std;

int visited[25][25] = { 0 };		//방문 했던 기록을 남기는 배열 (단지수로 체크)
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
			if (map[r][c] == '1' && visited[r][c] == 0)		//아파트가 있고, 방문을 안했던 곳이라면
			{
				visited[r][c] = cnt;			//현재 단지수를 표기
				find_danji(r, c);				//근처에 이어진 곳이 있는지 찾아보기
				cnt++;							//다 찾았으면 단지 번호 증가
			}
		}
	}
	
	cout << cnt - 1 << endl;		//단지 수를 출력

	int *ans = new int[cnt-1];		//단지 수 만큼 배열 생성

	for (int i = 1; i < cnt; i++)
	{
		int num_danji = 0;
		for (int r = 0; r < map_size; r++)
		{
			for (int c = 0; c < map_size; c++)		//각 단지가 몇 동씩 갖고 있는지 확인
			{
				if (visited[r][c] == i)
					num_danji++;
			}
		}
		ans[i-1] = num_danji;			//각 단지별 배열에 저장
	}

	for (int i = 0; i < cnt - 1; i++)		//오름차순으로 정렬
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