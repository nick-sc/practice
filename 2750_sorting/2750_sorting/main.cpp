#include <iostream>

using namespace std;

int nums, tmp;
int arr[1001];

void swap(int a, int b)
{
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void quick_sort(int st, int ed)
{
	int pv = st;
	int l = pv + 1;
	int r = ed;
	
	if (ed - st <= 0)
		return;

	while (1)
	{
		for (l; l < ed; l++)
		{
			if (arr[pv] < arr[l])
				break;
		}

		for (r; r > st; r--)
		{
			if (arr[pv] > arr[r])
				break;
		}
		

		if (r > l)
		{
			swap(r, l);
			continue;
		}
		if (r > st)
		{
			swap(st, r);
			quick_sort(st, r - 1);
		}

		pv = st = r + 1;
		l = st + 1;
		r = ed;

		if (ed - st <= 0)
			return;
	}		
}


int main()
{
	cin >> nums;

	for (int i = 0; i < nums; i++)
		cin >> arr[i];

	quick_sort(0, nums - 1);

	for (int i = 0; i < nums; i++)
		cout << arr[i] << '\n';

	return 0;
}