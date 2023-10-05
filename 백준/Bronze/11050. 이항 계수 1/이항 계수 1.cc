#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	int up = 1;
	int down = 1;
	cin >> N >> K;

	for (int i = 1; i <= min(N-K, K); i++)
	{
		up = up * (N - i + 1);
		down = down * i;
	}

	cout << up / down << "\n";
}
