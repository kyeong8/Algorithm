#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int order = 0;
	int value;
	pair<int, int> num;
	int N;
	cin >> N;
	
	deque<pair<int, int>> arr;

	for (int i = 0; i < N; i++)
	{
		cin >> value;
		arr.push_back(make_pair(i+1, value));
	}

	while (arr.size() > 1)
	{
		num = arr[order];
		deque<pair<int, int>>::iterator iter = next(arr.begin(), order);
		cout << iter->first << " ";
		arr.erase(iter);

		order += num.second;
		if (num.second > 0)
			--order;

		if (order < 0)
			order = (arr.size() - (abs(order) % arr.size())) % arr.size();
		else if (order >= arr.size())
			order = order % arr.size();
	}
	cout << arr[0].first;
}