// 2023-09-21 
// bj23290_마법사 상어와 복제    
// 5시간 30분 (화가 매우 납니다~ 변수 이름 잘못 기입하기도 하고 이동 불가능 잘못 계산하기도 하고)
// 백트래킹 및 조건 따라가기
// 구현, 시뮬레이션
// vector, 우선순위 큐

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Pos {
	int row;
	int col;
};


int R, C, K;
bool wall[21][21][2] = { false };
int map[21][21] = { 0 };

int r[4] = { 0, 0, -1, 1 };
int c[4] = { 1, -1, 0, 0 };

bool check(int row, int col)
{
	if (1 <= row && row <= R && 1 <= col && col <= C)
		return true;
	return false;
}

Pos normalAdd(Pos pos, int d)
{
	int nrow = pos.row + r[d];
	int ncol = pos.col + c[d];

	if (check(nrow, ncol))
	{
		if (d == 0)
		{
			if (!wall[pos.row][pos.col][1])
				return Pos{nrow, ncol};
		}

		if (d == 1)
		{
			if (!wall[pos.row][ncol][1])
				return Pos{ nrow, ncol };
		}

		if (d == 2)
		{
			if (!wall[nrow][ncol][0])
				return Pos{ nrow, ncol };
		}

		if (d == 3)
		{
			if (!wall[pos.row][pos.col][0])
				return Pos{ nrow, ncol };
		}
	}

	return Pos{ -1, -1 };
}

