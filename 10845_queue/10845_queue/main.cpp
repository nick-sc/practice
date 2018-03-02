#include <iostream>

using namespace std;

int my_queue[10001] = { 0 };
int num_inst;
int num_input;

int main()
{
	cin >> num_inst;
	int front = 0;
	int rear = 0;

	while (num_inst--)
	{
		char inst[10] = { '\0' };

		cin >> inst;
		

		if (inst[0] == 'p' && inst[1] == 'u')
		{
			cin >> num_input;
			my_queue[rear] = num_input;
			rear++;
		}
		if (inst[0] == 'p' && inst[1] == 'o')
		{
			if (my_queue[front] == 0)
				cout << "-1" << "\n";
			else
			{
				cout << my_queue[front] << "\n";
				front++;
			}
		}
		if (inst[0] == 's' && inst[1] == 'i')
		{
			cout << rear - front << "\n";
		}
		if (inst[0] == 'e' && inst[1] == 'm')
		{
			if (front == rear)
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
		if (inst[0] == 'f' && inst[1] == 'r')
		{
			if (front == rear)
				cout << "-1" << "\n";
			else
				cout << my_queue[front] << "\n";
		}
		if (inst[0] == 'b' && inst[1] == 'a')
		{
			if (front == rear)
				cout << "-1" << "\n";
			else
				cout << my_queue[rear-1] << "\n";
		}
	}
	
	return 0;
}