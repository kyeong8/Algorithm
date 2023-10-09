// 상어 번호마다 다른 우선순위를 어떻게 다룰 것인가
// 상어의 이동과 냄새를 어떻게 다룰 것인가

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
	int row;
	int col;
};

struct Shark {
	int row;
	int col;
	int direct;
	bool del;
};

struct Smell {
	int num;
	int rest;
};

int dr[] = { 0, -1, 1, 0, 0 };
int dc[] = { 0, 0, 0, -1, 1 };

int live;
int N, M, k;
Shark shark[401];
int priority[401][5][4];
int graph[21][21];
Smell smell[21][21];

bool outofrange(int row, int col)
{
	if (1 <= row && row <= N && 1 <= col && col <= N)
		return false;
	return true;
}

void touch()
{
	for (int i = 1; i <= M; i++)
	{
		if (shark[i].del)
			continue;

		smell[shark[i].row][shark[i].col] = { i, k };
	}
}

void move()
{
	vector<int> mem[21][21];
	bool flag[401] = { false };
	for (int i = 1; i <= M; i++)
	{
		if (shark[i].del)
			continue;

		for (int j = 0; j < 4; j++)
		{
			int direct = priority[i][shark[i].direct][j];
			int nrow = shark[i].row + dr[direct];
			int ncol = shark[i].col + dc[direct];

			if (!outofrange(nrow, ncol) && smell[nrow][ncol].rest == 0)
			{
				flag[i] = true;

				shark[i].direct = direct;
				shark[i].row = nrow;
				shark[i].col = ncol;

				mem[shark[i].row][shark[i].col].push_back(i);
				
				break;
			}
		}
	}

	
	for (int i = 1; i <= M; i++)
	{
		if (shark[i].del || flag[i])
			continue;

		for (int j = 0; j < 4; j++)
		{
			int direct = priority[i][shark[i].direct][j];
			int nrow = shark[i].row + dr[direct];
			int ncol = shark[i].col + dc[direct];

			if (!outofrange(nrow, ncol) && smell[nrow][ncol].num == i)
			{
				shark[i].direct = direct;
				shark[i].row = nrow;
				shark[i].col = ncol;

				mem[shark[i].row][shark[i].col].push_back(i);
				break;
			}
		}
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (mem[i][j].size() >= 2)
			{
				sort(mem[i][j].begin(), mem[i][j].end());

				graph[shark[mem[i][j][0]].row][shark[mem[i][j][0]].col] = mem[i][j][0];
				for (int idx = 1; idx < mem[i][j].size(); idx++)
				{
					shark[mem[i][j][idx]].del = true;
					--live;
				}
			}
			else if (mem[i][j].size() == 1)
				graph[i][j] = mem[i][j][0];
			else if (mem[i][j].empty())
				graph[i][j] = 0;
		}
	}
}

void delSmell()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (smell[i][j].rest > 0)
			{
				--smell[i][j].rest;

				if (smell[i][j].rest == 0)
					smell[i][j].num = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> k;

	live = M;
	int temp;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> temp;
			if (temp > 0)
				shark[temp] = { i, j, 0, false };
			graph[i][j] = temp;
			smell[i][j] = { 0, 0 };
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> temp;
		shark[i].direct = temp;
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cin >> temp;
				priority[i][j][k] = temp;
			}
		}
	}

	touch();

	int round = 0;
	while (true)
	{
		if (round > 1000)
			break;

		++round;

		move();
		
		if (live == 1)
			break;

		delSmell();

		touch();

		/*cout << "round: " << round << "\n";
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << smell[i][j].num << " ";
			}
			cout << "\n";
		}
		cout << "\n";

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << smell[i][j].rest << " ";
			}
			cout << "\n";
		}
		cout << "\n";

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << graph[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/
	}

	if (round > 1000)
		cout << "-1\n";
	else
		cout << round << "\n";
}