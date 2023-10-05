#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int K;
	cin >> K;
	
	int num;
	vector<int> v;
	int sum = 0;

	for (int i = 0; i < K; i++)
	{
		cin >> num;

		if (num == 0)
		{
			sum -= v.back();
			v.pop_back();
		}
		else
		{
			sum += num;
			v.push_back(num);
		}
	}

	cout << sum << "\n";
}