#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
	int length;
	int cnt;
	string word;
};


bool cmp(Info x, Info y)
{
	if (x.cnt == y.cnt)
	{
		if (x.length == y.length)
		{
			return x.word < y.word;
		}

		return x.length > y.length;
	}

	return x.cnt > y.cnt;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	map<string, int> index;
	vector<Info> v;
	string str;
	int count = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str.size() >= M)
		{
			if (index.find(str) != index.end())
				++v[index[str]].cnt;
			else
			{
				index[str] = count++;
				v.push_back(Info{ int(str.size()), 1, str });
			}

		}	
	}

	sort(v.begin(), v.end(), cmp);
	for (auto i : v)
		cout << i.word << "\n";
}
