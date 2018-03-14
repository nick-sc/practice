#include <iostream>

using namespace std;

int a, b, c, tmp;
int cnt = 0;


int main()
{
	cin >> a >> b >> c;

	while (b-a > 1 || c-b > 1)
	{
		if (b-a < c-b)
		{
			tmp = b + 1;
			a = b;
			b = tmp;
			cnt++;
		}
		else
		{
			tmp = b - 1;
			c = b;
			b = tmp;
			cnt++;
		}
	}

	cout << cnt;

	cin >> cnt;
	
	return 0;
}