#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int N;
bool blue[6][4];
bool green[6][4];
int blueCnt[6] = { 0 };
int greenCnt[6] = { 0 };
int blueDestroy = 0;
int greenDestroy = 0;

void blueMove(int type, int row, int col)
{
	// 1x1
	int curRow, curCol;
	
	if (type == 1)
	{
		curRow = -1;
		curCol = row;
		while (true)
		{
			++curRow;

			if (curRow >= 5 || blue[curRow + 1][curCol])
			{
				blue[curRow][curCol] = true;
				blueCnt[curRow] += 1;
				break;
			}
		}
	}
	else if (type == 2)
	{
		curRow = -1;
		curCol = row;
		while (true)
		{
			++curRow;
			if (curRow >= 5 || blue[curRow + 1][curCol])
			{
				blue[curRow][curCol] = true;
				blue[curRow - 1][curCol] = true;
				blueCnt[curRow] += 1;
				blueCnt[curRow - 1] += 1;
				break;
			}
		}
	}
	else if (type == 3)
	{
		curRow = -1;
		curCol = row;
		while (true)
		{
			++curRow;

			if (curRow >= 5 || blue[curRow + 1][curCol] || blue[curRow + 1][curCol + 1])
			{
				blue[curRow][curCol] = true;
				blue[curRow][curCol + 1] = true;
				blueCnt[curRow] += 2;
				break;
			}
		}
	}

	for (int i = 2; i < 6; i++)
	{
		if (blueCnt[i] == 4)
		{
			++blueDestroy;
			blueCnt[i] = 0;
			memset(blue[i], false, sizeof(blue[i]));

			for (int j = i - 1; j >= 0; j--)
			{
				for (int k = 0; k < 4; k++)
				{
					bool temp = blue[j + 1][k];
					blue[j + 1][k] = blue[j][k];
					blue[j][k] = temp;
				}

				int cnt = blueCnt[j + 1];
				blueCnt[j + 1] = blueCnt[j];
				blueCnt[j] = cnt;
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (blue[i][j])
			{
				blueCnt[5] = 0;
				memset(blue[5], false, sizeof(blue[5]));

				for (int j = 4; j >= i; j--)
				{
					for (int k = 0; k < 4; k++)
					{
						bool temp = blue[j + 1][k];
						blue[j + 1][k] = blue[j][k];
						blue[j][k] = temp;
					}

					int cnt = blueCnt[j + 1];
					blueCnt[j + 1] = blueCnt[j];
					blueCnt[j] = cnt;
				}
				break;
			}
		}
	}
}

void greenMove(int type, int row, int col)
{
	// 1x1
	int curRow, curCol;
	if (type == 1)
	{
		curRow = -1;
		curCol = col;

		while (true)
		{
			++curRow;
			if (curRow >= 5 || green[curRow + 1][curCol])
			{
				green[curRow][curCol] = true;
				greenCnt[curRow] += 1;
				break;
			}
		}
	}
	else if (type == 2)
	{
		curRow = -1;
		curCol = col;

		while (true)
		{
			++curRow;
			if (curRow >= 5 || green[curRow + 1][curCol] || green[curRow + 1][curCol + 1])
			{
				green[curRow][curCol] = true;
				green[curRow][curCol + 1] = true;
				greenCnt[curRow] += 2;
				break;
			}
		}
	}
	else if (type == 3)
	{
		curRow = -1;
		curCol = col;
		while (true)
		{
			++curRow;
			if (curRow >= 5 || green[curRow + 1][curCol])
			{
				green[curRow][curCol] = true;
				green[curRow - 1][curCol] = true;
				greenCnt[curRow] += 1;
				greenCnt[curRow - 1] += 1;
				break;
			}
		}
	}

	for (int i = 2; i < 6; i++)
	{
		if (greenCnt[i] == 4)
		{
			++greenDestroy;
			greenCnt[i] = 0;
			memset(green[i], false, sizeof(green[i]));

			for (int j = i - 1; j >= 0; j--)
			{
				for (int k = 0; k < 4; k++)
				{
					bool temp = green[j + 1][k];
					green[j + 1][k] = green[j][k];
					green[j][k] = temp;
				}

				int cnt = greenCnt[j + 1];
				greenCnt[j + 1] = greenCnt[j];
				greenCnt[j] = cnt;
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (green[i][j])
			{
				greenCnt[5] = 0;
				memset(green[5], false, sizeof(green[5]));

				for (int j = 4; j >= i; j--)
				{
					for (int k = 0; k < 4; k++)
					{
						bool temp = green[j + 1][k];
						green[j + 1][k] = green[j][k];
						green[j][k] = temp;
					}

					int cnt = greenCnt[j + 1];
					greenCnt[j + 1] = greenCnt[j];
					greenCnt[j] = cnt;
				}
				break;
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
	int t, x, y;
	for (int round = 1; round <= N; round++)
	{
		cin >> t >> x >> y;
		greenMove(t, x, y);
		blueMove(t, x, y);
	}

	//cout << "blue\n";
	//for (int i = 0; i < 6; i++)
	//{
	//	for (int j = 3; j >= 0; j--)
	//	{
	//		cout << blue[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	//for (int i = 2; i < 6; i++)
	//{
	//	cout << blueCnt[i] << "\n";
	//}
	//cout << "\n";

	//cout << "green\n";
	//for (int i = 0; i < 6; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		cout << green[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	//for (int i = 2; i < 6; i++)
	//{
	//	cout << greenCnt[i] << "\n";
	//}
	//cout << "\n";

	cout << blueDestroy + greenDestroy << "\n";
	int cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cnt += blue[i][j];
			cnt += green[i][j];
		}
	}
	cout << cnt << "\n";
}