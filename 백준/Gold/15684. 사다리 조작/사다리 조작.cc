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
			//cout << "row: " << row << " col: " << col << "\n";
			/*if (j == 4 && arr[1][3] && arr[4][2] && arr[6][4])
			{
				cout << "[dibug]1 " << "row: " << row << " col: " << col << "\n";
			}*/
			if (arr[row][col - 1] == 1)
				--col;
			else if (arr[row][col] == 1)
				++col;

			++row;

			if (row > H)
				break;
		}

		if (j != col)
		{
			//cout << "j: " << j << " col: " << col << "\n";
			return false;
		}
			
	}

	return true;
}

void combination(int depth, int type)
{
	//cout << "depth: " << depth << " type: " << type << "\n";
	if (type == depth)
	{
		if (check())
			minNum = min(minNum, depth);
		return;
	}

	for (auto i : v)
	{
		Pos temp = i;

		if (arr[temp.row][temp.col] != 1 && arr[temp.row][temp.col - 1] != 1 && arr[temp.row][temp.col + 1] != 1)
		{
			arr[temp.row][temp.col] = 1;

			combination(depth + 1, type);

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

	//cout << "N: " << N << " M: " << M << " H: " << H << "\n";
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (arr[i][j] != 1 && arr[i][j + 1] != 1 && arr[i][j - 1] != 1)
				v.push_back(Pos{ i, j });

			//if (arr[i][j] != 1 && arr[i][j + 1] != 1 && j < N)
			//	v.push_back(make_pair(Pos{ i, j }, Pos{ i, j + 1}));
		}
	}

	//for (auto i : v)
	//	cout << i.row << " " << i.col << "\n";

	//arr[1][3] = 1;

	//arr[4][2] = 1;

	//arr[6][4] = 1;

	//cout << "check: " << check() << "\n";

	for (int i = 0; i <= 3; i++)
	{
		//cout << "type: " << i << "\n";
		//cout << "size: " << v.size() << "\n";
		combination(0, i);
		if (minNum != 4)
			break;
	}
		
	if (minNum == 4)
		minNum = -1;
	cout << minNum << "\n";
}