#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int answer = 0;
	string str;
	set<string> uos;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "ENTER")
		{
			answer += uos.size();
			uos.clear();
		}
		else
			uos.insert(str);
	}

	cout << answer + uos.size() << "\n";
}