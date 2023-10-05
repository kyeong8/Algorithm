#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int map[50][50];
int N, L, R;

int r[4] = { -1, 1, 0, 0 };
int c[4] = { 0, 0, -1, 1 };

bool visited[50][50] = { false };

int dfs()
{
	bool flag = false;
	int cnt;
	int cumsum;
	memset(visited, false, sizeof(visited));
	vector<pair<int, int>> stack;
	vector<pair<int, int>> path;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				stack.push_back(make_pair(i, j));
				path.clear();
				cumsum = 0;
				cnt = 0;
			}
			
			while (!stack.empty())
			{
				int row = stack.back().first;
				int col = stack.back().second;

				if (!visited[row][col])
				{
					path.push_back(make_pair(row, col));
					cumsum += map[row][col];
					++cnt;
				}

				stack.pop_back();
				visited[row][col] = true;

				for (int k = 0; k < 4; k++)
				{
					int nrow = row + r[k];
					int ncol = col + c[k];

					if (0 <= nrow && nrow < N && 0 <= ncol && ncol < N)
					{
						if (!visited[nrow][ncol] && L <= abs(map[nrow][ncol] - map[row][col]) && abs(map[nrow][ncol] - map[row][col]) <= R)
						{
							stack.push_back(make_pair(nrow, ncol));
						}
					}
				}
			}

			//cout << "cumsum: " << cumsum << " cnt: " << cnt << "\n";

			int value = cumsum / cnt;

			for (auto p : path)
				map[p.first][p.second] = value;

			if (path.size() > 1)
				flag = true;
		}
	}
	
	if (flag)
		return 1;
	else
		return 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int temp;
	int answer = 0;
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	while (true)
	{
		temp = dfs();
		if (temp == 0)
			break;

		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
		++answer;
	}

	cout << answer << "\n";
}