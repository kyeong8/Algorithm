#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	int N, M;
	cin >> N;
	
	int* flag = new int[N];
	deque<int> qs;

	for (int i = 0; i < N; i++)
		cin >> flag[i];

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (!flag[i])
			qs.push_back(num);
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num;

		qs.push_front(num);
		num = qs.back();
		qs.pop_back();

		cout << num << " ";
	}
}