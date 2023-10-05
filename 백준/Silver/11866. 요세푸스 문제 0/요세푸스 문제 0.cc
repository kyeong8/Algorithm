#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	int order = 0;

	vector<int> v;

	for (int i = 1; i <= N; i++)
		v.push_back(i);


	cout << "<";

	for (int i = 0; i < N; i++)
	{
		order += K;
		--order;
		order %= v.size();

		vector<int>::iterator iter = next(v.begin(), order);
		cout << *iter;
		v.erase(iter);

		if (i != N - 1)
			cout << ", ";
	}

	cout << ">";
}