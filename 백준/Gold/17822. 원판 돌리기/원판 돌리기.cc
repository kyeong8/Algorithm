// 원판의 회전, 인접

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct Pos {
	int row;
	int col;
};

int N, M, K;
int disk[50][50];

int connect(int col)
{
	int ret = col;
	if (col < 0)
		ret = M - 1 + (col + 1) % M;
	else if (col >= M)
		ret = col % M;

	return ret;
}

// 상 우 하 좌
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> disk[i][j];
		}
	}

	int x, d, k;
	for (int round = 1; round <= K; round++)
	{
		cin >> x >> d >> k;

		for (int i = x; i <= N; i += x)
		{
			// 시계방향
			if (d == 0)
			{
				for (int t = 0; t < k; t++)
				{
					int temp = disk[i - 1][M - 1];
					for (int j = M - 2; j >= 0; j--)
						disk[i - 1][j + 1] = disk[i - 1][j];
					disk[i - 1][0] = temp;
				}
			}
			else
			{
				for (int t = 0; t < k; t++)
				{
					int temp = disk[i - 1][0];
					for (int j = 1; j < M; j++)
						disk[i - 1][j - 1] = disk[i - 1][j];
					disk[i - 1][M - 1] = temp;
				}
			}
		}

		//for (int row = 0; row < N; row++)
		//{
		//	for (int col = 0; col < M; col++)
		//	{
		//		cout << disk[row][col] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
		
		bool visited[50][50] = { false };
		int cnt = 0;
		int total = 0;
		vector<Pos> mem;
		for (int row = 0; row < N; row++)
		{
			for (int col = 0; col < M; col++)
			{
				if (disk[row][col] == 0)
					continue;

				total += disk[row][col];
				++cnt;

				for (int j = 0; j < 4; j++)
				{
					int nrow = row + dr[j];
					int ncol = col + dc[j];
					ncol = connect(ncol);
					
					if (0 <= nrow && nrow < N && !visited[nrow][ncol] && disk[nrow][ncol] == disk[row][col])
					{
						visited[nrow][ncol] = true;
						mem.push_back(Pos{ nrow, ncol });
					}
				}
			}
		}

		if (!mem.empty())
		{
			for (auto m : mem)
				disk[m.row][m.col] = 0;
		}
		else
		{
			float aver = total / (float)cnt;
			//cout << "total: " << total << " cnt: " << cnt << "\n";
			//cout << "aver: " << aver << "\n";
			for (int row = 0; row < N; row++)
			{
				for (int col = 0; col < M; col++)
				{
					if (disk[row][col] == 0)
						continue;

					if (disk[row][col] > aver)
						--disk[row][col];
					else if (disk[row][col] < aver)
						++disk[row][col];
				}
			}
		}
	}
	
	int answer = 0;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			//cout << disk[row][col] << " ";
			answer += disk[row][col];
		}
		//cout << "\n";
	}
	//cout << "\n";

	cout << answer << "\n";
}