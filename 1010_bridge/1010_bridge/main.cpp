#include<iostream>

using namespace std;

int num_testcase, west_side, east_side;		//입력받는 변수들
long long pos_count;			//경우의 수를 카운트하는 변수

int main()
{
	cin >> num_testcase;

	while(num_testcase)
	{
		cin >> west_side;
		cin >> east_side;

		int bigger = east_side;
		int smaller = west_side;
		int differ = east_side - west_side;
		pos_count = 1;

		if (smaller > differ)
		{
			while (bigger > smaller)
			{
				pos_count = pos_count * bigger;
				bigger--;
			}
			while (differ)
			{
				pos_count = pos_count / differ;
				differ--;
			}
		}

		else
		{
			while (bigger > differ)
			{
				pos_count = pos_count * bigger;
				bigger--;
			}
			while (smaller)
			{
				pos_count = pos_count / smaller;
				smaller--;
			}
		}
			
		cout << pos_count << endl;

		num_testcase--;
	}

	return 0;
}