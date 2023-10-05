#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> srow;
	set<int> scol;
	int n;
	int a, b;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		srow.insert(a);
		scol.insert(b);
	}

	int answer = 0;

	answer = (*(--srow.end()) - *srow.begin()) * (*(--scol.end()) - *scol.begin());

	cout << answer << "\n";
}