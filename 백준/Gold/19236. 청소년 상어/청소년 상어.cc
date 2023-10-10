/******************************************************************************

							  Online C++ Compiler.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// dfs, back tracking

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Pos
{
	int row;
	int col;
	int direct;
	bool del;
};

struct Fish {
	int num;
	int direct;
};

Pos fish[17];
Fish graph[4][4];
Pos shark;
int answer;


int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

bool outofrange(int row, int col)
{
	if (0 <= row && row < 4 && 0 <= col && col < 4)
		return false;
	return true;
}

void dfs(int sum, Pos fish[], Fish graph[][4])
{
	if (sum > answer)
		answer = sum;

	Pos sharkMem = shark;
	Fish fishMem;

	Pos fishs[17];
	Fish arr[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = graph[i][j];
			fishs[4 * i + (j + 1)] = fish[4 * i + (j + 1)];
		}
	}

	for (int i = 1; i <= 16; i++)
	{
		if (fishs[i].del)
			continue;

		int row = fishs[i].row;
		int col = fishs[i].col;
		int direct = fishs[i].direct;

		for (int j = 0; j < 8; j++)
		{
			int ndirect = (direct + j) % 8;
			int nrow = row + dr[ndirect];
			int ncol = col + dc[ndirect];

			if (!outofrange(nrow, ncol) && (nrow != shark.row || ncol != shark.col))
			{
				if (arr[nrow][ncol].num == 0)
				{
					fishs[i] = { nrow, ncol, ndirect, false };
					arr[row][col] = { 0, 0 };
					arr[nrow][ncol] = { i, ndirect };
				}
				else
				{
					fishMem = arr[nrow][ncol];

					fishs[i] = { nrow, ncol, ndirect, false };
					arr[nrow][ncol] = { i, ndirect };
					fishs[fishMem.num] = { row, col, fishMem.direct, false };
					arr[row][col] = fishMem;
				}

				break;
			}
		}
	}

	for (int i = 1; i <= 3; i++)
	{
		int nrow = shark.row + i * dr[shark.direct];
		int ncol = shark.col + i * dc[shark.direct];

		if (!outofrange(nrow, ncol) && arr[nrow][ncol].num > 0)
		{
			fishMem = arr[nrow][ncol];

			shark = { nrow, ncol, fishMem.direct };

			fishs[fishMem.num].del = true;
			arr[nrow][ncol] = { 0, 0 };

			dfs(sum + fishMem.num, fishs, arr);

			shark = sharkMem;
			fishs[fishMem.num].del = false;
			arr[nrow][ncol] = fishMem;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	answer = 0;
	shark.del = false;
	int a, b;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> a >> b;
			fish[a] = { i, j, b - 1, false };
			graph[i][j] = { a, b - 1 };
		}
	}

	shark = { 0, 0, graph[0][0].direct };
	int sum = graph[0][0].num;
	fish[graph[0][0].num].del = true;
	graph[0][0] = { 0, 0 };

	dfs(sum, fish, graph);

	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		cout << graph[i][j].num << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	cout << answer << "\n";
}