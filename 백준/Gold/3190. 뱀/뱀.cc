#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int row[4] = { -1, 0, 1, 0 };
int col[4] = { 0, 1, 0, -1 };

struct pos {
	int row;
	int col;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int map[100][100];

	int N, K, L;
	int r, c;
	int X, curr, trans;
	char direct;
	int time = 0;
	pos head, tail;
	cin >> N;
	cin >> K;

	head = pos{ 0, 0 };
	tail = pos{ 0, 0 };

	curr = 2;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] = 0;
		}
	}

	map[0][0] = curr;

	for (int i = 0; i < K; i++)
	{
		cin >> r >> c;
		map[r - 1][c - 1] = -1;
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		cin >> X >> direct;

		while (time != X)
		{
			++time;

			head.row += row[curr - 1];
			head.col += col[curr - 1];
			
			if (head.row < 0 || head.row >= N || head.col < 0 || head.col >= N)
			{
				cout << time << "\n";
				return 0;
			}
			else if (map[head.row][head.col] > 0)
			{
				cout << time << "\n";
				return 0;
			}
			else if (map[head.row][head.col] < 0)
			{
				map[head.row][head.col] = curr;
			}
			else 
			{
				map[head.row][head.col] = curr;

				trans = map[tail.row][tail.col];
				map[tail.row][tail.col] = 0;
				tail.row += row[trans - 1];
				tail.col += col[trans - 1];
			}
		}

		if (direct == 'D')
		{
			if (curr == 4)
				curr = 1;
			else 
				curr += 1;
		}
		else if (direct == 'L') 
		{
			if (curr == 1)
				curr = 4;
			else
				curr -= 1;
		}

		map[head.row][head.col] = curr;
	}

	while (true)
	{
		++time;

		head.row += row[curr - 1];
		head.col += col[curr - 1];

		if (head.row < 0 || head.row >= N || head.col < 0 || head.col >= N)
		{
			cout << time << "\n";
			return 0;
		}
		else if (map[head.row][head.col] > 0)
		{
			cout << time << "\n";
			return 0;
		}
		else if (map[head.row][head.col] < 0)
		{
			map[head.row][head.col] = curr;
		}
		else
		{
			map[head.row][head.col] = curr;

			trans = map[tail.row][tail.col];
			map[tail.row][tail.col] = 0;
			tail.row += row[trans - 1];
			tail.col += col[trans - 1];
		}
	}

	return 0;
}