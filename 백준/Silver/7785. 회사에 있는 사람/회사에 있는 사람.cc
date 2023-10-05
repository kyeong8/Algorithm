#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string name;
	string op;
	int n;
	set<string> s;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> name >> op;
		
		if (op == "enter")
			s.insert(name);
		else
			s.erase(name);
	}

	set<string>::iterator iter = s.end();
	--iter;
	for (; iter != s.begin(); --iter)
		cout << *iter << "\n";
	cout << *iter << "\n";
}