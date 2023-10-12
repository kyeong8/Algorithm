#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
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
bool arr[102][102] = { false };
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

	map<pair<int, int>, Shark> shark;
	
	cin >> R >> C >> M;
	int r, c, s, d, z;
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z;
		shark[make_pair( r, c )] = Shark{ s, d, z };
		arr[r][c] = true;
	}

	//for (int i = 1; i <= R; i++)
	//{
	//	for (int j = 1; j <= C; j++)
	//	{
	//		cout << arr[i][j] << " ";
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
			if (arr[i][hunter])
			{
				answer += shark[make_pair(i, hunter)].z;
				shark.erase(make_pair(i, hunter));
				arr[i][hunter] = false;
				break; 
			}
		}

		// 상어가 이동한다.
		map<pair<int, int>, Shark> mem;
		for (auto sh : shark)
		{
			int row = sh.first.first;
			int col = sh.first.second;
			int direct = sh.second.d;
			int speed = sh.second.s;
			int size = sh.second.z;

			//cout << "row: " << row << " col: " << col << "\n";

			arr[row][col] = false;
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

			if (mem.find(make_pair(nrow, ncol)) != mem.end())
			{
				int compareSize = mem[make_pair(nrow, ncol)].z;

				if (size > compareSize)
					mem[make_pair(nrow, ncol)] = Shark{ sh.second.s, direct, sh.second.z };
			}
			else
				mem[make_pair(nrow, ncol)] = Shark{ sh.second.s, direct, sh.second.z };
		}
		shark = mem;

		for (auto sh : shark)
			arr[sh.first.first][sh.first.second] = true;

		//for (int i = 1; i <= R; i++)
		//{
		//	for (int j = 1; j <= C; j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		//for (auto sh : shark)
		//	cout << "row: " << sh.first.first << " col: " << sh.first.second << " direct: " << sh.second.d << " speed: " << sh.second.s  << " size:" << sh.second.z << "\n";
		//cout << "\n";
	}

	cout << answer << "\n";
}
