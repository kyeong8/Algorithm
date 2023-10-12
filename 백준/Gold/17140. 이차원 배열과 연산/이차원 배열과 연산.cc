#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int r, c, k;
int A[100][100] = { 0 };
int cnt[101];
int rowCnt;
int colCnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> r >> c >> k;

	rowCnt = 3;
	colCnt = 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> A[i][j];
		}
	}

	int round = 0;
	while (true)
	{
		if (A[r - 1][c - 1] == k || round > 100)
			break;

		if (rowCnt >= colCnt)
		{
			int maxCol = colCnt;
			for (int i = 0; i < rowCnt; i++)
			{
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
				memset(cnt, 0, sizeof(cnt));

				int maxNum = 0;
				for (int j = 0; j < colCnt; j++)
				{
					if (A[i][j] == 0)
						continue;

					++cnt[A[i][j]];
					if (A[i][j] > maxNum)
						maxNum = A[i][j];

					A[i][j] = 0;
				}
				
				for (int j = 0; j <= maxNum; j++)
				{
					if (cnt[j] > 0)
						pq.push(make_pair(cnt[j], j));
				}

				int idx = 0;
				while (!pq.empty())
				{
					A[i][idx] = pq.top().second;
					A[i][idx+1] = pq.top().first;

					pq.pop();
					idx += 2;
				}

				if (maxCol < idx)
					maxCol = idx;
			}

			colCnt = maxCol;
		}
		else
		{
			int maxRow = rowCnt;
			for (int i = 0; i < colCnt; i++)
			{
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
				memset(cnt, 0, sizeof(cnt));

				int maxNum = 0;
				for (int j = 0; j < rowCnt; j++)
				{
					if (A[j][i] == 0)
						continue;
					++cnt[A[j][i]];
					if (A[j][i] > maxNum)
						maxNum = A[j][i];

					A[j][i] = 0;
				}

				for (int j = 0; j <= maxNum; j++)
				{
					if (cnt[j] > 0)
						pq.push(make_pair(cnt[j], j));
				}

				int idx = 0;
				while (!pq.empty())
				{
					A[idx][i] = pq.top().second;
					A[idx + 1][i] = pq.top().first;

					pq.pop();
					idx += 2;
				}

				if (maxRow < idx)
					maxRow = idx;
			}

			rowCnt = maxRow;
		}

		//for (int i = 0; i < rowCnt; i++)
		//{
		//	for (int j = 0; j < colCnt; j++)
		//	{
		//		cout << A[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		//break;
		++round;
	}

	if (round > 100)
		cout << "-1\n";
	else
		cout << round << "\n";

	
}
