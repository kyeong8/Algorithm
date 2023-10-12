#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>

using namespace std;

struct Pos {
	int row;
	int col;
};

int R, C, T;
int arr[50][50];
Pos machine[2];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

// clockwise 우 하 좌 상
int cdr[] = { 0, 1, 0, -1 };
int cdc[] = { 1, 0, -1, 0 };

// counter clockwise 우 상 좌 하
int ccdr[] = { 0, -1, 0, 1 };
int ccdc[] = { 1, 0, -1, 0 };

bool outofrange(int row, int col)
{
	if (0 <= row && row < R && 0 <= col && col < C)
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> R >> C >> T;
	int temp;
	int mCnt = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> temp;
			if (temp == -1)
			{
				machine[mCnt] = Pos{ i, j };
				++mCnt;
			}
			arr[i][j] = temp;
		}
	}

	for (int round = 1; round <= T; round++)
	{
		int mem[50][50] = { 0 };

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (arr[i][j] > 0)
				{
					int value = arr[i][j] / 5;
					int cnt = 0;
					for (int k = 0; k < 4; k++)
					{
						int nrow = i + dr[k];
						int ncol = j + dc[k];

						if (!outofrange(nrow, ncol) && arr[nrow][ncol] != -1)
						{
							++cnt;
							mem[nrow][ncol] += value;
						}
					}

					mem[i][j] -= cnt * value;
				}
			}
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				arr[i][j] += mem[i][j];
			}
		}

		// 위에
		deque<int> move;
		move.push_back(0);
		Pos start = { machine[0].row, machine[0].col};
		int direct = 0;
		while (true)
		{
			int nrow = start.row + ccdr[direct];
			int ncol = start.col + ccdc[direct];

			if (outofrange(nrow, ncol))
			{
				++direct;
				nrow = start.row + ccdr[direct];
				ncol = start.col + ccdc[direct];
			}

			if (nrow == machine[0].row - 1 && ncol == machine[0].col)
				break;

			move.push_back(arr[nrow][ncol]);
			start.row = nrow;
			start.col = ncol;
		}

		start = { machine[0].row, machine[0].col};
		direct = 0;
		while (true)
		{
			int nrow = start.row + ccdr[direct];
			int ncol = start.col + ccdc[direct];

			if (outofrange(nrow, ncol))
			{
				++direct;
				nrow = start.row + ccdr[direct];
				ncol = start.col + ccdc[direct];
			}

			if (arr[nrow][ncol] == -1)
				break;
			
			arr[nrow][ncol] = move.front();
			move.pop_front();

			start.row = nrow;
			start.col = ncol;
		}

		// 아래
		move.push_back(0);
		start = { machine[1].row, machine[1].col };
		direct = 0;
		while (true)
		{
			int nrow = start.row + cdr[direct];
			int ncol = start.col + cdc[direct];

			if (outofrange(nrow, ncol))
			{
				++direct;
				nrow = start.row + cdr[direct];
				ncol = start.col + cdc[direct];
			}

			if (nrow == machine[0].row + 1 && ncol == machine[0].col)
				break;

			move.push_back(arr[nrow][ncol]);
			start.row = nrow;
			start.col = ncol;
		}

		start = { machine[1].row, machine[1].col };
		direct = 0;
		while (true)
		{
			int nrow = start.row + cdr[direct];
			int ncol = start.col + cdc[direct];

			if (outofrange(nrow, ncol))
			{
				++direct;
				nrow = start.row + cdr[direct];
				ncol = start.col + cdc[direct];
			}

			if (arr[nrow][ncol] == -1)
				break;

			arr[nrow][ncol] = move.front();
			move.pop_front();

			start.row = nrow;
			start.col = ncol;
		}
	}
	
	int answer = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			answer += arr[i][j];
		}
	}

	cout << answer + 2 << "\n";
}
