#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct Pos {
	int row;
	int col;
};

int dr[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int N, M;
int A[51][51];
bool check[51][51] = { false };

Pos connect(int row, int col)
{
	Pos ret = { row, col };
	if (1 <= row && row <= N && 1 <= col && col <= N)
		return ret;
	else
	{
		if (row < 1)
			ret.row = N - (-1 * row) % 5;
		if (col < 1)
			ret.col = N - (-1 * col) % 5;
		if (row > N)
			ret.row = 1 + (row - (N + 1)) % N;
		if (col > N)
			ret.col = 1 + (col - (N + 1)) % N;

		return ret;
	}
}

bool outofrange(int row, int col)
{
	if (1 <= row && row <= N && 1 <= col && col <= N)
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
		}
	}

	vector<Pos> cloud;
	cloud.push_back(Pos{ N, 1 });
	cloud.push_back(Pos{ N, 2 });
	cloud.push_back(Pos{ N - 1, 1 });
	cloud.push_back(Pos{ N - 1, 2 });
	vector<Pos> history;

	for (int round = 1; round <= M; round++)
	{
		int d, s;
		cin >> d >> s;

		for (auto c : cloud)
		{
			int nrow, ncol;
			/*nrow = c.row + s * dr[d];
			ncol = c.col + s * dc[d];*/
			if (c.row + s * dr[d] > 0)
				nrow = (c.row + s * dr[d] - 1) % N + 1;
			else
				nrow = N + (c.row + s * dr[d]) % N;
			if (c.col + s * dc[d] > 0) 
				ncol = (c.col + s * dc[d] - 1) % N + 1;
			else
				ncol = N + (c.col + s * dc[d]) % N;

			A[nrow][ncol] += 1;
			history.push_back(Pos{ nrow, ncol });

			//cout << "nrow: " << nrow << " ncol: " << ncol << "\n";

		/*	Pos pos = connect(nrow, ncol);
			cout << "nrow: " << pos.row << " ncol: " << pos.col << "\n";
			A[pos.row][pos.col] += 1;
			history.push_back(pos);*/
			
		}
		//cout << "\n";
		for (auto h : history)
		{
			int cnt = 0;
			int row = h.row;
			int col = h.col;

			for (int i = 1; i <= 4; i++)
			{
				int nrow = row + dr[2 * i];
				int ncol = col + dc[2 * i];

				if (!outofrange(nrow, ncol) && A[nrow][ncol] > 0)
					++cnt;
			}
			check[row][col] = true;
			A[row][col] += cnt;
		}

		cloud.clear();

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (!check[i][j] && A[i][j] >= 2)
				{
					cloud.push_back(Pos{ i, j });
					A[i][j] -= 2;
				}
				else
					check[i][j] = false;
			}
		}

		history.clear();
	}

	int answer = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			answer += A[i][j];
		}
	}

	cout << answer << "\n";
}