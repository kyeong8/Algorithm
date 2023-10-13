#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
int arr[31][11] = { 0 };

struct Pos {
	int row;
	int col;
};

int minNum = 4;
vector<Pos> v;

bool check()
{
	for (int j = 1; j <= N; j++)
	{
		int row = 1;
		int col = j;

		while (true)
		{
			// 가로선은 왼쪽에서 오른쪽으로 향함. 즉, 왼쪽 기준
			if (arr[row][col - 1] == 1)
				--col;
			else if (arr[row][col] == 1)
				++col;

			++row;

			if (row > H)
				break;
		}

		if (j != col)
			return false;
	}

	return true;
}

void combination(int depth, int type, int idx)
{
	if (type == depth)
	{
		if (check())
			minNum = min(minNum, depth);
		return;
	}

	for (int i = idx; i < v.size(); i++)
	{
		Pos temp = v[i];

		if (arr[temp.row][temp.col] != 1 && arr[temp.row][temp.col - 1] != 1 && arr[temp.row][temp.col + 1] != 1)
		{
			arr[temp.row][temp.col] = 1;

			combination(depth + 1, type, i);

			arr[temp.row][temp.col] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int a, b;

	// H -> 가로 -> row, N -> 세로 -> col
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			// 가로선을 놓을 수 있는 후보
			// 왼쪽 column, 현재 column, 오른쪽 column 모두 가로선이 없어야 놓을 수 있음
			if (arr[i][j] != 1 && arr[i][j + 1] != 1 && arr[i][j - 1] != 1)
				v.push_back(Pos{ i, j });
		}
	}

	for (int i = 0; i <= 3; i++)
	{
		combination(0, i, 0);
		if (minNum != 4)
			break;
	}

	if (minNum == 4)
		minNum = -1;
	cout << minNum << "\n";
}