#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Mem {
	int row;
	int col;
	int blink;
	int student;
};

int arr[21][21] = { 0 };
int seq[400] = { 0 };
bool like[401][401] = { false };
int N;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool inofrange(int row, int col)
{
	if (1 <= row && row <= N && 1 <= col && col <= N)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		cin >> seq[i];
		int temp;
		for (int j = 0; j < 4; j++)
		{
			cin >> temp;
			like[seq[i]][temp] = true;
		}
	}

	for (int idx = 0; idx < N * N; idx++)
	{
		vector<Mem> mem;
		int num = seq[idx];
		int maxCnt = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][j] != 0)
					continue;

				int cnt = 0;
				int blink = 0;
				for (int k = 0; k < 4; k++)
				{
					int nrow = i + dr[k];
					int ncol = j + dc[k];

					if (inofrange(nrow, ncol) && like[num][arr[nrow][ncol]])
						cnt++;
					else if (inofrange(nrow, ncol) && arr[nrow][ncol] == 0)
						blink++;
				}

				if (maxCnt < cnt)
				{
					mem.clear();
					mem.push_back(Mem{ i, j, blink, cnt });
					maxCnt = cnt;
				}
				else if (maxCnt == cnt)
					mem.push_back(Mem{ i, j, blink, cnt });
			}
		}

		Mem best;
		best.row = N + 1;
		best.col = N + 1;
		best.blink = 0;
		best.student = 0;
		for (int i = 0; i < mem.size(); i++)
		{
			if (mem[i].student > best.student)
				best = mem[i];
			else if (mem[i].student == best.student)
			{
				if (mem[i].blink > best.blink)
					best = mem[i];
				else if (mem[i].blink == best.blink)
				{
					if (mem[i].row < best.row)
						best = mem[i];
					else if (mem[i].row == best.row)
					{
						if (mem[i].col < best.col)
							best = mem[i];
					}
				}
			}
		}

		arr[best.row][best.col] = num;

		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int num = arr[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nrow = i + dr[k];
				int ncol = j + dc[k];

				if (inofrange(nrow, ncol) && like[num][arr[nrow][ncol]])
					cnt++;
			}
			answer += pow(10, cnt - 1);
		}
	}

	cout << answer << "\n";
}