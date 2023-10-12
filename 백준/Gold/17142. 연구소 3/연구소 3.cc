#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
	int row;
	int col;
};

int answer;
int N, M;
int arr[50][50];
int blink;
vector<Pos> virus;
vector<vector<int>> seq;
vector<int> subseq;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool outofrange(int row, int col)
{
	if (0 <= row && row < N && 0 <= col && col < N)
		return false;
	return true;
}

void dfs(int depth, int idx, int virusCnt)
{
	if (depth == M)
	{
		seq.push_back(subseq);
		return;
	}
		
	for (int i = idx; i < virusCnt; i++)
	{
		subseq.push_back(i);

		dfs(depth + 1, i + 1, virusCnt);

		subseq.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	answer = 3000;
	cin >> N >> M;
	int temp;
	blink = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			arr[i][j] = temp;
			if (temp == 0)
				++blink;
			else if (temp == 2)
				virus.push_back(Pos{ i, j });
		}
	}

	int virusCnt = virus.size();
	dfs(0, 0, virusCnt);

	for (auto sub : seq)
	{
		int cnt = 0;
		bool visited[50][50] = { false };
		queue<pair<Pos, int>> q;
		
		for (auto s : sub)
		{
			visited[virus[s].row][virus[s].col] = true;
			q.push(make_pair(Pos{ virus[s].row, virus[s].col }, 0));
		}

		int maxTime = 0;
		while (!q.empty())
		{
			int row = q.front().first.row;
			int col = q.front().first.col;
			int time = q.front().second;
			q.pop();

			if (arr[row][col] != 2 && maxTime < time)
				maxTime = time;

			for (int i = 0; i < 4; i++)
			{
				int nrow = row + dr[i];
				int ncol = col + dc[i];

				if (!visited[nrow][ncol] && !outofrange(nrow, ncol) && arr[nrow][ncol] != 1)
				{
					visited[nrow][ncol] = true;
					q.push(make_pair(Pos{ nrow, ncol }, time + 1));

					if (arr[nrow][ncol] == 0)
						++cnt;
				}
			}
		}

		if (cnt == blink && answer > maxTime)
		{
			answer = maxTime;
		}
	}

	if (answer == 3000)
		cout << "-1\n";
	else
		cout << answer << "\n";
}
