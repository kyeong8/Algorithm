#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(int argc, const char* argv[])
{
	//freopen("input.txt", "r", stdin);

	int N;
	cin >> N;

	for (int i = 1; i < 2 * N; i++)
	{
		if (N - i >= 0)
		{
			for (int j = 0; j < N - i; j++)
				cout << " ";
			for (int j = 0; j < 2 * (i - 1) + 1; j++)
				cout << "*";
		}
		else
		{
			for (int j = 0; j < i - N; j++)
				cout << " ";
			for (int j = 0; j < 2 * (- i + 2 * N) - 1; j++)
				cout << "*";
		}
		cout << endl;
	}
}