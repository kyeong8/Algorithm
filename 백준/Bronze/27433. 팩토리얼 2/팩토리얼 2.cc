#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long answer = 1;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		answer *= i;

	cout << answer << "\n";
}