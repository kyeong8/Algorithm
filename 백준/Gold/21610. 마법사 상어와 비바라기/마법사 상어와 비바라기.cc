#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Pos {
	int row;
	int col;
};

int A[50][50] = { 0 };
int N, M;
int dr[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

deque<Pos> cloud;
bool mem[50][50] = { false };

bool inofrange(int row, int col)
{
	if (0 <= row && row < N && 0 <= col && col < N)
		return true;
	return false;
}

void initCloud()
{
	cloud.push_back(Pos{ N - 2, 0 });
	cloud.push_back(Pos{ N - 2, 1 });
	cloud.push_back(Pos{ N - 1, 0 });
	cloud.push_back(Pos{ N - 1, 1 });
}

// 1 3 5 7
void waterCopyBug()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!mem[i][j])
				continue;

			int cnt = 0;
			for (int k = 1; k < 8; k += 2)
			{
				int nrow = i + dr[k];
				int ncol = j + dc[k];

				if (inofrange(nrow, ncol) && A[nrow][ncol] > 0)
					cnt++;
			}

			A[i][j] += cnt;
		}
	}
}

void moveCloud(int direct, int speed)
{
	while (!cloud.empty())
	{
		int row = cloud.front().row;
		int col = cloud.front().col;
		cloud.pop_front();

		int nrow = row + speed * dr[direct];
		int ncol = col + speed * dc[direct];

		if (nrow >= 0)
			nrow %= N;
		else
			nrow = N - 1 - abs(nrow + 1) % N;
		if (ncol >= 0)
			ncol %= N;
		else
			ncol = N - 1 - abs(ncol + 1) % N;

		A[nrow][ncol]++;
		mem[nrow][ncol] = true;
	}
}

void createCloud()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!mem[i][j])
			{
				if (A[i][j] >= 2)
				{
					cloud.push_back(Pos{ i, j });
					A[i][j] -= 2;
				}
			}
			else
				mem[i][j] = false;
		}
	}
}

int main()
{
	// initCloud(); -> (N, 1), (N, 2), (N-1, 1), (N-1, 2)
	// moveCloud(); >> addWater(); removeCloud();
	// waterCopyBug(); -> 이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다. -> 이동과는 다르게 처리
	// createCloud(); -> 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다. -> 사라진 칸 기록

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	initCloud();

	int d, s;
	for (int step = 0; step < M; step++)
	{
		cin >> d >> s;
		moveCloud(d - 1, s);

		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		cout << A[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
		
		waterCopyBug();

		createCloud();
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			answer += A[i][j];

	cout << answer << "\n";
}