Pos specialAdd(Pos pos, int d, bool leftORtop)
{
	int nrow = pos.row + r[d];
	int ncol = pos.col + c[d];

	if (leftORtop)
	{
		if (d < 2)
		{
			if (check(nrow - 1, ncol))
			{
				if (d == 0)
				{
					if (!wall[nrow - 1][pos.col][0] && !wall[nrow - 1][pos.col][1])
						return Pos{ nrow - 1, ncol };
				}

				if (d == 1)
				{
					if (!wall[nrow - 1][pos.col][0] && !wall[nrow - 1][ncol][1])
						return Pos{ nrow - 1, ncol };
				}
			}
		}
		else
		{
			if (check(nrow, ncol - 1))
			{
				if (d == 2)
				{
					if (!wall[pos.row][ncol - 1][1] && !wall[nrow][ncol - 1][0])
						return Pos{ nrow, ncol - 1 };
				}

				if (d == 3)
				{
					if (!wall[pos.row][ncol - 1][1] && !wall[pos.row][ncol - 1][0])
						return Pos{ nrow, ncol - 1 };
				}
			}
		}
	}
	else
	{
		if (d < 2)
		{
			if (check(nrow + 1, ncol))
			{
				if (d == 0)
				{
					if (!wall[pos.row][pos.col][0] && !wall[nrow + 1][pos.col][1])
						return Pos{ nrow + 1, ncol };
				}

				if (d == 1)
				{
					if (!wall[pos.row][pos.col][0] && !wall[nrow + 1][ncol][1])
						return Pos{ nrow + 1, ncol };
				}
			}
		}
		else
		{
			if (check(nrow, ncol + 1))
			{
				if (d == 2)
				{
					if (!wall[pos.row][pos.col][1] && !wall[nrow][ncol + 1][0])
						return Pos{ nrow, ncol + 1 };
				}

				if (d == 3)
				{
					if (!wall[pos.row][pos.col][1] && !wall[pos.row][ncol + 1][0])
						return Pos{ nrow, ncol + 1 };
				}
			}
		}
	}
	
	return Pos{ -1, -1 };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	vector<pair<Pos, int>> warm;
	vector<Pos> search;

	int minNum;
	int answer = 0;
	int temp;
	cin >> R >> C >> K;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> temp;
			if (temp == 5)
				search.push_back(Pos{ i, j });
			else if (temp != 0)
				warm.push_back(make_pair(Pos{ i, j }, temp));
			map[i][j] = 0;
		}
	}

	int W;
	cin >> W;

	int x, y, t;
	for (int i = 0; i < W; i++)
	{
		cin >> x >> y >> t;
		if (t == 1)
			wall[x][y][t] = true;
		else
			wall[x - 1][y][t] = true;
	}

	while (true)
	{
		minNum = 1001;
		for (auto w : warm)
		{
			int d = w.second - 1;
			int row = w.first.row + r[d];
			int col = w.first.col + c[d];

			Pos shift;
			vector<pair<Pos, int>> v;
			vector<pair<Pos, int>> mem;
			v.push_back(make_pair(Pos{ row, col }, 5));

			bool visited[21][21] = { false };

			for (int i = 0; i < 5; i++)
			{
				while (!v.empty())
				{
					Pos pos = v.back().first;
					int temper = v.back().second;
					v.pop_back();

					//cout << "info.temper: " << info.temper << "\n";
					map[pos.row][pos.col] += temper;

					if (temper <= 1)
						continue;

					shift = normalAdd(pos, d);
					if (shift.row != -1 && shift.col != -1 && !visited[shift.row][shift.col])
					{
						visited[shift.row][shift.col] = true;
						mem.push_back(make_pair(Pos{ shift.row, shift.col }, temper - 1));
					}

					shift = specialAdd(pos, d, false);
					if (shift.row != -1 && shift.col != -1 && !visited[shift.row][shift.col])
					{
						visited[shift.row][shift.col] = true;
						mem.push_back(make_pair(Pos{ shift.row, shift.col }, temper - 1));
					}

					shift = specialAdd(pos, d, true);
					if (shift.row != -1 && shift.col != -1 && !visited[shift.row][shift.col])
					{
						visited[shift.row][shift.col] = true;
						mem.push_back(make_pair(Pos{ shift.row, shift.col }, temper - 1));
					}
				}
				v.clear();
				for (auto m : mem)
				{
					v.push_back(m);
					//cout << "mrow: " << m.first.row << " mcol: " << m.first.col << "\n";
				}
				//cout << "\n";
				mem.clear();
			}
		}

		//cout << "prev\n";
		//for (int i = 1; i <= R; i++)
		//{
		//	for (int j = 1; j <= C; j++)
		//	{
		//		cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		int reg[21][21] = { 0 };

		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				int row = i + r[0];
				int col = j + c[0];

				if (check(row, col) && !wall[i][j][1])
				{
					int diff = abs(map[row][col] - map[i][j]);
					diff /= 4;

					if (map[row][col] > map[i][j])
					{
						reg[row][col] -= diff;
						reg[i][j] += diff;
					}
					else
					{
						reg[row][col] += diff;
						reg[i][j] -= diff;
					}
				
				}

				row = i + r[3];
				col = j + c[3];

				if (check(row, col) && !wall[i][j][0])
				{
					int diff = abs(map[row][col] - map[i][j]);
					diff /= 4;


					if (map[row][col] > map[i][j])
					{
						reg[row][col] -= diff;
						reg[i][j] += diff;
					}
					else
					{
						reg[row][col] += diff;
						reg[i][j] -= diff;
					}
				}

			}
		}

		//for (int i = 1; i <= R; i++)
		//{
		//	for (int j = 1; j <= C; j++)
		//	{
		//		cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				map[i][j] += reg[i][j];
			}
		}

		for (int i = 1; i <= C; i++) {
			if (map[1][i] > 0) map[1][i]--;
			if (map[R][i] > 0) map[R][i]--;
		}
		for (int i = 2; i < R; i++) {
			if (map[i][1] > 0) map[i][1]--;
			if (map[i][C] > 0) map[i][C]--;
		}

		++answer;

		//for (int i = 1; i <= R; i++)
		//{
		//	for (int j = 1; j <= C; j++)
		//	{
		//		cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		if (answer > 100)
		{
			cout << answer << "\n";
			break;
		}
			
		for (auto s : search)
			minNum = min(minNum, map[s.row][s.col]);

		if (minNum >= K)
		{
			cout << answer << "\n";
			break;
		}
	}
}
