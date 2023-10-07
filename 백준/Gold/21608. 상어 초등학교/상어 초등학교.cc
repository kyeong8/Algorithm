// 4명의 좋아하는 학생 저장

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N;
vector<int> like[401];
int map[21][21] = { 0 };

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool outofrange(int row, int col)
{
	if (1 <= row && row <= N && 1 <= col && col <= N)
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> N;

	memset(map, 0, sizeof(map));

	for (int count = 1; count <= N * N; count++)
	{
		int my;
		cin >> my;
		for (int i = 0; i < 4; i++)
		{
			int you;
			cin >> you;
			like[my].push_back(you);
		}

		int maxCnt = -1;
		int maxBlink = -1;
		pair<int, int> pos;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] != 0)
					continue;

				int cnt = 0;
				int blink = 0;
				for (int k = 0; k < 4; k++)
				{
					int row = i + dr[k];
					int col = j + dc[k];
					
					if (!outofrange(row, col))
					{
						int idx = map[row][col];
						if (find(like[my].begin(), like[my].end(), idx) != like[my].end())
							++cnt;
						if (idx == 0)
							++blink;
					}
				}

				if (maxCnt < cnt)
				{
					maxCnt = cnt;
					maxBlink = blink;
					pos = { i, j };
				}
				else if (maxCnt == cnt)
				{
					if (maxBlink < blink)
					{
						maxCnt = cnt;
						maxBlink = blink;
						pos = { i, j };
					}
				}
			}
		}

		map[pos.first][pos.second] = my;
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int my = map[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int row = i + dr[k];
				int col = j + dc[k];

				if (!outofrange(row, col))
				{
					int idx = map[row][col];
					if (find(like[my].begin(), like[my].end(), idx) != like[my].end())
						++cnt;
				}
			}
			if (cnt > 0)
				answer += pow(10, cnt - 1);
		}
	}

	cout << answer << "\n";

	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= N; j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
}