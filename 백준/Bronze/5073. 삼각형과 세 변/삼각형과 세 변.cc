#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	while (true)
	{
		cin >> a >> b >> c;

		if (!a && !b && !c)
			break;
		
		if (a > b && a > c)
		{
			if (a >= b + c)
			{
				cout << "Invalid" << "\n";
				continue;
			}
		}
		else if (b > a && b > c)
		{
			if (b >= a + c)
			{
				cout << "Invalid" << "\n";
				continue;
			}
		}
		else if (c > a && c > b)
		{
			if (c >= b + a)
			{
				cout << "Invalid" << "\n";
				continue;
			}
		}

		if (a == b && b == c)
			cout << "Equilateral" << "\n";
		else if (a == b || b == c || a == c)
			cout << "Isosceles" << "\n";
		else
			cout << "Scalene" << "\n";
	}
}