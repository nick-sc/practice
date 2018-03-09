#include <iostream>

using namespace std;

int _isP(int k)
{
	for (int j = 2; j*j <= k; j++)
	{
		if (k % j == 0)
		{
			return 0;
		}
	}

	return 1;
}


int main()
{
	int tc;
	int gold;
	
	cin >> tc;

	while (tc--)
	{
		cin >> gold;
		if (gold == 0)
			break;

		for (int i = gold/2; i > 1; i--)
		{
			if (_isP(i))
			{
				if (_isP(gold - i))
				{
					cout << i << " " << gold - i << "\n";
					break;
				}
			}
		}
	}
		
	return 0;
}