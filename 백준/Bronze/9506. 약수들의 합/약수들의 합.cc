#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int sum = 1;
	vector <int> v1;
	vector <int> v2;

	while (true)
	{
		cin >> N;

		if (N == -1)
			break;

		for (int i = 2; i * i <= N; i++)
		{
			if (N % i == 0)
			{
				sum += i;
				sum += (N / i);
				v1.push_back(i);
				v2.push_back(N / i);
			}
		}

		if (sum == N)
		{
			cout << N << " = 1 + ";
			for (auto i : v1)
				cout << i << " + ";

			vector<int>::iterator iter = v2.end();
			while (iter != v2.begin())
			{
				--iter;
				cout << *iter;
				if (*iter != v2[0])
					cout << " + ";
			}
			cout << "\n";
		}
		else
			cout << N << " is NOT perfect.\n";

		v1.clear();
		v2.clear();
		sum = 1;
	}
}