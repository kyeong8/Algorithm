// 흰색인 경우에는 그 칸으로 이동한다. 이동하려는 칸에 말이 이미 있는 경우에는 가장 위에 A번 말을 올려놓는다
// A번 말의 위에 다른 말이 있는 경우에는 A번 말과 위에 있는 모든 말이 이동한다.
// 예를 들어, A, B, C로 쌓여있고, 이동하려는 칸에 D, E가 있는 경우에는 A번 말이 이동한 후에는 D, E, A, B, C가 된다.
// 빨간색인 경우에는 이동한 후에 A번 말과 그 위에 있는 모든 말의 쌓여있는 순서를 반대로 바꾼다.
// A, B, C가 이동하고, 이동하려는 칸에 말이 없는 경우에는 C, B, A가 된다.
// A, D, F, G가 이동하고, 이동하려는 칸에 말이 E, C, B로 있는 경우에는 E, C, B, G, F, D, A가 된다.
// 파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다. 
// 방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히 있는다. (방향은 바꿔줘야 한다.)
// 체스판을 벗어나는 경우에는 파란색과 같은 경우이다.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
	int row;
	int col;
	int direct;
};

int N, K;
int arr[12][12];
vector<Player> player;
vector<int> here[12][12];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { 1, -1, 0, 0 };

bool outofrange(int row, int col)
{
	if (0 <= row && row < N && 0 <= col && col < N)
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	int row, col, direct;
	for (int i = 0; i < K; i++)
	{
		cin >> row >> col >> direct;
		player.push_back(Player{ row - 1, col - 1, direct - 1 });
		here[row - 1][col - 1].push_back(i);
	}


	int round = 1;
	bool exit = false;
	while (true)
	{
		if (round > 1000)
			break;

		for (int i = 0; i < K; i++)
		{
			int row = player[i].row;
			int col = player[i].col;

			// 자기 자신과 업고 있는 애들 저장
			bool flag = false;
			int size = here[row][col].size();
			vector<int> high;
			for (int idx = 0; idx < size; idx++)
			{
				if (flag)
					high.push_back(here[row][col][idx]);

				if (here[row][col][idx] == i)
				{
					high.push_back(here[row][col][idx]);
					flag = true;
				}
			}

			// 아직 자기 자신과 업고 있는 애들은 기존 위치에 있음.

			int nrow = row + dr[player[i].direct];
			int ncol = col + dc[player[i].direct];

			if (!outofrange(nrow, ncol) && arr[nrow][ncol] == 0)
			{
				// 자기 자신과 업고 있던 애들 전부 옮긴다.
				if (!high.empty())
				{
					for (auto h : high)
						here[nrow][ncol].push_back(h);
				}

				// 자기 자신과 업고 있던 애들을 이전 위치에서 빼내고 바뀐 위치로 옮긴다.
				for (int j = 0; j < (int)high.size(); j++)
				{
					int num = here[row][col].back();
					here[row][col].pop_back();

					player[num].row = nrow;
					player[num].col = ncol;
				}
			}
			else if (!outofrange(nrow, ncol) && arr[nrow][ncol] == 1)
			{
				// 자기 자신과 업고 있는 애들이 있다면
				if (!high.empty())
				{
					// 업고 있던 애들의 순서를 반대로 바꾸고 전부 움직일 위치에 옮긴다.
					reverse(high.begin(), high.end());
					for (auto h : high)
						here[nrow][ncol].push_back(h);
				}

				for (int j = 0; j < (int)high.size(); j++)
				{
					int num = here[row][col].back();
					here[row][col].pop_back();

					player[num].row = nrow;
					player[num].col = ncol;
				}
			}
			else if (arr[nrow][ncol] == 2 || outofrange(nrow, ncol))
			{
				// 말의 이동 방향을 반대로 한다.
				if (player[i].direct == 0)
					player[i].direct = 1;
				else if (player[i].direct == 1)
					player[i].direct = 0;
				else if (player[i].direct == 2)
					player[i].direct = 3;
				else if (player[i].direct == 3)
					player[i].direct = 2;

				int nnrow = row + dr[player[i].direct];
				int nncol = col + dc[player[i].direct];

				// 방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히 있는다.
				if (arr[nnrow][nncol] != 2 && !outofrange(nnrow, nncol))
				{
					// 다시 체스판 색깔에 따라 행동한다.
					if (arr[nnrow][nncol] == 0)
					{
						// 자기 자신과 업고 있던 애들 전부 옮긴다.
						if (!high.empty())
						{
							for (auto h : high)
								here[nnrow][nncol].push_back(h);
						}

						// 자기 자신과 업고 있던 애들을 이전 위치에서 빼내고 바뀐 위치로 옮긴다.
						for (int j = 0; j < (int)high.size(); j++)
						{
							int num = here[row][col].back();
							here[row][col].pop_back();

							player[num].row = nnrow;
							player[num].col = nncol;
						}
					}
					else if (arr[nnrow][nncol] == 1)
					{
						// 자기 자신과 업고 있는 애들이 있다면
						if (!high.empty())
						{
							// 업고 있던 애들의 순서를 반대로 바꾸고 전부 움직일 위치에 옮긴다.
							reverse(high.begin(), high.end());
							for (auto h : high)
								here[nnrow][nncol].push_back(h);
						}

						for (int j = 0; j < (int)high.size(); j++)
						{
							int num = here[row][col].back();
							here[row][col].pop_back();

							player[num].row = nnrow;
							player[num].col = nncol;
						}
					}
				}
			}

			// 종료 조건:  턴이 진행되던 중에 말이 4개 이상 쌓이는 순간

			if (here[player[i].row][player[i].col].size() >= 4)
			{
				exit = true;
				break;
			}
		}

		if (exit)
			break;

		++round;
	}

	if (round > 1000)
		cout << "-1\n";
	else
		cout << round << "\n";
}
