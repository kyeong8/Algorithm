// 방향에 따라 달라지는 모래의 분포
// 격자 밖으로 나간 모래를 저장
// 달팽이 모양 이동

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
int graph[500][500];
int out;

// 좌 하 우 상
int dr[] = { 0, 1, 0, -1 };
int dc[] = { -1, 0, 1, 0 };

bool outofrange(int row, int col)
{
	if (1 <= row && row <= N && 1 <= col && col <= N)
		return false;
	return true;
}

void spread(int row, int col, int dir)
{
	int y = graph[row][col];
	graph[row][col] = 0;
	int alpha = 0;

	/////////////////
    ////// 위 ///////
    /////////////////
	int temp = (dir + 1) % 4;
	int nrow = row + dr[temp];
	int ncol = col + dc[temp];

	if (!outofrange(nrow, ncol))
		graph[nrow][ncol] += (int)(y * 0.07);
	else
		out += (int)(y * 0.07);
	alpha += (int)(y * 0.07);

	/////////////////
	nrow = nrow + dr[dir];
	ncol = ncol + dc[dir];

	if (!outofrange(nrow, ncol))
		graph[nrow][ncol] += (int)(y * 0.1);
	else
		out += (int)(y * 0.1);
	alpha += (int)(y * 0.1);
	
	/////////////////
	nrow = nrow - 2 * dr[dir];
	ncol = ncol - 2 * dc[dir];

	if (!outofrange(nrow, ncol))
		graph[nrow][ncol] += (int)(y * 0.01);
	else
		out += (int)(y * 0.01);
	alpha += (int)(y * 0.01);
	
	/////////////////
	nrow = row + 2 * dr[temp];
	ncol = col + 2 * dc[temp];

	if (!outofrange(nrow, ncol))
		graph[nrow][ncol] += (int)(y * 0.02);
	else
		out += (int)(y * 0.02);
	alpha += (int)(y * 0.02);

	/////////////////
	////// 아래 /////
	/////////////////
	if (dir == 0)
		temp = 3;
	else
		temp = (dir - 1) % 4;
	nrow = row + dr[temp];
	ncol = col + dc[temp];

	if (!outofrange(nrow, ncol))
		graph[nrow][ncol] += (int)(y * 0.07);
	else
		out += (int)(y * 0.07);
	alpha += (int)(y * 0.07);
	
	/////////////////
	nrow = nrow + dr[dir];
	ncol = ncol + dc[dir];

	if (!outofrange(nrow, ncol))
		graph[nrow][ncol] += (int)(y * 0.1);
	else
		out += (int)(y * 0.1);
	alpha += (int)(y * 0.1);
	
	/////////////////
	nrow = nrow - 2 * dr[dir];
	ncol = ncol - 2 * dc[dir];

	if (!outofrange(nrow, ncol))
		graph[nrow][ncol] += (int)(y * 0.01);
	else
		out += (int)(y * 0.01);
	alpha += (int)(y * 0.01);
	
	/////////////////
	nrow = row + 2 * dr[temp];
	ncol = col + 2 * dc[temp];

	if (!outofrange(nrow, ncol))
		graph[nrow][ncol] += (int)(y * 0.02);
	else
		out += (int)(y * 0.02);
	alpha += (int)(y * 0.02);
	
	/////////////////
	//// 진행방향 ////
	/////////////////

	nrow = row + 2 * dr[dir];
	ncol = col + 2 * dc[dir];

	if (!outofrange(nrow, ncol))
		graph[nrow][ncol] += (int)(y * 0.05);
	else
		out += (int)(y * 0.05);
	alpha += (int)(y * 0.05);
	
	//////////////
	nrow = row + dr[dir];
	ncol = col + dc[dir];

	if (!outofrange(nrow, ncol))
		graph[nrow][ncol] += (y - alpha);
	else
		out += (y - alpha);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	out = 0;
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> graph[i][j];
		}
	}

	int row = N / 2 + 1;
	int col = row;
	int dir = 0;
	int length = 1;
	int rest = length;
	int iter = 2;
	int distance = N * N - 1;

	while (true)
	{
		if (distance == 0)
			break;
		--distance;

		int nrow = row + dr[dir];
		int ncol = col + dc[dir];
		row = nrow;
		col = ncol;
		
		spread(row, col, dir);

		//cout << "round: " << N * N - distance << "\n";
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		cout << graph[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
		
		--rest;
		if (rest == 0)
		{
			dir = (dir + 1) % 4;

			--iter;
			if (iter == 0)
			{
				++length;
				iter = 2;
			}
			rest = length;
		}
	}

	cout << out << "\n";
}