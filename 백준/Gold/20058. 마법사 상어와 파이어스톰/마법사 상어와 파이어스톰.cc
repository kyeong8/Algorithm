// L로 나뉜 부분 격자를 회전
// 인접한 얼음 개수 카운팅

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int N, Q, L;
int graph[64][64];
int mem[64][64];
int maxNum;
bool visited[64][64] = { false };

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void rotate(int row, int col, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			mem[j][length - 1 - i] = graph[i + row][j + col];
		}
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			graph[i + row][j + col] = mem[i][j];
		}
	}
}

bool outofrange(int row, int col)
{
	if (0 <= row && row < N && 0 <= col && col < N)
		return false;
	return true;
}

void findGroup(int row, int col)
{
	int cnt = 1;
	queue<pair<int, int>> q;
	visited[row][col] = true;
	q.push(make_pair(row, col));

	while (!q.empty())
	{
		int curRow = q.front().first;
		int curCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nrow = curRow + dr[i];
			int ncol = curCol + dc[i];

			if (!outofrange(nrow, ncol) && !visited[nrow][ncol] && graph[nrow][ncol] > 0)
			{
				visited[nrow][ncol] = true;
				q.push(make_pair(nrow, ncol));
				++cnt;
			}
		}
	}

	if (maxNum < cnt)
		maxNum = cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> Q;
	N = pow(2, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}

	maxNum = 1;
	vector<pair<int, int>> v;
	for (int round = 0; round < Q; round++)
	{
		memset(visited, false, sizeof(visited));
		cin >> L;
		int length = pow(2, L);
		for (int i = 0; i < N; i += length)
		{
			for (int j = 0; j < N; j += length)
			{
				rotate(i, j, length);
			}
		}
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][j] == 0)
					continue;

				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int row = i + dr[k];
					int col = j + dc[k];
					if (!outofrange(row, col))
					{
						if (graph[row][col] > 0)
							++cnt;
					}
				}

				if (cnt < 3)
					v.push_back(make_pair(i, j));
			}
		}

		for (auto vv : v)
			graph[vv.first][vv.second] -= 1;
		v.clear();
	}

	int total = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			total += graph[i][j];

			if (!visited[i][j] && graph[i][j] > 0)
				findGroup(i, j);
		}
	}

	cout << total << "\n";
	if (maxNum == 1)
		cout << "0\n";
	else
		cout << maxNum << "\n";
}