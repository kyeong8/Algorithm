#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b;
	cin >> a >> b;
	long long cmpA, cmpB;
	cmpA = a;
	cmpB = b;

	while (cmpA != cmpB)
	{
		if (cmpA < cmpB)
			cmpA += a;
		else
			cmpB += b;
		//cout << "cmpA: " << cmpA << " cmpB: " << cmpB << "\n";
	}
	cout << cmpA << "\n";

}