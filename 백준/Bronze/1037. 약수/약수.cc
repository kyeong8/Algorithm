#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long minNum = 1000001;
	long long maxNum = 1;
	int N;
	long long num;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		maxNum = max(maxNum, num);
		minNum = min(minNum, num);
	}

	cout << maxNum * minNum << "\n";
}
