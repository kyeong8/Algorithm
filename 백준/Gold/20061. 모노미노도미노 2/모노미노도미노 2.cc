#include <iostream>

using namespace std;

int N;
int point = 0;

//bool red[4][4] = { false };
bool blue[4][6] = { false };
bool green[6][4] = { false };

bool block(int type, int row, int col)
{
	if (type == 0)
	{
		if (col > 5 || blue[row][col])
			return true;
		return false;
	}
	else if (type == 1)
	{
		if (row > 5 || green[row][col])
			return true;
		return false;
	}
}

void shift(int t, int x, int y)
{
	if (t == 1)
	{
		int brow = x;
		int bcol = 0;

		while (true)
		{
			if (block(0, brow, bcol + 1))
				break;
			bcol++;
		}
		blue[brow][bcol] = true;

		int grow = 0;
		int gcol = y;

		while (true)
		{
			if (block(1, grow + 1, gcol))
				break;
			grow++;
		}
		green[grow][gcol] = true;
	}
	else if (t == 2)
	{
		int brow = x;
		int bcol = 0;

		while (true)
		{
			if (block(0, brow, bcol + 1))
				break;
			bcol++;
		}
		blue[brow][bcol] = true;
		blue[brow][bcol - 1] = true;

		int grow = 0;
		int gcol = y;

		while (true)
		{
			if (block(1, grow + 1, gcol) || block(1, grow + 1, gcol + 1))
				break;
			grow++;
		}
		green[grow][gcol] = true;
		green[grow][gcol + 1] = true;
	}
	else if (t == 3)
	{
		int brow = x;
		int bcol = 0;

		while (true)
		{
			if (block(0, brow, bcol + 1) || block(0, brow + 1, bcol + 1))
				break;
			bcol++;
		}
		blue[brow][bcol] = true;
		blue[brow + 1][bcol] = true;

		int grow = 0;
		int gcol = y;

		while (true)
		{
			if (block(1, grow + 1, gcol))
				break;
			grow++;
		}
		green[grow][gcol] = true;
		green[grow - 1][gcol] = true;
	}
}

void gravity(int type, int index)
{
	if (type == 0)
	{
		for (int j = index - 1; j >= 0; j--)
		{
			for (int i = 0; i < 4; i++)
			{
				blue[i][j + 1] = blue[i][j];
				blue[i][j] = false;
			}
		}
	}
	else if (type == 1)
	{
		for (int i = index - 1; i >= 0; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				green[i + 1][j] = green[i][j];
				green[i][j] = false;
			}
		}
	}
}

void calPoint()
{
	for (int j = 2; j < 6; j++)
	{
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			if (blue[i][j])
				cnt++;
		}
		if (cnt == 4)
		{
			for (int i = 0; i < 4; i++)
				blue[i][j] = false;
			point++;

			gravity(0, j);
		}
	}

	for (int i = 2; i < 6; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 4; j++)
		{
			if (green[i][j])
				cnt++;
		}
		if (cnt == 4)
		{
			for (int j = 0; j < 4; j++)
				green[i][j] = false;
			point++;

			gravity(1, i);
		}
	}
}

void softLine()
{
	int bcnt = 0;
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (blue[i][j])
			{
				bcnt++;
				break;
			}
		}
	}

	for (int j = 5; j > 5 - bcnt; j--)
	{
		for (int i = 0; i < 4; i++)
		{
			blue[i][j] = false;
		}
	}

	for (int i = 0; i < bcnt; i++)
		gravity(0, 5);

	int gcnt = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (green[i][j])
			{
				gcnt++;
				break;
			}
		}
	}

	for (int i = 5; i > 5 - gcnt; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			green[i][j] = false;
		}
	}

	for (int i = 0; i < gcnt; i++)
		gravity(1, 5);
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N;

	int t, x, y;

	for (int i = 0; i < N; i++)
	{
		int ret;
		int bcnt = 0, gcnt = 0;
		cin >> t >> x >> y;

		shift(t, x, y);

		calPoint();

		softLine();

		/*cout << "---------- blue ----------\n";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 2; j < 6; j++)
			{
				if (blue[i][j])
					cout << "O ";
				else
					cout << "X ";
			}
			cout << "\n";
		}
		cout << "\n";

		cout << "---------- green ----------\n";
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (green[i][j])
					cout << "O ";
				else
					cout << "X ";
			}
			cout << "\n";
		}
		cout << "\n";*/
	}

	int cnt = 0;
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (green[i][j])
				cnt++;
			if (blue[j][i])
				cnt++;
		}
	}

	cout << point << "\n";
	cout << cnt << "\n";
}