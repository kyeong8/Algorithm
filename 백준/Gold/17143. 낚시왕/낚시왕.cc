#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Shark {
	int s;
	int d;
	int z;
};

// start: 4, <-, ->, 1 ~ 6
// 방향을 보고 왼쪽이면 length - (pos - 1), (pos - 1)만큼 shift
// 오른쪽이면 length - (6 - pos), (6 - pos)만큼 shift
// pos- 1 or 6 - pos가 legnth보다 크다?
// 왼쪽은 pos - legnth, 오른쪽은 length - pos
// 3 2 1 2 3 4 5 6 5  4  3  2  1  2  3  4  5  6
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18

int R, C, M;
Shark arr[102][102];
int hunter = 0;
int answer = 0;

//// 위 아래 오른쪽 왼쪽
//int dr[] = { -1, 1, 0, 0 };
//int dc[] = { 0, 0, 1, -1 };

int change(int direct)
{
	if (direct == 1)
		return 2;
	else if (direct == 2)
		return 1;
	else if (direct == 3)
		return 4;
	else if (direct == 4)
		return 3;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> R >> C >> M;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			arr[i][j] = { 0, 0, 0 };
		}
	}

	int r, c, s, d, z;
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z;
		arr[r][c] = { s, d, z };
	}

	//for (int i = 1; i <= R; i++)
	//{
	//	for (int j = 1; j <= C; j++)
	//	{
	//		cout << arr[i][j].d << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	while (true)
	{
		// 낚시왕이 오른쪽으로 한 칸 이동한다.
		++hunter;

		//cout << "hunter: " << hunter << "\n";
		// 낚시왕이 격자 밖으로 나가면 종료
		if (hunter > C)
			break;

		// 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다
		for (int i = 1; i <= R; i++)
		{
			// 격자판에서 잡은 상어가 사라진다.
			if (arr[i][hunter].z != 0)
			{
				answer += arr[i][hunter].z;
				arr[i][hunter] = { 0, 0, 0 };
				break;
			}
		}

		// 상어가 이동한다.
		Shark mem[102][102];
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
				if (arr[i][j].z == 0)
					continue;

				int row = i;
				int col = j;
				int direct = arr[i][j].d;
				int speed = arr[i][j].s;
				int size = arr[i][j].z;


				int nrow, ncol;
				// 왼쪽 오른쪽
				if (direct > 2)
				{
					nrow = row, ncol = col;
					while (true)
					{
						//cout << "Speed: " << speed << "\n";
						//cout << "ncol: " << ncol << "\n";
						//cout << "direct: " << direct << "\n";

						if (direct == 4 && speed > ncol - 1)
						{
							speed -= ncol - 1;
							direct = change(direct);
							ncol = 1;
						}
						else if (direct == 3 && speed > C - ncol)
						{
							speed -= C - ncol;
							direct = change(direct);
							ncol = C;
						}
						else if (direct == 4 && speed <= ncol - 1)
						{
							ncol -= speed;
							speed = 0;
						}
						else if (direct == 3 && speed <= C - ncol)
						{
							ncol += speed;
							speed = 0;
						}

						if (speed == 0)
							break;
					}
					//cout << "destination: " << ncol << "\n\n";
				}
				// 위 아래
				else if (direct <= 2)
				{
					nrow = row, ncol = col;
					while (true)
					{
						//cout << "Speed: " << speed << "\n";
						//cout << "ncol: " << ncol << "\n";
						//cout << "direct: " << direct << "\n";

						if (direct == 1 && speed > nrow - 1)
						{
							speed -= nrow - 1;
							direct = change(direct);
							nrow = 1;
						}
						else if (direct == 2 && speed > R - nrow)
						{
							speed -= R - nrow;
							direct = change(direct);
							nrow = R;
						}
						else if (direct == 1 && speed <= nrow - 1)
						{
							nrow -= speed;
							speed = 0;
						}
						else if (direct == 2 && speed <= R - nrow)
						{
							nrow += speed;
							speed = 0;
						}

						if (speed == 0)
							break;
					}
					//cout << "destination: " << ncol << "\n\n";
				}

				if (mem[nrow][ncol].z != 0)
				{
					int compareSize = mem[nrow][ncol].z;

					if (size > compareSize)
						mem[nrow][ncol] = Shark{ arr[i][j].s, direct, size };
				}
				else
					mem[nrow][ncol] = Shark{ arr[i][j].s, direct, size };
			}
		}

		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				arr[i][j] = mem[i][j];
			}
		}

		//for (int i = 1; i <= R; i++)
		//{
		//	for (int j = 1; j <= C; j++)
		//	{
		//		cout << arr[i][j].d << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
		
	}

	cout << answer << "\n";
}
