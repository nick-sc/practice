#include <iostream>

using namespace std;

int last_num;
int digits = 0;

int main()
{
	cin >> last_num;

	for (int i = 1; i <= last_num; i++)
	{
		if (i < 10)
			digits += 1;
		else if (i < 100)
			digits += 2;
		else if (i < 1000)
			digits += 3;
		else if (i < 10000)
			digits += 4;
		else if (i < 100000)
			digits += 5;
		else if (i < 1000000)
			digits += 6;
		else if (i < 10000000)
			digits += 7;
		else if (i < 100000000)
			digits += 8;
		else
			digits += 9;
	}
	cout << digits;
	
	return 0;
}