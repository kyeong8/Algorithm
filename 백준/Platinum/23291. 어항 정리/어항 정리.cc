#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Info {
	int index;
	int length;
};

int N, K;
int home[100][100] = { 0 };

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool inofrange(int row, int col)
{
	if (0 <= row && row < N && 0 <= col && col < N)
		return true;
	return false;
}

void printMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << home[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool findCondition()
{
	int maxFish = 0;
	int minFish = 10001;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (home[i][j] == 0)
				continue;

			if (maxFish < home[i][j])
				maxFish = home[i][j];
			if (minFish > home[i][j])
				minFish = home[i][j];
		}
	}

	if (abs(maxFish - minFish) <= K)
		return true;
	else
		return false;
}

void addFish()
{
	int minFish = 10001;
	vector<int> mem;
	for (int i = 0; i < N; i++)
	{
		if (minFish > home[0][i])
		{
			mem.clear();
			minFish = home[0][i];
			mem.push_back(i);
		}
		else if (minFish == home[0][i])
			mem.push_back(i);
	}

	for (auto t : mem)
		home[0][t]++;
}

Info arrageHome()
{
	home[1][1] = home[0][0];
	home[0][0] = 0;
	//printMap();
	int idx = 1;
	int length = 0;
	while (true)
	{
		int horizon = 0;
		int vertical = 0;

		for (int i = idx; i < N; i++)
		{
			if (home[1][i] > 0)
				horizon++;
			else
				break;
		}

		while (true)
		{
			if (home[vertical][idx] > 0)
				vertical++;
			else
				break;
		}

		if (idx + vertical + horizon - 1 >= N)
			break;

		for (int j = idx; j < idx + horizon; j++)
		{
			int startCol = idx + horizon;
			int i = 0;
			while (true)
			{
				if (home[i][j] == 0)
					break;

				home[idx + horizon - j][startCol++] = home[i][j];
				home[i][j] = 0;
				i++;
			}
		}
		idx += horizon;
		//printMap();
		length = vertical + 1;
	}

	return Info{ idx, length };
}

void adjustFish(int index, int length)
{
	int temp[100][100] = { 0 };
	for (int i = 0; i < length; i++)
	{
		for (int j = index; j < N; j++)
		{
			if (home[i][j] == 0)
				continue;

			for (int k = 0; k < 4; k++)
			{
				int nrow = i + dr[k];
				int ncol = j + dc[k];

				if (inofrange(nrow, ncol) && home[nrow][ncol] > 0 && home[i][j] > home[nrow][ncol])
				{
					int d = (home[i][j] - home[nrow][ncol]) / 5;
					if (d > 0)
					{
						temp[i][j] -= d;
						temp[nrow][ncol] += d;
					}
				}
			}
		}
	}

	for (int i = 0; i < length; i++)
		for (int j = index; j < N; j++)
			home[i][j] += temp[i][j];
}

void stretching(int index, int length)
{
	int cursor = 0;

	for (int j = index; j < N; j++)
	{
		for (int i = 0; i < length; i++)
		{
			if (home[i][j] > 0)
			{
				home[0][cursor++] = home[i][j];
				if (i == 0 && cursor - 1 == j)
					continue;
				home[i][j] = 0;
			}
		}
	}
}

void specificArrange()
{
	for (int i = 0; i < N / 2; i++)
	{
		home[1][N - 1 - i] = home[0][i];
		home[0][i] = 0;
	}
	//printMap();
	int idx = N / 2 + N / 4;
	for (int j = N / 2 + N / 4 - 1; j >= N / 2; j--)
	{
		home[2][idx] = home[1][j];
		home[3][idx] = home[0][j];
		idx++;
		home[1][j] = 0;
		home[0][j] = 0;
	}
}

int main()
{
	// findCondition();
	// addFish();
	// arrageHome();
	// adjustFish();
	// stretching();
	// specificArrange();
	// stretching();

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> home[0][i];

	int answer = 0;
	while (true)
	{
		if (findCondition())
			break;
		addFish();
		Info ret = arrageHome();
		adjustFish(ret.index, ret.length);
		//printMap();

		stretching(ret.index, ret.length);
		//printMap();

		specificArrange();
		//printMap();

		adjustFish(N - N / 4, 4);
		//printMap();

		stretching(N - N / 4, 4);
		//printMap();
		answer++;
	}
	cout << answer << "\n";
}