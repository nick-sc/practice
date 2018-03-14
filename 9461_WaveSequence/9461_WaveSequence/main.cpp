#include <iostream>

using namespace std;

int main()
{
	int tc;
	long long waveS[101];

	cin >> tc;

	waveS[1] = 1;
	waveS[2] = 1;
	waveS[3] = 1;
	waveS[4] = 2;
	waveS[5] = 2;

	for (int i = 6; i < 101; i++)
		waveS[i] = waveS[i - 1] + waveS[i - 5];

	while (tc--)
	{
		int n;
		cin >> n;
		cout << waveS[n] << '\n';
	}

	return 0;
}