#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[100][100] = { 0 };
int N, K;

bool visited[100][100] = { false };

int r[4] = { -1, 1, 0, 0 };
int c[4] = { 0, 0, -1, 1 };

void bfs(int prevRow, int index)
{
	memset(visited, false, sizeof(visited));

	int mem[100][100] = { 0 };


	for (int a = 0; a < prevRow + 1; a++)
	{
		for (int b = index; b < N; b++)
		{
			if (map[a][b] != 0)
			{
				for (int i = 0; i < 4; i++)
				{
					int nrow = a + r[i];
					int ncol = b + c[i];

					if (0 <= nrow && nrow < N && 0 <= ncol && ncol < N)
					{
						if (!visited[nrow][ncol] && map[nrow][ncol] != 0 && abs(map[nrow][ncol] - map[a][b]) >= 5)
						{
							int value = abs(map[nrow][ncol] - map[a][b]);
							if (map[nrow][ncol] > map[a][b])
							{
								mem[nrow][ncol] -= value / 5;
								mem[a][b] += value / 5;
							}
							else
							{
								mem[nrow][ncol] += value / 5;
								mem[a][b] -= value / 5;
							}
						}
					}
				}

				visited[a][b] = true;
			}
		}
	}


	for (int a = 0; a < prevRow + 1; a++)
	{
		for (int b = index; b < N; b++)
		{
			map[a][b] += mem[a][b];
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	// 물고기가 있는 어항 중 가장 작은 열
	int index = 0;
	int answer = 0;

	vector<pair<int, int>> small;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> map[0][i];


	while (true)
	{
		int maxNum = 0;
		int minNum = 10001;
		// 물고기가 가장 적은 어항의 위치와 물고기 수의 차이를 구하는 과정
		for (int i = 0; i < N; i++)
		{
			maxNum = max(maxNum, map[0][i]);

			if (minNum == map[0][i])
				small.push_back(make_pair(0, i));
			else if (minNum > map[0][i])
			{
				minNum = map[0][i];
				small.clear();
				small.push_back(make_pair(0, i));
			}
		}

		if (maxNum - minNum <= K)
			break;

		++answer;

		// 물고기의 수가 가장 적은 어항에 물고기를 한 마리 넣는다.
		for (auto i : small)
			++map[i.first][i.second];

		// 먼저, 가장 왼쪽에 있는 어항을 그 어항의 오른쪽에 있는 어항의 위에 올려 놓는다.
		map[1][1] = map[0][0];
		map[0][0] = 0;
		index = 1;

		// 2개 이상 쌓여있는 어항을 모두 공중 부양시킨 다음, 전체를 시계방향으로 90도 회전시킨다
		int row;
		int col;

		while (true)
		{
			row = 0; // 공중 부양 해야하는 행의 개수
			col = 0; // 공중 부양 해야하는 열의 개수

			for (int i = index; i < N; i++)
			{
				if (map[1][i] != 0)
					++col;
				else
					break;
			}

			for (int i = 0; i < N; i++)
			{
				if (map[i][index] != 0)
					++row;
				else
					break;
			}

			// index = 3, row = 3, col = 2
			// 공중 부양시키고 회전시켜 쌓았을 때 범위를 넘는 경우
			if (row + index + col > N)
				break;

			for (int i = 0; i < row; i++)
			{
				for (int j = index; j < col + index; j++)
				{
					// 쌓였을 때 높이 index는 공중 부양하는 column 개수가 된다.
					// 거기서 column의 변화량 j - index 만큼 빠져 높이가 결정됨
					// 오른쪽으로 증가하면 아래로 감소하기 때문
					map[col - (j - index)][index + i + col] = map[i][j];
					map[i][j] = 0;
				}
			}

			// 공중 부양되어 쌓인 어항으로 인해
			// 가장 작은 2층이상 어항의 index를 재갱신
			index += col;
		}

		bfs(row, index);

		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				map[0][i * row + j] = map[j][index + i];
				map[j][index + i] = 0;
			}
		}

		// 첫번째 접기
		// 앞에 반절을 행을 증가시켜 역순으로 옮기기
		for (int i = 0; i < N / 2; i++)
		{
			map[1][N - 1 - i] = map[0][i];
			map[0][i] = 0;
		}


		// 두번째 접기
		// 뒤에 반절부터 다시 층마다 역순으로 옮기기
		// 가장 낮은 층이 가장 높은 층이 됨
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N / 4; j++)
			{
				map[3 - i][N - 1 - j] = map[i][j + N / 2];
				map[i][j + N / 2] = 0;
			}
		}

		bfs(4, N - N / 4 - 1);

		// 펼치기
		for (int i = 0; i < N / 4; i++) // 열
		{
			for (int j = 0; j < 4; j++) // 행
			{
				map[0][i * 4 + j] = map[j][N - N / 4 + i];
				map[j][N - N / 4 + i] = 0;
			}
		}
	}

	cout << answer << "\n";

	// (0, 0), (1, 0) -> (1, 0), (1, 1)

	// j -> row = j, i -> col = N - j - 1  [-90]
	// row = N - j - 1, col = i             [90]
	// (0, 1), (1, 1) -> (1, 2) (1, 3)
	// (0, 2), (0, 3), (1, 2), (1, 3) -> 


	// 물고기 수의 차이가 K이하이면 종료
	//if (maxNum - minNum >= K)
	//	cout << answer << "\n";

}
