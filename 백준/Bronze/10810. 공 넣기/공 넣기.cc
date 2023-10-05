#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(int argc, const char* argv[])
{
	//freopen("input.txt", "r", stdin);

	int N;
	int M;
	cin >> N >> M;
	int a, b, c;

	int* arr = new int;
	arr = new int[N];


	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		for (int j = a; j <= b; j++)
		{
			arr[j-1] = c;
		}
	}

	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
}