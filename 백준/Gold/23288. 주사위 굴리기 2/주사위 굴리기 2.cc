#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int n, m, k;
int map[21][21];
int direct;

// 동, 서, 남, 북
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

int dice[4][3] = { {0, 2, 0},
				 {4, 1, 3},
				 {0, 5, 0},
				 {0, 6, 0} };

void rotate()
{
	if (direct == 0) // 동
	{
		int temp = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = temp;
	}
	else if (direct == 1) // 서
	{
		int temp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = temp;
	}
	else if (direct == 2) // 남
	{
		int temp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = temp;
	}
	else if (direct == 3) // 북
	{
		int temp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = temp;
	}
}

bool outofrange(int row, int col)
{
	if (1 <= row && row <= n && 1 <= col && col <= m)
		return false;
	return true;
}

// 동, 서, 남, 북
void revDirect()
{
	if (direct == 0)
		direct = 1;
	else if (direct == 1)
		direct = 0;
	else if (direct == 2)
		direct = 3;
	else if (direct == 3)
		direct = 2;
}

void clockWise()
{
	if (direct == 0)
		direct = 2;
	else if (direct == 1)
		direct = 3;
	else if (direct == 2)
		direct = 1;
	else if (direct == 3)
		direct = 0;
}

void cclockWise()
{
	if (direct == 0)
		direct = 3;
	else if (direct == 1)
		direct = 2;
	else if (direct == 2)
		direct = 0;
	else if (direct == 3)
		direct = 1;
}

int calPoint(int srow, int scol)
{
	int cnt = 1;
	bool visited[21][21] = { false };
	queue<pair<int, int>> q;
	visited[srow][scol] = true;
	q.push(make_pair(srow, scol));

	while (!q.empty())
	{
		int currRow = q.front().first;
		int currCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nrow = currRow + dr[i];
			int ncol = currCol + dc[i];
			if (!outofrange(nrow, ncol) && !visited[nrow][ncol] && map[nrow][ncol] == map[srow][scol])
			{
				++cnt;
				visited[nrow][ncol] = true;
				q.push(make_pair(nrow, ncol));
			}
		}
	}
	return cnt * map[srow][scol];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}

	direct = 0;
	int point = 0;
	int curRow = 1;
	int curCol = 1;
	//cout << "direct: " << direct << "\n\n";
	for (int round = 1; round <= k; round++)
	{
		int nrow = curRow + dr[direct];
		int ncol = curCol + dc[direct];
		//cout << "nrow: " << nrow << " ncol: " << ncol << "\n";
		
		if (outofrange(nrow, ncol))
		{
			revDirect();
			nrow = curRow + dr[direct];
			ncol = curCol + dc[direct];
		}

		curRow = nrow;
		curCol = ncol;

		rotate();
		//cout << "dice[3][1]: " << dice[3][1] << " map[curRow][curCol]: " << map[curRow][curCol] << "\n";

		if (dice[3][1] > map[curRow][curCol])
			clockWise();
		else if (dice[3][1] < map[curRow][curCol])
			cclockWise();

		point += calPoint(curRow, curCol);
		//cout << "curRow: " << curRow << " curCol: " << curCol << "\n";
		//cout << "direct: " << direct << "\n";

		//for (int i = 0; i < 4; i++)
		//{
		//	for (int j = 0; j < 3; j++)
		//	{
		//		cout << dice[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "point: " << point << "\n";
	}

	cout << point << "\n";
}
