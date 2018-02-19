#include <iostream>

using namespace std;

typedef struct {
	int num_of_cell;
	int direction;
	int largest;
} cells;

cells map[100][100];
cells nxt_map[100][100];

int movement[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int map_size;
int counting;
int repeat;
int num_of_cluster;

int x, y, nxt_x, nxt_y, total;

void cell_moving()
{
	for (int i = 0; i < map_size; i++)
	{
		for (int j = 0; j < map_size; j++)
		{
			if (map[i][j].num_of_cell > 0)
			{
				nxt_y = i + movement[map[i][j].direction-1][0];
				nxt_x = j + movement[map[i][j].direction-1][1];

				if (nxt_y == 0 || nxt_y == map_size-1 || nxt_x == 0 || nxt_x == map_size-1)
				{
					nxt_map[nxt_y][nxt_x].num_of_cell = map[i][j].num_of_cell / 2;
					if (map[i][j].direction == 1)
						nxt_map[nxt_y][nxt_x].direction = 2;
					else if (map[i][j].direction == 2)
						nxt_map[nxt_y][nxt_x].direction = 1;
					else if (map[i][j].direction == 3)
						nxt_map[nxt_y][nxt_x].direction = 4;
					else if (map[i][j].direction == 4)
						nxt_map[nxt_y][nxt_x].direction = 3;
				}													//red zone�� �浹���� ���
				else
				{
					nxt_map[nxt_y][nxt_x].num_of_cell = nxt_map[nxt_y][nxt_x].num_of_cell + map[i][j].num_of_cell;
					if (map[i][j].num_of_cell > nxt_map[nxt_y][nxt_x].largest)
					{
						nxt_map[nxt_y][nxt_x].largest = map[i][j].num_of_cell;
						nxt_map[nxt_y][nxt_x].direction = map[i][j].direction;
					}												//�ΰ� �̻��� cluster�� ������ ��, ���� ����
					
				}
					
			}
		}
	}

	for (int i = 0; i < map_size; i++)
	{
		for (int j = 0; j < map_size; j++)
		{
			map[i][j] = nxt_map[i][j];
			nxt_map[i][j] = { 0,0,0 };
		}
	}							//���� round�� ���� map ����
			
	return;	
}

int main()
{
	int test_case;

	cin >> test_case;

	for (int r = 0; r < test_case; r++)
	{
		cin >> map_size;
		for (int i = 0; i < map_size; i++)
		{
			for (int j = 0; j < map_size; j++)
			{
				map[i][j] = { 0,0,0 };
				nxt_map[i][j] = { 0,0,0 };
			}
		}									//�ݺ� ���� ���� map �ʱ�ȭ

		cin >> repeat;
		cin >> num_of_cluster;

		for (int set = 0; set < num_of_cluster; set++)
		{
			cin >> y;
			cin >> x;
			cin >> map[y][x].num_of_cell;
			cin >> map[y][x].direction;
		}									//�ʱ� �� ����
		
		for (counting = 0; counting < repeat; counting++)
			cell_moving();
		
		total = 0;
		for (int i = 0; i < map_size; i++)
		{
			for (int j = 0; j < map_size; j++)
				total = total + map[i][j].num_of_cell;
		}
		
		printf("#%d %d\n", r+1, total);
	}
	
	return 0;
}