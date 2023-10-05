#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	vector<vector<char>> v;
	string answer;

	for (int i = 0; i < 5; i++)
	{
		vector<char> temp;
		v.push_back(temp);

		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++)
			v[i].push_back(str[j]);
	}

	int k = 0;
	while (true)
	{
		string str = "";
		int cnt = 0;
		for (int i = 0; i < 5; i++)
		{
			if (k < v[i].size())
				str.push_back(v[i][k]);
			else
				cnt++;
		}
		if (cnt == 5)
			break;
		
		answer.append(str);
		k++;
	}

	cout << answer;

	return 0;
}