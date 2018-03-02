#include <iostream>

using namespace std;

int my_stack[10001] = { 0 };
int num_inst;
int num_input;

int main()
{
	cin >> num_inst;
	int s_bot = 0;
	int s_top = 0;

	while (num_inst--)
	{
		char inst[10] = { '\0' };

		cin >> inst;


		if (inst[0] == 'p' && inst[1] == 'u')
		{
			cin >> num_input;
			my_stack[s_top] = num_input;
			s_top++;
		}
		if (inst[0] == 'p' && inst[1] == 'o')
		{
			if (s_top == s_bot)
				cout << "-1" << "\n";
			else
			{
				cout << my_stack[s_top-1] << "\n";
				my_stack[s_top - 1] = 0;
				s_top--;
			}
		}
		if (inst[0] == 's' && inst[1] == 'i')
		{
			cout << s_top - s_bot << "\n";
		}
		if (inst[0] == 'e' && inst[1] == 'm')
		{
			if (s_top == s_bot)
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
		if (inst[0] == 't' && inst[1] == 'o')
		{
			if (s_top == s_bot)
				cout << "-1" << "\n";
			else
				cout << my_stack[s_top-1] << "\n";
		}
	}

	
	return 0;
}