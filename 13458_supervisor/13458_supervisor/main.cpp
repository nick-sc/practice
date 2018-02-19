#include <iostream>

using namespace std;

int main()
{
	int num_of_testroom = 0;
	int B, C = { 0 };
	long long needed = 0;
	int temp = 0;
	
	cin >> num_of_testroom;			//¹æ °¹¼ö ÀÔ·Â

	int *num_of_tester = new int[num_of_testroom];
	
	for (int i = 0; i < num_of_testroom; i++)
		cin >> num_of_tester[i];

	cin >> B;
	cin >> C;
		
	for (int i = 0; i < num_of_testroom; i++)
	{
		temp = (num_of_tester[i] - B);
		needed++;
		if (temp > 0)
		{
			if (temp%C == 0)
				needed = needed + (int)temp / C;
			else
				needed = needed + (int)temp / C + 1;
		}
	}

	cout << needed;

	delete [ ] num_of_tester;
			
	return 0;
}
