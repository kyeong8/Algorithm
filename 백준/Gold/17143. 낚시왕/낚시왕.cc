#include <iostream>

using namespace std;

struct Pos {
	int row;
	int col;

	bool operator <(const Pos& var) const
	{
		if (row != var.row) return row < var.row;
		return col < var.col;
	}
};

struct Info {
	int speed;
	int direct;
	int size;
};

int dr[] = { 0, 1, -1, 0, 0 };
int dc[] = { 0, 0, 0, 1, -1 };

Info arr[101][101] = { 0, };
int R, C, M;

pair<Pos, Info> move(int row, int col, int speed, int direct, int size)
{
	int curRow = row;
	int curCol = col;
	int curDirect = direct;
	int curSpeed = speed;
	// 상
	if (direct == 1)
	{
		int rest = (row - 1);

		if (rest < curSpeed)
		{
			curSpeed -= rest;
			curRow = 1;
		}
		else
			return make_pair(Pos{ curRow - curSpeed, col }, Info{ speed, direct, size });

		int a = curSpeed / (R - 1);
		int b = curSpeed % (R - 1);

		// 홀수 - 방향 안 바뀜
		if (a % 2 == 1)
			return make_pair(Pos{ R - b, col }, Info{ speed, direct, size });
		// 짝수 - 방향 바뀜
		else
			return make_pair(Pos{ curRow + b, col }, Info{ speed, direct + 1, size });
	}
	// 하
	else if (direct == 2)
	{
		int rest = (R - row);

		if (rest < curSpeed)
		{
			curSpeed -= rest;
			curRow = R;
		}
		else
			return make_pair(Pos{ curRow + curSpeed, col }, Info{ speed, direct, size });

		int a = curSpeed / (R - 1);
		int b = curSpeed % (R - 1);

		// 홀수 - 방향 안 바뀜
		if (a % 2 == 1)
			return make_pair(Pos{ 1 + b, col }, Info{ speed, direct, size });
		// 짝수 - 방향 바뀜
		else
			return make_pair(Pos{ curRow - b, col }, Info{ speed, direct - 1, size });
	}
	// 우
	else if (direct == 3)
	{
		int rest = (C - col);

		if (rest < curSpeed)
		{
			curSpeed -= rest;
			curCol = C;
		}
		else
			return make_pair(Pos{ row, curCol + curSpeed }, Info{ speed, direct, size });

		int a = curSpeed / (C - 1);
		int b = curSpeed % (C - 1);

		// 홀수 - 방향 안 바뀜
		if (a % 2 == 1)
			return make_pair(Pos{ row, 1 + b }, Info{ speed, direct, size });
		// 짝수 - 방향 바뀜
		else
			return make_pair(Pos{ row, curCol - b }, Info{ speed, direct + 1, size });
	}
	// 좌
	else if (direct == 4)
	{
		int rest = (col - 1);

		if (rest < curSpeed)
		{
			curSpeed -= rest;
			curCol = 1;
		}
		else
			return make_pair(Pos{ row, curCol - curSpeed }, Info{ speed, direct, size });

		int a = curSpeed / (C - 1);
		int b = curSpeed % (C - 1);

		// 홀수 - 방향 안 바뀜
		if (a % 2 == 1)
			return make_pair(Pos{ row, C - b }, Info{ speed, direct, size });
		// 짝수 - 방향 바뀜
		else
			return make_pair(Pos{ row, curCol + b }, Info{ speed, direct - 1, size });
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	cin >> R >> C >> M;
	int r, c, s, d, z;
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z;
		arr[r][c] = Info{ s, d, z };
	}

	/*for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << arr[i][j].size << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/

	int answer = 0;
	// 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
	for (int time = 1; time <= C; time++)
	{
		// 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
		for (int i = 1; i <= R; i++)
		{
			if (arr[i][time].size != 0)
			{
				answer += arr[i][time].size;
				arr[i][time] = { 0, 0, 0 };
				break;
			}
		}

		Info mem[102][102];
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				mem[i][j] = { 0, 0, 0 };
			}
		}

		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				if (arr[i][j].size == 0)
					continue;

				int row = i;
				int col = j;
				int direct = arr[i][j].direct;
				int speed = arr[i][j].speed;
				int size = arr[i][j].size;

				pair<Pos, Info> ret;
				ret = move(row, col, speed, direct, size);

				if (mem[ret.first.row][ret.first.col].size != 0)
				{
					if (size > mem[ret.first.row][ret.first.col].size)
						mem[ret.first.row][ret.first.col] = Info { speed, ret.second.direct, size };
				}
				else
					mem[ret.first.row][ret.first.col] = Info{ speed, ret.second.direct, size };
			}
		}

		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				arr[i][j] = mem[i][j];
			}
		}

		/*for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				cout << arr[i][j].size << " ";
			}
			cout << "\n";
		}
		cout << "\n";

		for (auto sh : shark)
			cout << "row: " << sh.first.row << " col: " << sh.first.col << " direct: " << sh.second.direct << " speed: " << sh.second.speed  << " size:" << sh.second.size << "\n";
		cout << "\n";*/
	}

	cout << answer << "\n";
}