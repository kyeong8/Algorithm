#include <iostream>

using namespace std;

int GCD(int l, int r)
{
	if (r == 0)
		return l;
	return GCD(r, l % r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, d;
	int numer;
	int denomin;
	int gcd;
	cin >> a >> b >> c >> d;

	numer = a * d + b * c;
	denomin = b * d;
	gcd = GCD(denomin, numer);

	cout << numer / gcd << " " << denomin / gcd << "\n";
}