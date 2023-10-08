// 같은 칸에 여러 개의 파이어볼을 어떻게 다룰 것인가
// 파이어볼의 소멸과 질량, 속력, 방향을 어떻게 다룰 것인가

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct Fire {
	int m;
	int s;
	int d;
};

int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K;
vector<Fire> fire[51][51];
vector<Fire> mem[51][51];

pair<int, int> connect(int row, int col)
{
	pair<int, int> ret = make_pair(row, col);
	if (row < 1)
		ret.first = N + row % N;
	else if (row > N)
		ret.first = (row - 1) % N + 1;
	if (col < 1)
		ret.second = N + col % N;
	else if (col > N)
		ret.second = (col - 1) % N + 1;

	return ret;
}

void move()
{
	vector<Fire> mem[51][51];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!fire[i][j].empty())
			{
				for (auto f : fire[i][j])
				{
					int row = i + f.s * dr[f.d];
					int col = j + f.s * dc[f.d];
					pair<int, int> pos = connect(row, col);

					mem[pos.first][pos.second].push_back(f);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (mem[i][j].size() >= 2)
			{
				int mass = 0;
				int speed = 0;
				pair<int, int> oddEven = make_pair(0, 0);
				int size = mem[i][j].size();

				for (int k = 0; k < size; k++)
				{
					mass += mem[i][j][mem[i][j].size() - 1].m;
					speed += mem[i][j][mem[i][j].size() - 1].s;
					if (mem[i][j][mem[i][j].size() - 1].d % 2 == 1)
						++oddEven.first;
					else
						++oddEven.second;
					mem[i][j].pop_back();
				}

				mass /= 5;
				speed /= size;

				if (mass != 0)
				{
					int k;
					if (oddEven.first == 0 || oddEven.second == 0)
						k = 0;
					else
						k = 1;
					for (; k < 8; k += 2)
						mem[i][j].push_back(Fire{ mass, speed, k });
				}
				else
					mem[i][j].clear();
			}

			//fire[i][j].clear();
			//copy(mem[i][j].begin(), mem[i][j].end(), fire[i][j].begin());
			fire[i][j] = mem[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;

	int r, c, m, s, d;
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> m >> s >> d;
		fire[r][c].push_back(Fire{ m, s, d });
	}

	for (int round = 1; round <= K; round++)
	{
		move();
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		cout << fire[i][j].size() << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
	}
	
	int answer = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (auto f : fire[i][j])
			{
				answer += f.m;
			}
		}
	}

	cout << answer << "\n";
}