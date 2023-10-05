#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	unordered_map<string, int> m;
	m["ChongChong"] = 1;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (m.find(a) != m.end() || m.find(b) != m.end())
		{
			m[a] = 1;
			m[b] = 1;
		}
	}

	cout << m.size() << "\n";
}