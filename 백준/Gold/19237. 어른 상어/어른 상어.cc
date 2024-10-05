#include <iostream>

using namespace std;

int N, M, K;

struct Shark {
	int row;
	int col;
	int direct;
	bool exit;
};

struct Smell {
	int num;
	int remain;
};

int pd[401][5][5] = { 0 };
int dr[5] = { 0, -1, 1, 0, 0 };
int dc[5] = { 0, 0, 0, -1, 1 };

Smell smell[20][20];
Shark shark[401];

bool noSmell(int row, int col)
{
	if (0 <= row && row < N && 0 <= col && col < N && smell[row][col].remain == 0)
		return true;
	return false;
}

bool mySmell(int row, int col, int num)
{
	if (0 <= row && row < N && 0 <= col && col < N && smell[row][col].num == num)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;

	int arr[20][20] = { 0 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			if (temp > 0)
			{
				shark[temp].row = i;
				shark[temp].col = j;
				shark[temp].exit = false;
				smell[i][j].num = temp;
				smell[i][j].remain = K;
			}
		}
	}

	for (int i = 1; i <= M; i++)
		cin >> shark[i].direct;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				cin >> pd[i][j][k];
			}
		}
	}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << smell[i][j].num << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << smell[i][j].remain << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	int cnt = 0;
	int time = 0;
	while (true)
	{
		if (time > 1000)
			break;
		if (M - cnt == 1)
			break;
		//cout << "time: " << time + 1 << "\n";
		// sharkMove()
		for (int i = 1; i <= M; i++)
		{
			if (shark[i].exit)
				continue;

			int flag = false;
			int row = shark[i].row;
			int col = shark[i].col;
			int direct = shark[i].direct;

			for (int j = 1; j <= 4; j++)
			{
				int ndirect = pd[i][direct][j];
				int nrow = row + dr[ndirect];
				int ncol = col + dc[ndirect];

				if (noSmell(nrow, ncol))
				{
					flag = true;
					shark[i].row = nrow;
					shark[i].col = ncol;
					shark[i].direct = ndirect;
					if (arr[nrow][ncol] == 0)
						arr[nrow][ncol] = i;
					else
					{
						shark[i].exit = true;
						cnt++;
					}
					break;
				}
			}

			if (!flag)
			{
				for (int j = 1; j <= 4; j++)
				{
					int ndirect = pd[i][direct][j];
					int nrow = row + dr[ndirect];
					int ncol = col + dc[ndirect];

					if (mySmell(nrow, ncol, i))
					{
						shark[i].row = nrow;
						shark[i].col = ncol;
						shark[i].direct = ndirect;
						arr[nrow][ncol] = i;
						break;
					}
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// smellDel()
				if (smell[i][j].remain > 0)
				{
					--smell[i][j].remain;
					if (smell[i][j].remain == 0)
						smell[i][j].num = 0;
				}

				// smellAdd()
				if (arr[i][j] != 0)
				{
					smell[i][j].num = arr[i][j];
					smell[i][j].remain = K;
					arr[i][j] = 0;
				}
			}
		}

		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		cout << smell[i][j].num << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		cout << smell[i][j].remain << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		time++;
	}

	if (time > 1000)
		cout << "-1\n";
	else
		cout << time << "\n";
}