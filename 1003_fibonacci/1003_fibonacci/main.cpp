#include <iostream>

using namespace std;

int fibo_0[41] = { 0 };
int fibo_1[41] = { 0 };


int fib_0(int n)
{
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 0;
	}
	else if (fibo_0[n]) {
		return fibo_0[n];
	}
	else {
		fibo_0[n] = fib_0(n - 1) + fib_0(n - 2);
		return fibo_0[n];
	}
}

int fib_1(int n)
{
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else if (fibo_1[n]) {
		return fibo_1[n];
	}
	else {
		fibo_1[n] = fib_1(n - 1) + fib_1(n - 2);
		return fibo_1[n];
	}
}

int main()
{
	int tc;
	int num;
	int cnt0, cnt1;

	cin >> tc;

	while (tc--)
	{
		cin >> num;
		cnt0 = fib_0(num);
		cnt1 = fib_1(num);

		cout << cnt0 << " " << cnt1 << "\n";
	}

	return 0;
}