#include <iostream>

using namespace std;

int queue[5001];
int visit[5001] = { 0 };
int N, M;

int main()
{
	cin >> N, M;
	int inc = 0;
	int cnt = 1;

	while (cnt <= N)
	{
		int k = 0;
		while (k < 3)
		{
			inc++;
			if (!visit[(inc - 1) % N + 1])
				k++;
		}

		visit[(inc - 1) % N + 1] = 1;
		queue[cnt] = (inc - 1) % N + 1;
		cnt++;
	}
	
	cout << "<" << queue[1];
	for (int i = 2; i <= N; i++)
		cout << ", " << queue[i];
	cout << ">";
	
	return 0;
}
