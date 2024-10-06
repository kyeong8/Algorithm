#include <iostream>
#include <queue>

using namespace std;

struct Pos {
	int row;
	int col;
};

int N, M, fuel;
int arr[21][21] = { 0 };
Pos driver;
int pas[21][21] = { 0 };
Pos des[401];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool check(int row, int col)
{
	if (1 <= row && row <= N && 1 <= col && col <= N && arr[row][col] == 0)
		return true;
	return false;
}

// 못 찾으면 -1, 가는 길에 연료가 고갈되어도 -1
// 찾으면 번호
int findPas()
{
	bool visited[21][21] = { false };
	int first = 401;
	deque<Pos> mem;
	deque<pair<Pos, int>> q;
	visited[driver.row][driver.col] = true;
	q.push_back(make_pair(Pos{ driver.row, driver.col }, 0));

	while (!q.empty())
	{
		int row = q.front().first.row;
		int col = q.front().first.col;
		int dis = q.front().second;
		q.pop_front();

		if (pas[row][col] > 0)
		{
			if (first >= dis)
				first = dis;
			else
				break;

			mem.push_back(Pos{ row, col });
		}

		for (int i = 0; i < 4; i++)
		{
			int nrow = row + dr[i];
			int ncol = col + dc[i];

			if (!visited[nrow][ncol] && check(nrow, ncol))
			{
				visited[nrow][ncol] = true;
				q.push_back(make_pair(Pos{ nrow, ncol }, dis + 1));
			}
		}
	}

	if (mem.empty() || first > fuel)
		return -1;
	else
	{
		int row = 21;
		int col = 21;

		for (int i = 0; i < mem.size(); i++)
		{
			if (mem[i].row < row)
			{
				row = mem[i].row;
				col = mem[i].col;
			}
			else if (mem[i].row == row)
			{
				if (mem[i].col < col)
					col = mem[i].col;
			}
		}

		int num = pas[row][col];
		pas[row][col] = 0;
		fuel -= first;
		driver.row = row;
		driver.col = col;
		return num;
	}

}

// 가는 길에 연료가 고갈되면 false, 도착 가능하면 true
bool findDes(int num)
{
	// 연료 소모
	// 연료 추가

	bool visited[21][21] = { false };
	deque<pair<Pos, int>> q;
	visited[driver.row][driver.col] = true;
	q.push_back(make_pair(Pos{ driver.row, driver.col }, 0));

	while (!q.empty())
	{
		int row = q.front().first.row;
		int col = q.front().first.col;
		int dis = q.front().second;
		q.pop_front();

		if (dis > fuel)
			return false;

		if (des[num].row == row && des[num].col == col)
		{
			driver.row = row;
			driver.col = col;
			fuel += dis;
			return true;
		}

		for (int i = 0; i < 4; i++)
		{
			int nrow = row + dr[i];
			int ncol = col + dc[i];

			if (!visited[nrow][ncol] && check(nrow, ncol))
			{
				visited[nrow][ncol] = true;
				q.push_back(make_pair(Pos{ nrow, ncol }, dis + 1));
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> fuel;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	//Pos tpas[401];
	//Pos tdes[410];
	cin >> driver.row;
	cin >> driver.col;
	for (int i = 1; i <= M; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		pas[a][b] = i;
		des[i] = Pos{ c,d };
		/*tpas[i].row = a;
		tpas[i].col = b;
		tdes[i].row = c;
		tdes[i].col = d;*/
	}


	/*for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	cout << driver.row << " " << driver.col << "\n";

	for (int i = 1; i <= M; i++)
	{
		cout << tpas[i].row << " " << tpas[i].col << " " << tdes[i].row << " " << tdes[i].col << "\n";
	}*/


	for (int i = 1; i <= M; i++)
	{
		int next;
		next = findPas();

		/*cout << "driver.row: " << driver.row << " driver.col: " << driver.col << "\n";
		cout << "next: " << next << "\n";
		cout << "fuel1: " << fuel << "\n";*/

		if (next < 0)
		{
			fuel = -1;
			break;
		}

		if (!findDes(next))
		{
			fuel = -1;
			break;
		}

		//cout << "fuel2: " << fuel << "\n";
	}

	cout << fuel << "\n";
}