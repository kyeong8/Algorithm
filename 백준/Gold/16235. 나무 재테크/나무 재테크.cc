// 2023-09-21 
// bj23289_온풍기 안녕!
// 9시간 (방향 잘못 쓰고 열전달을 잘못 이해함, 벽 조건도 잘못 읽음)
// 3방향으로 뻗어나가는 열전달 방법, 한 번에 조절되는 온도
// 구현, 시뮬레이션
// vector, 2차원배열

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

int r[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int c[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int A[11][11];
	int water[11][11];
	deque<int> arr[11][11];
	int answer = 0;

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
			water[i][j] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> z;
		arr[x][y].push_back(z);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			sort(arr[i][j].begin(), arr[i][j].end());
		}
	}

	for (int year = 0; year < K; year++)
	{
		int mem[11][11] = { 0 };

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int index = 0;
				for (int k = 0; k < arr[i][j].size(); k++)
				{
					if (water[i][j] >= arr[i][j][k])
					{
						water[i][j] -= arr[i][j][k];
						++arr[i][j][k];
						index = k + 1;
					}
					else
					{
						index = k;
						break;
					}
				}

				for (int k = index; k < arr[i][j].size(); k++)
				{
					water[i][j] += (arr[i][j][k] / 2);
				}


				while (arr[i][j].size() != index)
				{
					arr[i][j].pop_back();
				}

				for (int k = 0; k < arr[i][j].size(); k++)
				{
					if (arr[i][j][k] % 5 == 0)
					{
						for (int d = 0; d < 8; d++)
						{
							int row = i + r[d];
							int col = j + c[d];

							if (1 <= row && row <= N && 1 <= col && col <= N)
							{
								++mem[row][col];
							}
						}
					}
				}
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				water[i][j] += A[i][j];

				for (int k = 0; k < mem[i][j]; k++)
					arr[i][j].push_front(1);

				if (year == K - 1)
				{
					answer += arr[i][j].size();
				}
			}
		}

		memset(mem, 0, sizeof(mem));
	}

	cout << answer << "\n";
}
