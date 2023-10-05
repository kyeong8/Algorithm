#include <iostream>

using namespace std;

int main()
{
	long long cumsum = 0;
	long long answer = 0;
	int n;
	cin >> n;

	for (int i = 1; i <= n - 2; i++)
	{
		cumsum += i;
		answer += cumsum;
	}
		
	cout << answer << "\n" << 3;
}