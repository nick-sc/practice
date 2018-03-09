#include <iostream>

using namespace std;

int nums, tmp;
int arr[1000001];


void merge(int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//임시 어레이 생성
	int *L = new int [n1];
	int *R = new int [n2];

	//임시 어레이에 copy
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	//두 임시 어레이의 작은수부터 원래 어레이에 삽입
	i = 0; //어레이 L의 인덱스
	j = 0; //어레이 R의 인덱스
	k = l; //원래 어레이에 놓아야하는 인덱스
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//L이나 R에 남은거 하나가 있으면 넣어주기
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		merge_sort(l, m);
		merge_sort(m + 1, r);

		merge(l, m, r);
	}
}


int main()
{
	cin >> nums;

	for (int i = 0; i < nums; i++)
		cin >> arr[i];

	merge_sort(0, nums - 1);

	for (int i = 0; i < nums; i++)
		cout << arr[i];

	return 0;
}