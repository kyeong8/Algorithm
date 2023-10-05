#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	deque<int> q;

	for (int i = 1; i <= N; i++)
		q.push_front(i);

	while (q.size() != 1)
	{
		q.pop_back();
		q.push_front(q.back());
		q.pop_back();
	}

	cout << q[0] << "\n";
}