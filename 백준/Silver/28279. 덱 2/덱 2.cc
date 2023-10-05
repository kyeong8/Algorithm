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
	
	int op;
	int num;

	deque<int> q;

	for (int i = 0; i < N; i++)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> num;
			q.push_front(num);
		}
		else if (op == 2)
		{
			cin >> num;
			q.push_back(num);
		}
		else if (op == 3)
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if (op == 4)
		{
			if (!q.empty())
			{
				cout << q.back() << "\n";
				q.pop_back();
			}
			else
				cout << -1 << "\n";
		}
		else if (op == 5)
		{
			cout << q.size() << "\n";
		}
		else if (op == 6)
		{
			if (q.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (op == 7)
		{
			if (!q.empty())
				cout << q.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (op == 8)
		{
			if (!q.empty())
				cout << q.back() << "\n";
			else
				cout << -1 << "\n";
		}
	}
}