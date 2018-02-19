#include <iostream>

using namespace std;

int row, col, cur;
int biggest=0;

int **map = new int*[row];
//int map[502][502] = { 0 };

void search(int r, int c)
{
	if (c + 3 < col)					//¦��� 2��
	{
		cur = map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r][c + 3];
		biggest = biggest < cur ? cur : biggest;
	}
	if (r + 3 < row)
	{
		cur = map[r][c] + map[r + 1][c] + map[r + 2][c] + map[r + 3][c];
		biggest = biggest < cur ? cur : biggest;
	}

	if (c + 1 < col && r + 1 < row)		//���簢��
	{
		cur = map[r][c] + map[r + 1][c] + map[r][c+1] + map[r+1][c+1];
		biggest = biggest < cur ? cur : biggest;
	}
	
	if (c + 1 < col && r + 2 < row)			//���η� �䤤�� 4��
	{
		cur = map[r][c] + map[r + 1][c] + map[r+2][c] + map[r + 2][c + 1];
		biggest = biggest < cur ? cur : biggest;
		cur = map[r+2][c] + map[r][c+1] + map[r+1][c + 1] + map[r + 2][c+1];
		biggest = biggest < cur ? cur : biggest;
		cur = map[r][c] + map[r + 1][c] + map[r+2][c] + map[r][c + 1];
		biggest = biggest < cur ? cur : biggest;
		cur = map[r][c] + map[r][c + 1] + map[r + 1][c + 1] + map[r + 2][c + 1];
		biggest = biggest < cur ? cur : biggest;
	}

	if (c + 2 < col && r + 1 < row)			//���η� �䤤�� 4��
	{
		cur = map[r][c] + map[r + 1][c] + map[r + 1][c+1] + map[r + 1][c + 2];
		biggest = biggest < cur ? cur : biggest;
		cur = map[r][c+2] + map[r + 1][c] + map[r + 1][c + 1] + map[r + 1][c + 2];
		biggest = biggest < cur ? cur : biggest;
		cur = map[r][c] + map[r][c+1] + map[r][c + 2] + map[r + 1][c];
		biggest = biggest < cur ? cur : biggest;
		cur = map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r + 1][c+2];
		biggest = biggest < cur ? cur : biggest;
	}

	if (c + 1 < col && r + 2 < row)			//���η� �� ���� 2��
	{
		cur = map[r][c] + map[r + 1][c] + map[r + 1][c + 1] + map[r + 2][c + 1];
		biggest = biggest < cur ? cur : biggest;
		cur = map[r][c + 1] + map[r + 1][c] + map[r + 1][c + 1] + map[r + 2][c];
		biggest = biggest < cur ? cur : biggest;
	}

	if (c + 2 < col && r + 1 < row)			//���η� �� ���� 2��
	{
		cur = map[r][c+1] + map[r][c+2] + map[r + 1][c] + map[r + 1][c + 1];
		biggest = biggest < cur ? cur : biggest;
		cur = map[r][c] + map[r][c+1] + map[r + 1][c + 1] + map[r + 1][c+2];
		biggest = biggest < cur ? cur : biggest;
	}

	if (c + 1 < col && r + 2 < row)			//���η� �� ���� 2��
	{
		cur = map[r][c] + map[r + 1][c] + map[r+2][c] + map[r + 1][c + 1];
		biggest = biggest < cur ? cur : biggest;
		cur = map[r+1][c] + map[r][c+1] + map[r + 1][c + 1] + map[r + 2][c+1];
		biggest = biggest < cur ? cur : biggest;
	}

	if (c + 2 < col && r + 1 < row)			//���η� �� ���� 2��
	{
		cur = map[r][c + 1] + map[r+1][c] + map[r + 1][c+1] + map[r + 1][c + 2];
		biggest = biggest < cur ? cur : biggest;
		cur = map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r + 1][c + 1];
		biggest = biggest < cur ? cur : biggest;
	}
}


int main()
{
	cin >> row >> col;

	for (int i = 0; i < row; i++)
		map[i] = new int[col];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			search(i, j);
		}
	}

	cout << biggest;

	//delete[] map;
	
	return 0;
}