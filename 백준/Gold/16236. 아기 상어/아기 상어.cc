#include <iostream>
#include <queue>

using namespace std;

struct Pos {
	int row;
	int col;

	Pos(int Row, int Col) : row(Row), col(Col) {};
};

int arr[21][21] = { 0, };
Pos shark(0, 0);
int eatCount;
int sharkSize;
int N;

int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };

bool check(int row, int col)
{
	if (0 <= row && row < N && 0 <= col && col < N)
		return true;
	return false;
}

int findFish(int srow, int scol, int depth)
{
	int first = 9999;
	queue<Pos> mem;
	queue<pair<Pos, int>> q;
	bool visited[20][20] = { false };
	visited[srow][scol] = true;
	q.push(make_pair(Pos(srow, scol), depth));

	while (!q.empty())
	{
		int crow = q.front().first.row;
		int ccol = q.front().first.col;
		int ndepth = q.front().second + 1;

		//cout << "crow: " << crow << " ccol: " << ccol << "\n";
		q.pop();

		if (ndepth > first)
			break;
		for (int i = 0; i < 4; i++)
		{
			int nrow = crow + dr[i];
			int ncol = ccol + dc[i];

			if (!visited[nrow][ncol] && check(nrow, ncol) && (arr[nrow][ncol] <= sharkSize))
			{
				if (arr[nrow][ncol] > 0 && arr[nrow][ncol] < sharkSize)
				{
					first = ndepth;
					mem.push(Pos(nrow, ncol));
				}

				visited[nrow][ncol] = true;
				q.push(make_pair(Pos(nrow, ncol), ndepth));
			}
		}
	}

	if (mem.empty())
		return -1;

	int row = N + 1, col = N + 1;
	while (!mem.empty())
	{
		Pos temp = mem.front();
		mem.pop();
		if (temp.row < row)
		{
			row = temp.row;
			col = temp.col;
		}
		else if (temp.row == row)
		{
			if (temp.col < col)
				col = temp.col;
		}
	}

	shark.row = row, shark.col = col;
	arr[row][col] = 0;

	return first;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	eatCount = 0;
	sharkSize = 2;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 9)
			{
				shark = Pos(i, j);
				arr[i][j] = 0;
			}
		}
	}

	int answer = 0;
	while (true)
	{
		int temp = findFish(shark.row, shark.col, 0);
		//cout << "temp " << temp << "\n";
		if (temp < 0)
			break;
		eatCount++;
		if (sharkSize == eatCount)
		{
			sharkSize++;
			eatCount = 0;
		}
		answer += temp;


		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}*/
	}

	cout << answer << "\n";
}