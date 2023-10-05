#include <iostream>

using namespace std;

int main()
{
	int answer = 0;
	int a, b, c;
	cin >> a >> b >> c;

	if (a == b && b == c)
	{
		answer = 3 * a;
		cout << answer << "\n";
		return 0;
	}

	if (a >= b && a >= c)
	{
		if (a >= b + c)
			answer = 2 * (b + c) - 1;
		else
			answer = a + b + c;
	}
	else if (b >= a && b >= c)
	{
		if (b >= a + c)
			answer = 2 * (a + c) - 1;
		else
			answer = a + b + c;
	}
	else if (c >= a && c >= b)
	{
		if (c >= b + a)
			answer = 2 * (b + a) - 1;
		else
			answer = a + b + c;
	}

	cout << answer << "\n";
	return 0;
}