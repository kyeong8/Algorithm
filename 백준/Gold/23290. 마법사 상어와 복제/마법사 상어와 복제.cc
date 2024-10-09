#include <iostream>
#include <vector>

using namespace std;

struct Info {
	int row;
	int col;
};

vector<int> fish[4][4];
Info shark;
int M, S;
int dr[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int sr[] = { -1, 0, 1, 0 };
int sc[] = { 0, -1, 0, 1 };

int smell[4][4] = { 0 };
vector<int> mem[4][4];
vector<Info> memMove;
vector<Info> bestMove;

int maxEat = 0;

bool inofrange(int row, int col)
{
	if (0 <= row && row < 4 && 0 <= col && col < 4)
		return true;
	return false;
}

void copyMagic()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mem[i][j].clear();
			mem[i][j] = fish[i][j];
			//for (auto t : fish[i][j])
			//	mem[i][j].push_back(t);
		}
	}
}

void fishMove()
{
	vector<int> temp[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (auto t : fish[i][j])
			{
				int flag = false;
				for (int k = 0; k < 8; k++)
				{ 
					int direct = (t + 7 * k) % 8;
					int row = i + dr[direct];
					int col = j + dc[direct];

					if (!(row == shark.row && col == shark.col) && inofrange(row, col) && smell[row][col] == 0)
					{
						flag = true;
						temp[row][col].push_back(direct);
						break;
					}
				}

				if (!flag)
					temp[i][j].push_back(t);
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fish[i][j].clear();
			fish[i][j] = temp[i][j];
			//for (auto t : temp[i][j])
			//	fish[i][j].push_back(t);
		}
	}
}

void sharkMove(int row, int col, int depth, int eat)
{
	if (depth > 3)
	{
		if (maxEat < eat)
		{
			bestMove.clear();
			shark.row = row;
			shark.col = col;
			maxEat = eat;
			bestMove = memMove;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nrow = row + sr[i];
		int ncol = col + sc[i];

		if (inofrange(nrow, ncol))
		{
			vector<int> temp;
			temp = fish[nrow][ncol];
			fish[nrow][ncol].clear();
			memMove.push_back(Info{nrow, ncol});

			sharkMove(nrow, ncol, depth + 1, eat + temp.size());

			fish[nrow][ncol] = temp;
			memMove.pop_back();
		}
	}
}

void smellDel()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (smell[i][j] > 0)
				smell[i][j]--;
}

void pasteMagic()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (auto t : mem[i][j])
				fish[i][j].push_back(t);
			mem[i][j].clear();
		}
	}
}

void printMap()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << fish[i][j].size() << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void printSmell()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << smell[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	// copyMagic();
	// fishMove();
	// sharkMove();
	// smellDel();
	// pasteMagic();

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
		
	cin >> M >> S;
	int x, y, d;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> d;
		fish[x - 1][y - 1].push_back(d - 1);
	}
	cin >> shark.row >> shark.col;
	shark.row--;
	shark.col--;

	int trow, tcol;
	for (int step = 0; step < S; step++)
	{
		copyMagic();
		fishMove();
		//printMap();

		maxEat = -1;
		memMove.clear();
		bestMove.clear();
		trow = shark.row;
		tcol = shark.col;

		sharkMove(trow, tcol, 1, 0);

		for (auto t : bestMove)
		{
			//cout << "t.row: " << t.row + 1 << " t.col: " << t.col + 1 << "\n";
			if (fish[t.row][t.col].size() > 0)
			{
				smell[t.row][t.col] = 3;
				fish[t.row][t.col].clear();
			}
		}

		smellDel();
		pasteMagic();

		//cout << "shark.row: " << shark.row + 1<< " shakr.col: " << shark.col + 1 << "\n";
		//printMap();
		//printSmell();
	}

	int answer = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			answer += fish[i][j].size();
	cout << answer << "\n";
}