#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[20][20];
int A[20][20];
int answer = 987654321;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int dy[] = { 1, 1 };
int dx[] = { -1, 1 };

bool outofrange(int row, int col)
{
	if (0 <= row && row < N && 0 <= col && col < N)
		return false;
	return true;
}
//
//void five(int row, int col, int a, int b)
//{
//	arr[row][col] = 5;
//
//	int curRow = row;
//	int curCol = col;
//	for (int i = 0; i < a; i++)
//	{
//		int nrow = curRow + dy[0];
//		int ncol = curCol + dx[0];
//
//		if (!outofrange(nrow, ncol))
//		{
//			curRow = nrow;
//			curCol = ncol;
//			arr[curRow][curCol] = 5;
//		}
//	}
//
//	for (int i = 0; i < b; i++)
//	{
//		int nrow = curRow + dy[1];
//		int ncol = curCol + dx[1];
//
//		if (!outofrange(nrow, ncol))
//		{
//			curRow = nrow;
//			curCol = ncol;
//			arr[curRow][curCol] = 5;
//		}
//	}
//
//	curRow = row;
//	curCol = col;
//	for (int i = 0; i < b; i++)
//	{
//		int nrow = curRow + dy[1];
//		int ncol = curCol + dx[1];
//
//		if (!outofrange(nrow, ncol))
//		{
//			curRow = nrow;
//			curCol = ncol;
//			arr[curRow][curCol] = 5;
//		}
//	}
//
//	for (int i = 0; i < a; i++)
//	{
//		int nrow = curRow + dy[0];
//		int ncol = curCol + dx[0];
//
//		if (!outofrange(nrow, ncol))
//		{
//			curRow = nrow;
//			curCol = ncol;
//			arr[curRow][curCol] = 5;
//		}
//	}
//}
//
//void fill(int y, int x, int row, int col, int a, int b, int type)
//{
//	bool visited[20][20] = { false };
//	queue<pair<int, int>> q;
//	arr[row][col] = type;
//	visited[row][col] = true;
//	q.push(make_pair(row, col));
//	
//
//	while (!q.empty())
//	{
//		int curRow = q.front().first;
//		int curCol = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nrow = curRow + dr[i];
//			int ncol = curCol + dc[i];
//
//			if (!visited[nrow][ncol] && !outofrange(nrow, ncol) && arr[nrow][ncol] != 5)
//			{
//				if (type == 1)
//				{
//					// 1
//					if (0 <= nrow && nrow < y + a && 0 <= ncol && ncol <= x)
//					{
//						arr[nrow][ncol] = type;
//						visited[nrow][ncol] = true;
//						q.push(make_pair(nrow, ncol));
//					}
//				}
//				else if (type == 2)
//				{
//					// 2
//					if (0 <= nrow <= y + b && x < ncol < N )
//					{
//						arr[nrow][ncol] = type;
//						visited[nrow][ncol] = true;
//						q.push(make_pair(nrow, ncol));
//					}
//				}
//				else if (type == 3)
//				{
//					// 3
//					if (y + a <= nrow < N && 0 <= ncol < x - a + b)
//					{
//						arr[nrow][ncol] = type;
//						visited[nrow][ncol] = true;
//						q.push(make_pair(nrow, ncol));
//					}
//				}
//				else if (type == 4)
//				{
//					// 4
//					if (y + b < nrow < N && x - a + b <= ncol < N)
//					{
//						arr[nrow][ncol] = type;
//						visited[nrow][ncol] = true;
//						q.push(make_pair(nrow, ncol));
//					}
//				}
//				else if (type == 5)
//				{
//					arr[nrow][ncol] = type;
//					visited[nrow][ncol] = true;
//					q.push(make_pair(nrow, ncol));
//				}
//			}
//		}
//	}
//}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			for (int a = 1; a <= N - 2; a++)
			{
				for (int b = 1; b <= N - 2; b++)
				{
					int flag = 0;

					// y < - x + t
					// 1번 구역
					int t = x + y;
					if (0 < - 0 + t)
						++flag;
					
					// y < x + t
					// 2번
					t = y - x;
					if (N - 1 + t > 0)
						++flag;

					// y + a, x - a
					// y > x + t
					// 3
					t = y - x + 2 * a;
					if (- N + 1 + t < 0)
						++flag;

					// y + b, x + b
					// y > - x + t
					// 4
					t = x + y + 2 * b;
					if (N - 1 + N - 1 - t > 0)
						++flag;

					if (flag < 4)
						continue;

					//memset(arr, 0, sizeof(arr));

					//five(y, x, a, b);

					//fill(y, x, y + 1, x, a, b, 5);

					//fill(y, x, 0, 0, a, b, 1);
					//if (y == 1 && x == 1 && a == 1 && b == 1)
					//{
					//	for (int i = 0; i < N; i++)
					//	{
					//		for (int j = 0; j < N; j++)
					//		{
					//			cout << arr[i][j] << " ";
					//		}
					//		cout << "\n";
					//	}
					//	cout << "\n";
					//}
					//fill(y, x, 0, N - 1, a, b, 2);
					//fill(y, N - 1, 0, x, a, b, 3);
					//fill(y, x, N - 1, N - 1, a, b, 4);

					//if (y == 1 && x == 1 && a == 1 && b == 1)
					//{
					//	for (int i = 0; i < N; i++)
					//	{
					//		for (int j = 0; j < N; j++)
					//		{
					//			cout << arr[i][j] << " ";
					//		}
					//		cout << "\n";
					//	}
					//	cout << "\n";
					//}

					memset(arr, 0, sizeof(arr));
					int cnt[4] = { 0 };
					int total = 0;

					for (int i = 0; i < N; i++)
					{
						for (int j = 0; j < N; j++)
						{
							total += A[i][j];

							// 1
							// 0, 0
							// y < - x + t
							// int t = x + y;
							if (0 <= i && i < y + a && 0 <= j && j <= x && i + j - x - y < 0)
							{
								arr[i][j] = 1;
								cnt[0] += A[i][j];
							}

							// 2
							// y < x + t
							if (0 <= i && i <= y + b && x < j && j < N && i - j - y + x < 0)
							{
								arr[i][j] = 2;
								cnt[1] += A[i][j];
							}

							// 3
							// y + a, x - a
							// y > x + t
							// 3
							//t = y - x - 2 * a;
							if (y + a <= i && i < N && 0 <= j && j < x - a + b && i - j - y + x - 2 * a > 0)
							{
								arr[i][j] = 3;
								cnt[2] += A[i][j];
							}

							// 4
							// y + b, x + b
							// y > - x + t
							if (y + b < i && i < N && x - a + b <= j && j < N && i + j - x - y - 2 * b > 0)
							{
								arr[i][j] = 4;
								cnt[3] += A[i][j];
							}
						}
					}

					vector<int> v;
					int rest = 0;
					for (int t = 0; t < 4; t++)
					{
						v.push_back(cnt[t]);
						rest += cnt[t];
					}
					v.push_back(total - rest);

					sort(v.begin(), v.end());

					if (abs(v.back() - v.front()) < answer)
					{
						//cout << "y: " << y << " x: " << x << "\n";
						//cout << "a: " << a << " b: " << b << "\n";
						answer = abs(v.back() - v.front());
						/*cout << "answer: " << answer << "\n";

						for (int i = 0; i < N; i++)
						{
							for (int j = 0; j < N; j++)
							{
								cout << arr[i][j] << " ";
							}
							cout << "\n";
						}
						cout << "\n";*/
					}
				}
			}
		}
	}

	cout << answer << "\n";
}
