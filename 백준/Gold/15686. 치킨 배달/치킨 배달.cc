#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[50][50];

int minNum = 987654321;
vector<pair<int, int>> h;
vector<pair<int, int>> c;
vector<pair<int, int>> comb;


int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int bfs()
{
	bool visited[50][50] = { false };
	int length[50][50] = { 0 };

	for (auto i : comb)
	{
		memset(visited, false, sizeof(visited));
		queue<pair<pair<int, int>, int>> q;
		visited[i.first][i.second] = true;
		q.push(make_pair(i, 0));

		while (!q.empty())
		{
			int row = q.front().first.first;
			int col = q.front().first.second;
			int dis = q.front().second;
			q.pop();

			if (map[row][col] == 1)
			{
				if (length[row][col] == 0)
					length[row][col] = dis;
				else
					length[row][col] = min(length[row][col], dis);
			}

			for (int j = 0; j < 4; j++)
			{
				int nrow = row + dy[j];
				int ncol = col + dx[j];

				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < N)
				{
					if (!visited[nrow][ncol])
					{
						visited[nrow][ncol] = true;
						q.push(make_pair(make_pair(nrow, ncol), dis + 1));
					}
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cnt += length[i][j];
		}
	}

	return cnt;
}

void dfs(int index, int depth)
{
	if (depth == M)
	{
		minNum = min(minNum, bfs());
		return;
	}

	for (int i = index; i < c.size(); i++)
	{
		int row = c[i].first;
		int col = c[i].second;

		comb.push_back(c[i]);

		dfs(i + 1, depth + 1);

		comb.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M;

	int temp;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			if (temp == 2)
			{
				c.push_back(make_pair(i, j));
				map[i][j] = 0;
			}
				
			else if (temp == 1)
			{
				h.push_back(make_pair(i, j));
				map[i][j] = temp;
			}	
		}
	}

	dfs(0, 0);

	cout << minNum << "\n";
}