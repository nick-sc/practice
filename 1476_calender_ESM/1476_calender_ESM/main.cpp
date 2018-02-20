#include <iostream>
#define E_MAX 15
#define S_MAX 28
#define M_MAX 19
#define Y_MAX 7980

using namespace std;

int e, s, m;

int main()
{
	cin >> e >> s >> m;

	e = e - 1;
	s = s - 1;
	m = m - 1;
	
	
	for (int i = 0; i < Y_MAX; i++)
	{
		if (i%E_MAX == e && i%S_MAX == s && i%M_MAX == m)
		{
			cout << i+1;
			break;
		}
	}

	return 0;
}