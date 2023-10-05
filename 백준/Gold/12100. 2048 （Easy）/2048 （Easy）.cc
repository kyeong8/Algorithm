#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
int map[20][20];

int r[4] = { -1, 1, 0, 0 };
int c[4] = { 0, 0, -1, 1 };

int answer = 0;

void dfs(int depth)
{
	if (depth == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				answer = max(answer, map[i][j]);
			}
		}

		return;
	}

	int mem[20][20];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			mem[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			for (int k = 0; k < N; k++)
			{
				bool pass[20] = { false };
				bool temp;
				for (int j = 1; j < N; j++)
				{
					int row = j;
					while (true)
					{
						if (0 <= row + r[i] && row + r[i] < N && map[row + r[i]][k] == 0)
						{
							map[row + r[i]][k] = map[row][k];
							map[row][k] = 0;
							temp = pass[row + r[i]];
							pass[row + r[i]] = pass[row];
							pass[row] = temp;
							row += r[i];
						}
						else if (0 <= row + r[i] && row + r[i] < N && map[row + r[i]][k] == map[row][k])
						{
							if (pass[row] || pass[row + r[i]])
							{
								row += r[i];
								continue;
							}	
							map[row + r[i]][k] = 2 * map[row][k];
							map[row][k] = 0;
							row += r[i];
							pass[row] = true;
						}
						else
							break;
					}
				}
			}

			//if (depth == 0)
			//{
			//	cout << i << "\n";
			//	for (int i = 0; i < N; i++)
			//	{
			//		for (int j = 0; j < N; j++)
			//		{
			//			cout << map[i][j] << " ";
			//		}
			//		cout << "\n";
			//	}
			//	cout << "\n";
			//}

			dfs(depth + 1);

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					map[i][j] = mem[i][j];
				}
			}
		}
		else if (i == 1)
		{
			for (int k = 0; k < N; k++)
			{
				bool pass[20] = { false };
				bool temp;
				for (int j = N - 2; j >= 0; j--)
				{
					int row = j;
					while (true)
					{
						if (0 <= row + r[i] && row + r[i] < N && map[row + r[i]][k] == 0)
						{
							map[row + r[i]][k] = map[row][k];
							map[row][k] = 0;
							temp = pass[row + r[i]];
							pass[row + r[i]] = pass[row];
							pass[row] = temp;
							row += r[i];
						}
						else if (0 <= row + r[i] && row + r[i] < N && map[row + r[i]][k] == map[row][k])
						{
							if (pass[row] || pass[row + r[i]])
							{
								row += r[i];
								continue;
							}
							map[row + r[i]][k] = 2 * map[row][k];
							map[row][k] = 0;
							row += r[i];
							pass[row] = true;
						}
						else
							break;
					}
				}
			}

			//if (depth == 0)
			//{
			//	cout << i << "\n";
			//	for (int i = 0; i < N; i++)
			//	{
			//		for (int j = 0; j < N; j++)
			//		{
			//			cout << map[i][j] << " ";
			//		}
			//		cout << "\n";
			//	}
			//	cout << "\n";
			//}

			dfs(depth + 1);

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					map[i][j] = mem[i][j];
				}
			}
		}
		else if (i == 2)
		{
			for (int j = 0; j < N; j++)
			{
				bool pass[20] = { false };
				bool temp;
				for (int k = 1; k < N; k++)
				{
					int col = k;
					while (true)
					{
						if (0 <= col + c[i] && col + c[i] < N && map[j][col + c[i]] == 0)
						{
							map[j][col + c[i]] = map[j][col];
							map[j][col] = 0;
							temp = pass[col + c[i]];
							pass[col + c[i]] = pass[col];
							pass[col] = temp;
							col += c[i];
						}
						else if (0 <= col + c[i] && col + c[i] < N && map[j][col + c[i]] == map[j][col])
						{
							if (pass[col] || pass[col + c[i]])
							{
								col += c[i];
								continue;
							}
							map[j][col + c[i]] = 2 * map[j][col];
							map[j][col] = 0;
							col += c[i];
							pass[col] = true;
						}
						else
							break;
					}
				}
			}

			//if (depth == 0)
			//{
			//	cout << i << "\n";
			//	for (int i = 0; i < N; i++)
			//	{
			//		for (int j = 0; j < N; j++)
			//		{
			//			cout << map[i][j] << " ";
			//		}
			//		cout << "\n";
			//	}
			//	cout << "\n";
			//}

			dfs(depth + 1);

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					map[i][j] = mem[i][j];
				}
			}
		}
		else if (i == 3)
		{
			for (int j = 0; j < N; j++)
			{
				bool pass[20] = { false };
				bool temp;
				for (int k = N - 2; k >= 0; k--)
				{
					int col = k;
					while (true)
					{
						if (0 <= col + c[i] && col + c[i] < N && map[j][col + c[i]] == 0)
						{
							map[j][col + c[i]] = map[j][col];
							map[j][col] = 0;
							temp = pass[col + c[i]];
							pass[col + c[i]] = pass[col];
							pass[col] = temp;
							col += c[i];
						}
						else if (0 <= col + c[i] && col + c[i] < N && map[j][col + c[i]] == map[j][col])
						{
							if (pass[col] || pass[col + c[i]])
							{
								col += c[i];
								continue;
							}
							map[j][col + c[i]] = 2 * map[j][col];
							map[j][col] = 0;
							col += c[i];
							pass[col] = true;
						}
						else
							break;
					}
				}
			}

			//if (depth == 0)
			//{
			//	cout << i << "\n";
			//	for (int i = 0; i < N; i++)
			//	{
			//		for (int j = 0; j < N; j++)
			//		{
			//			cout << map[i][j] << " ";
			//		}
			//		cout << "\n";
			//	}
			//	cout << "\n";
			//}

			dfs(depth + 1);

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					map[i][j] = mem[i][j];
				}
			}
		}
	}
}

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
			cin >> map[i][j];
		}
	}

	dfs(0);

	cout << answer << "\n";
	return 0;
}