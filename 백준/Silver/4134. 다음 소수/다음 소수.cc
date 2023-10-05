#include <iostream>
#include <cmath>

using namespace std;

bool check(long long num)
{
	for (int i = 2; i < floor(sqrt(num)) + 1; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		if (n < 2)
		{
			cout << 2 << "\n";
			continue;
		}
		while (true)
		{
			if (check(n))
			{
				cout << n << "\n";
				break;
			}
			n++;
		}
	}
}