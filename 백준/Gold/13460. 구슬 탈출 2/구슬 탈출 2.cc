#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>

using namespace std;

int r[4] = { -1, 1, 0, 0 };
int c[4] = { 0, 0, -1, 1 };

char map[10][10];
int N, M;

struct ball {
	int redRow;
	int redCol;
	int blueRow;
	int blueCol;
	int prev;
};

bool check(int row, int col)
{
	if (0 <= row && row < N && 0 <= col && col < M)
	{
		if (map[row][col] == '.' || map[row][col] == 'O')
			return true;
		else
			return false;
	}
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	deque<pair<ball, int>> dq;

	ball first;
	ball curr;
	ball next;

	int nRow, nCol;
	int cnt;
	char temp;
	bool flag = false;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			temp = cin.get();
			if (temp == '\n')
				temp = cin.get();

			if (temp == 'R')
			{
				first.redRow = i;
				first.redCol = j;
				map[i][j] = '.';
			}
			else if (temp == 'B')
			{
				first.blueRow = i;
				first.blueCol = j;
				map[i][j] = '.';
			}
			else
				map[i][j] = temp;
		}
	}

	first.prev = -1;
	dq.push_back(make_pair(first, 0));

	while (!dq.empty())
	{
		curr = dq.front().first;
		cnt = dq.front().second;
		dq.pop_front();
		//cout << "redRow: " << curr.redRow << "\n";
		//cout << "redCol: " << curr.redCol << "\n";
		//cout << "blueRow: " << curr.blueRow << "\n";
		//cout << "blueCol: " << curr.blueCol << "\n";
		//cout << "Cnt: " << cnt << "\n";
		if (cnt > 9)
			continue;

		for (int i = 0; i < 4; i++)
		{
			if (i == curr.prev)
				continue;
			
			bool blueGoal = false;
			bool redGoal = false;

			next = curr;
			for (int k = 0; k < 2; k++)
			{
				nRow = next.redRow;
				nCol = next.redCol;

				if (check(nRow + r[i], nCol + c[i]))
				{
					while (true)
					{
						if (!blueGoal)
						{
							if (!(nRow + r[i] == next.blueRow && nCol + c[i] == next.blueCol) && check(nRow + r[i], nCol + c[i]))
							{
								nRow += r[i];
								nCol += c[i];

								if (map[nRow][nCol] == 'O')
								{
									redGoal = true;
									break;
								}
							}
							else
								break;
						}
						else
						{
							if (check(nRow + r[i], nCol + c[i]))
							{
								nRow += r[i];
								nCol += c[i];

								if (map[nRow][nCol] == 'O')
								{
									redGoal = true;
									break;
								}
							}
							else
								break;
						}
					}
				}
				
				next.redRow = nRow;
				next.redCol = nCol;

				//cout << "next.redRow: " << next.redRow << "\n";
				//cout << "next.redCol: " << next.redCol << "\n";

				nRow = next.blueRow;
				nCol = next.blueCol;

				if (check(nRow + r[i], nCol + c[i]))
				{
					while (true)
					{
						if (!redGoal)
						{
							if (!(nRow + r[i] == next.redRow && nCol + c[i] == next.redCol) && check(nRow + r[i], nCol + c[i]))
							{
								nRow += r[i];
								nCol += c[i];

								if (map[nRow][nCol] == 'O')
								{
									blueGoal = true;
									break;
								}
							}
							else
								break;
						}
						else
						{
							if (check(nRow + r[i], nCol + c[i]))
							{
								nRow += r[i];
								nCol += c[i];

								if (map[nRow][nCol] == 'O')
								{
									blueGoal = true;
									break;
								}
							}
							else
								break;
						}
					}
				}
				
				next.blueRow = nRow;
				next.blueCol = nCol;

				//cout << "next.blueRow: " << next.blueRow << "\n";
				//cout << "next.blueCol: " << next.blueCol << "\n";


				if (i == 0)
					next.prev = 1;
				else if (i == 1)
					next.prev = 0;
				else if (i == 2)
					next.prev = 3;
				else if (i == 3)
					next.prev = 2;
			}
			if (!blueGoal && redGoal)
			{
				cout << cnt + 1 << "\n";
				return 0;
			}
			else if (!blueGoal && !redGoal && (curr.redRow != next.redRow || curr.redCol != next.redCol || curr.blueRow != next.blueRow || curr.blueCol != next.blueCol))
				dq.push_back(make_pair(next, cnt + 1));
		}
	}
	cout << -1 << "\n";
	return 0;
}