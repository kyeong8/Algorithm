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

	int n;
	cin >> n;

	int* arr = new int[n];
	int* diff = new int[n-1];
	int sum = 0;
	int gcd;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i > 0)
		{
			diff[i - 1] = arr[i] - arr[i - 1];
			sum += diff[i - 1];
		}
	}
	
	gcd = GCD(diff[0], diff[1]);

	for (int i = 0; i < n - 3; i++)
		gcd = GCD(gcd, diff[i + 2]);

	cout << sum / gcd - (n - 1) << "\n";

	delete[] arr;
}