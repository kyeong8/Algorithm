// findGroup
// gravity
// rotate

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


struct Pos {
	int row;
	int col;
};

struct Group {
	int size;
	int block;
	int row;
	int col;
	vector<Pos> history;
};

// 상 하 좌 우
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int point;
int N, M;
int map[21][21];
bool checkBlock[21][21] = { false };
Group maxGroup;

bool cmp(Pos a, Pos b)
{
	return a.row < b.row;
	if (a.row == b.row)
		return a.col < b.col;
}

bool outofrange(int row, int col)
{
	if (1 <= row && row <= N && 1 <= col && col <= N)
		return false;
	return true;
}

void findGroup(int row, int col)
{
	bool visited[21][21] = { false };
	vector<Pos> mem;

	queue<Pos> q;
	int color = map[row][col];
	
	int cnt = 0;
	mem.push_back(Pos{ row, col });
	visited[row][col] = true; 
	checkBlock[row][col] = true;
	q.push(Pos{ row, col });

	while (!q.empty())
	{
		int currRow = q.front().row;
		int currCol = q.front().col;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nrow = currRow + dr[i];
			int ncol = currCol + dc[i];

			// 외부가 아니고 다른 블록 그룹이 아니며 같은 색깔이거나 무지개색
			if (!outofrange(nrow, ncol) && !visited[nrow][ncol] && (map[nrow][ncol] == color || map[nrow][ncol] == 0))
			{
				mem.push_back(Pos{ nrow, ncol });
				visited[nrow][ncol] = true;
				if (map[nrow][ncol] == color)
					checkBlock[nrow][ncol] = true;
				else
					++cnt;
				q.push(Pos{ nrow, ncol });
			}
		}
	}
	
	if (mem.size() < 2)
		return;

	sort(mem.begin(), mem.end(), cmp);
	int size = (int)mem.size();
	int srow, scol;
	for (auto temp : mem)
	{
		if (map[temp.row][temp.col] > 0)
		{
			srow = temp.row;
			scol = temp.col;
			break;
		}
	}


	if (maxGroup.size < size)
		maxGroup = Group{ size, cnt, srow, scol, mem };
	else if (maxGroup.size == size)
	{
		if (maxGroup.block < cnt)
			maxGroup = Group{ size, cnt, srow, scol, mem };
		else if (maxGroup.block == cnt)
		{
			if (maxGroup.row < srow)
				maxGroup = Group{ size, cnt, srow, scol, mem };
			else if (maxGroup.row == srow)
			{
				if (maxGroup.col < mem[0].col)
					maxGroup = Group{ size, cnt, srow, scol, mem };
			}
		}
	}
}

void gravity()
{
	for (int j = 1; j <= N; j++)
	{
		int mem = 0;

		for (int i = N; i > 0; i--)
		{
			if (map[i][j] == -2 && mem == 0)
				mem = i;
			if (map[i][j] == -1)
				mem = 0;
			if (map[i][j] >= 0 && mem != 0)
			{
				map[mem][j] = map[i][j];
				map[i][j] = -2;
				i = mem + 1;
				mem = 0;
			}
		}
	}
}

void rotate()
{
	int mem[21][21];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			mem[N - (j - 1)][i] = map[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			map[i][j] = mem[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	point = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	while (true)
	{
		vector<Pos> v;
		maxGroup = Group{ 0, 0, 0, 0, v };

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] > 0 && !checkBlock[i][j])
					findGroup(i, j);
			}
		}

		//cout << "size: " << maxGroup.size << " block: " << maxGroup.block << " row: " << maxGroup.row << " col: " << maxGroup.col << "\n";
		
		if (maxGroup.history.size() < 2)
			break;

		for (auto temp : maxGroup.history)
		{
			//cout << "row: " << temp.row << " col: " << temp.col << "\n";
			map[temp.row][temp.col] = -2;
		}

		//cout << "maxGroup.history.size(): " << maxGroup.history.size() << "\n";
		point += maxGroup.history.size() * maxGroup.history.size();

		gravity();
		//cout << "firstGravity\n";
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		if (map[i][j] >= 0)
		//			cout << " " << map[i][j] << " ";
		//		else
		//			cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		rotate();
		//cout << "rotate\n";
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		if (map[i][j] >= 0)
		//			cout << " " << map[i][j] << " ";
		//		else
		//			cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		gravity();
		//cout << "secondGravity\n";
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		if (map[i][j] >= 0)
		//			cout << " " << map[i][j] << " ";
		//		else
		//			cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
		//cout << "1\n";
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		if (map[i][j] >= 0)
		//			cout << " " << map[i][j] << " ";
		//		else
		//			cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
		///break;
		memset(checkBlock, false, sizeof(checkBlock));
	}
	cout << point << "\n";
}