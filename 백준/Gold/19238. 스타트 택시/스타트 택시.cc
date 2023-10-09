// 우선순위 계산과 최단거리 이동 및 연료 계산

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

struct Pos {
	int row;
	int col;
};

struct Need {
	int row;
	int col;
	int distance;
};

Pos taxi;
int N, M, fuel;
int start[20][20];
Pos des[400];
bool wall[20][20];

// 상 하 좌 우
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool outofrange(int row, int col)
{
	if (0 <= row && row < N && 0 <= col && col < N)
		return false;
	return true;
}

struct cmp {
	bool operator() (Need a, Need b)
	{
		if (a.distance == b.distance)
		{
			if (a.row == b.row)
				return a.col > b.col;
			return a.row > b.row;
		}
		return a.distance > b.distance;
	}
};

void Take(int round)
{
	priority_queue<Need, vector<Need>, cmp> pq;

	// 시작위치에 손님이 있을 때 고려해야함
	if (start[taxi.row][taxi.col] > 0)
		pq.push(Need{ taxi.row, taxi.col, 0 });

	bool visited[20][20] = { false };
	queue<pair<Pos, int>> q;
	visited[taxi.row][taxi.col] = true;
	q.push(make_pair(taxi, 0));

	while (!q.empty())
	{
		int row = q.front().first.row;
		int col = q.front().first.col;
		int dis = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nrow = row + dr[i];
			int ncol = col + dc[i];

			if (!outofrange(nrow, ncol) && !visited[nrow][ncol] && !wall[nrow][ncol])
			{
				if (start[nrow][ncol] > 0)
					pq.push(Need{nrow, ncol, dis + 1});

				visited[nrow][ncol] = true;
				q.push(make_pair(Pos{ nrow, ncol }, dis + 1));

				if (pq.size() == M - (round - 1))
					break;
			}
		}
	}

	if (pq.empty())
	{
		fuel = -1;
		return;
	}

	int drow = pq.top().row;
	int dcol = pq.top().col;
	int minus = pq.top().distance;
	pq.pop();

	taxi = { drow, dcol };
	fuel -= minus;
}

void putDown(int num)
{
	bool visited[20][20] = { false };
	queue<pair<Pos, int>> q;
	visited[taxi.row][taxi.col] = true;
	q.push(make_pair(taxi, 0));

	while (!q.empty())
	{
		int row = q.front().first.row;
		int col = q.front().first.col;
		int dis = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nrow = row + dr[i];
			int ncol = col + dc[i];

			if (!outofrange(nrow, ncol) && !visited[nrow][ncol] && !wall[nrow][ncol])
			{
				if ((des[num - 1].row == nrow && des[num - 1].col == ncol) || dis >= fuel)
				{
					// fuel: 9, dis: 9
					if (dis < fuel)
						fuel += ((dis + 1) * 2);
					
					taxi = { nrow, ncol };
					fuel -= (dis + 1);
					return;
				}

				visited[nrow][ncol] = true;
				q.push(make_pair(Pos{ nrow, ncol }, dis + 1));
			}
		}
	}

	fuel = -1;
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> fuel;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> wall[i][j];
		}
	}

	int a, b, c, d;
	cin >> a >> b;
	taxi = { a - 1, b - 1 };
	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b >> c >> d;
		start[a - 1][b - 1] = i;
		des[i - 1] = { c - 1, d - 1 };
	}

	for (int round = 1; round <= M; round++)
	{
		Take(round);
		if (fuel < 0)
			break;

		int num = start[taxi.row][taxi.col];
		start[taxi.row][taxi.col] = 0;

		putDown(num);
		if (fuel < 0)
			break;
	}
	cout << fuel << "\n";
}