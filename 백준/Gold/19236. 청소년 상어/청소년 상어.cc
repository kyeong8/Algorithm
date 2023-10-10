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

void dfs(int sum)
{
	if (sum > answer)
	{
		answer = sum;

		//cout << "answer: " << answer << "\n";
		//for (int i = 0; i < 4; i++)
		//{
		//	for (int j = 0; j < 4; j++)
		//	{
		//		cout << graph[i][j].num << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
	}

	Pos sharkMem = shark;
	Fish fishMem;

	Pos fishHis[17];
	Fish mem[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mem[i][j] = graph[i][j];
			fishHis[4 * i + (j + 1)] = fish[4 * i + (j + 1)];
		}
	}

	for (int i = 1; i <= 16; i++)
	{
		if (fish[i].del)
			continue;

		int row = fish[i].row;
		int col = fish[i].col;
		int direct = fish[i].direct;

		for (int j = 0; j < 8; j++)
		{
			int ndirect = (direct + j) % 8;
			int nrow = row + dr[ndirect];
			int ncol = col + dc[ndirect];

			if (!outofrange(nrow, ncol) && (nrow != shark.row || ncol != shark.col))
			{
				if (graph[nrow][ncol].num == 0)
				{
					fish[i] = { nrow, ncol, ndirect, false };
					graph[row][col] = { 0, 0 };
					graph[nrow][ncol] = { i, ndirect };
				}
				else
				{
					fishMem = graph[nrow][ncol];

					fish[i] = { nrow, ncol, ndirect, false };
					graph[nrow][ncol] = { i, ndirect };
					fish[fishMem.num] = { row, col, fishMem.direct, false };
					graph[row][col] = fishMem;
				}

				break;
			}
		}
	}

	for (int i = 1; i <= 3; i++)
	{
		int nrow = shark.row + i * dr[shark.direct];
		int ncol = shark.col + i * dc[shark.direct];

		if (!outofrange(nrow, ncol) && graph[nrow][ncol].num > 0)
		{
			fishMem = graph[nrow][ncol];
			
			shark = { nrow, ncol, fishMem.direct };
			
			fish[fishMem.num].del = true;
			graph[nrow][ncol] = { 0, 0 };

			dfs(sum + fishMem.num);

			shark = sharkMem;
			fish[fishMem.num].del = false;
			graph[nrow][ncol] = fishMem;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			graph[i][j] = mem[i][j];
			fish[4 * i + (j + 1)] = fishHis[4 * i + (j + 1)];
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

	dfs(sum);

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