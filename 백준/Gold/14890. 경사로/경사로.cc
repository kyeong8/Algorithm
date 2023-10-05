#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int arr[100][100];
	int N, L;
	int floor;
	int diff;
	int combo;
	int upordown;
	int cnt = 0;
	bool flag;

	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		flag = false;
		floor = arr[i][0];
		upordown = 0;
		combo = 1;
		int stair = 0;
		for (int j = 1; j < N; j++)
		{
			diff = arr[i][j] - floor;

			if (diff == 1)
			{
				if (combo < L || stair > 0)
				{
					flag = true;
					break;
				}
				
				stair = 0;
				floor = arr[i][j];
				upordown = diff;
				combo = 1;
			}
			else if (diff == -1)
			{
				if (upordown < 0 && combo < L)
				{
					flag = true;
					break;
				}

				stair = 2 * L - 1;
				floor = arr[i][j];
				upordown = diff;
				combo = 1;
			}
			else if (diff == 0)
			{
				if (stair > 0)
					--stair;
				++combo;
			}
			else
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			if (upordown < 0 && combo < L)
				continue;
			//cout << "i: " << i << "\n";
			++cnt;
		}
	}

	for (int j = 0; j < N; j++)
	{
		flag = false;
		floor = arr[0][j];
		upordown = 0;
		combo = 1;
		int stair = 0;
		for (int i = 1; i < N; i++)
		{
			diff = arr[i][j] - floor;

			if (diff == 1)
			{
				if (combo < L || stair > 0)
				{
					flag = true;
					break;
				}

				stair = 0;
				floor = arr[i][j];
				upordown = diff;
				combo = 1;
			}
			else if (diff == -1)
			{
				if (upordown < 0 && combo < L)
				{
					flag = true;
					break;
				}

				stair = 2 * L - 1;
				floor = arr[i][j];
				upordown = diff;
				combo = 1;
			}
			else if (diff == 0)
			{
				if (stair > 0)
					--stair;
				++combo;
			}
			else
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			if (upordown < 0 && combo < L)
				continue;
			//cout << "j: " << j << "\n";
			++cnt;
		}
	}

	cout << cnt << "\n";
}