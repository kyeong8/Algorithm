#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct Pos {
	int row;
	int col;
};

int r[4] = { -1, 0, 1, 0 };
int c[4] = { 0, 1, 0, -1 };

vector<Pos> v;
int map[8][8];
int N, M;
int minNum = 64;

void dfs(int index)
{
	if (index == v.size())
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
					++cnt;
			}
		}

		minNum = min(minNum, cnt);
		return;
	}
		
	
	int row = v[index].row;
	int col = v[index].col;
	int mem[8][8];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			mem[i][j] = map[i][j];
		}
	}


	if (map[row][col] == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			int nrow = row + r[i];
			int ncol = col + c[i];

			while (true)
			{
				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M)
				{
					if (map[nrow][ncol] == 6)
						break;
					else if (map[nrow][ncol] == 0)
						map[nrow][ncol] = -1;

					nrow += r[i];
					ncol += c[i];
				}
				else
					break;
			}

			dfs(index + 1);

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					map[i][j] = mem[i][j];
				}
			}
		}
	}
	else if (map[row][col] == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			int nrow = row + r[i];
			int ncol = col + c[i];

			while (true)
			{
				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M)
				{
					if (map[nrow][ncol] == 6)
						break;
					else if (map[nrow][ncol] == 0)
						map[nrow][ncol] = -1;

					nrow += r[i];
					ncol += c[i];
				}
				else
					break;
			}

			nrow = row + r[i + 2];
			ncol = col + c[i + 2];

			while (true)
			{
				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M)
				{
					if (map[nrow][ncol] == 6)
						break;
					else if (map[nrow][ncol] == 0)
						map[nrow][ncol] = -1;

					nrow += r[i + 2];
					ncol += c[i + 2];
				}
				else
					break;
			}

			dfs(index + 1);

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					map[i][j] = mem[i][j];
				}
			}
		}
	}
	else if (map[row][col] == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			int nrow = row + r[i];
			int ncol = col + c[i];

			while (true)
			{
				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M)
				{
					if (map[nrow][ncol] == 6)
						break;
					else if (map[nrow][ncol] == 0)
						map[nrow][ncol] = -1;

					nrow += r[i];
					ncol += c[i];
				}
				else
					break;
			}

			nrow = row + r[(i + 1) % 4];
			ncol = col + c[(i + 1) % 4];

			while (true)
			{
				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M)
				{
					if (map[nrow][ncol] == 6)
						break;
					else if (map[nrow][ncol] == 0)
						map[nrow][ncol] = -1;

					nrow += r[(i + 1) % 4];
					ncol += c[(i + 1) % 4];
				}
				else
					break;
			}

			dfs(index + 1);

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					map[i][j] = mem[i][j];
				}
			}
		}
	}
	else if (map[row][col] == 4)
	{

		for (int i = 0; i < 4; i++)
		{
			int nrow = row + r[i];
			int ncol = col + c[i];

			while (true)
			{
				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M)
				{
					if (map[nrow][ncol] == 6)
						break;
					else if (map[nrow][ncol] == 0)
						map[nrow][ncol] = -1;

					nrow += r[i];
					ncol += c[i];
				}
				else
					break;
			}

			nrow = row + r[(i + 1) % 4];
			ncol = col + c[(i + 1) % 4];

			while (true)
			{
				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M)
				{
					if (map[nrow][ncol] == 6)
						break;
					else if (map[nrow][ncol] == 0)
						map[nrow][ncol] = -1;

					nrow += r[(i + 1) % 4];
					ncol += c[(i + 1) % 4];
				}
				else
					break;
			}

			nrow = row + r[(i + 2) % 4];
			ncol = col + c[(i + 2) % 4];

			while (true)
			{
				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M)
				{
					if (map[nrow][ncol] == 6)
						break;
					else if (map[nrow][ncol] == 0)
						map[nrow][ncol] = -1;

					nrow += r[(i + 2) % 4];
					ncol += c[(i + 2) % 4];
				}
				else
					break;
			}

			dfs(index + 1);

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					map[i][j] = mem[i][j];
				}
			}
		}

	}
	else if (map[row][col] == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			int nrow = row + r[i];
			int ncol = col + c[i];

			while (true)
			{
				if (0 <= nrow && nrow < N && 0 <= ncol && ncol < M)
				{
					if (map[nrow][ncol] == 6)
						break;
					else if (map[nrow][ncol] == 0)
						map[nrow][ncol] = -1;

					nrow += r[i];
					ncol += c[i];
				}
				else
					break;
			}
		}

		dfs(index + 1);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				map[i][j] = mem[i][j];
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

	int temp;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			map[i][j] = temp;

			if (0 < temp && temp < 6)
				v.push_back(Pos{ i, j });
		}
	}
	
	dfs(0);

	cout << minNum << '\n';
}