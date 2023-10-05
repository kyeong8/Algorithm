#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long N;
	long long answer = 2;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		answer = 2 * answer - 1;
		if (i == N - 1)
			cout << answer * answer << "\n";
	}
}