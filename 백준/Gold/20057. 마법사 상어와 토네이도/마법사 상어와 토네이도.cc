#include <iostream>

using namespace std;

int dr[] = { 0, 1, 0, -1 };
int dc[] = { -1, 0, 1, 0 };

int arr[500][500] = { 0 };
int answer = 0;
int N;

bool inofrange(int row, int col)
{
	if (1 <= row && row <= N && 1 <= col && col <= N)
		return true;
	return false;
}

void spread(int row, int col, int direct)
{
	int oriSand = arr[row][col];

	int sum = 0;
	int nrow, ncol, cSand;

	// 직진 방향
	nrow = row + 2 * dr[direct];
	ncol = col + 2 * dc[direct];
	cSand = oriSand * 0.05;
	sum += cSand;
	if (!inofrange(nrow, ncol))
		answer += cSand;
	else
		arr[nrow][ncol] += cSand;

	// 왼쪽
	nrow = row + dr[(direct + 1) % 4];
	ncol = col + dc[(direct + 1) % 4];
	cSand = oriSand * 0.07;
	sum += cSand;
	if (!inofrange(nrow, ncol))
		answer += cSand;
	else
		arr[nrow][ncol] += cSand;

	nrow = row + 2 * dr[(direct + 1) % 4];
	ncol = col + 2 * dc[(direct + 1) % 4];
	cSand = oriSand * 0.02;
	sum += cSand;
	if (!inofrange(nrow, ncol))
		answer += cSand;
	else
		arr[nrow][ncol] += cSand;

	nrow = row + dr[direct];
	ncol = col + dc[direct];
	nrow = nrow + dr[(direct + 1) % 4];
	ncol = ncol + dc[(direct + 1) % 4];
	cSand = oriSand * 0.1;
	sum += cSand;
	if (!inofrange(nrow, ncol))
		answer += cSand;
	else
		arr[nrow][ncol] += cSand;

	nrow = row - dr[direct];
	ncol = col - dc[direct];
	nrow = nrow + dr[(direct + 1) % 4];
	ncol = ncol + dc[(direct + 1) % 4];
	cSand = oriSand * 0.01;
	sum += cSand;
	if (!inofrange(nrow, ncol))
		answer += cSand;
	else
		arr[nrow][ncol] += cSand;

	// 오른쪽
	nrow = row + dr[(direct + 3) % 4];
	ncol = col + dc[(direct + 3) % 4];
	cSand = oriSand * 0.07;
	sum += cSand;
	if (!inofrange(nrow, ncol))
		answer += cSand;
	else
		arr[nrow][ncol] += cSand;

	nrow = row + 2 * dr[(direct + 3) % 4];
	ncol = col + 2 * dc[(direct + 3) % 4];
	cSand = oriSand * 0.02;
	sum += cSand;
	if (!inofrange(nrow, ncol))
		answer += cSand;
	else
		arr[nrow][ncol] += cSand;

	nrow = row + dr[direct];
	ncol = col + dc[direct];
	nrow = nrow + dr[(direct + 3) % 4];
	ncol = ncol + dc[(direct + 3) % 4];
	cSand = oriSand * 0.1;
	sum += cSand;
	if (!inofrange(nrow, ncol))
		answer += cSand;
	else
		arr[nrow][ncol] += cSand;

	nrow = row - dr[direct];
	ncol = col - dc[direct];
	nrow = nrow + dr[(direct + 3) % 4];
	ncol = ncol + dc[(direct + 3) % 4];
	cSand = oriSand * 0.01;
	sum += cSand;
	if (!inofrange(nrow, ncol))
		answer += cSand;
	else
		arr[nrow][ncol] += cSand;

	// alpha
	nrow = row + dr[direct];
	ncol = col + dc[direct];
	cSand = oriSand - sum;
	if (!inofrange(nrow, ncol))
		answer += cSand;
	else
		arr[nrow][ncol] += cSand;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	pair<int, int> start;
	start.first = N / 2 + 1;
	start.second = N / 2 + 1;
	int direct = 0;
	int cnt = 0;
	int len = 1;

	while (true)
	{
		bool flag = false;

		for (int i = 0; i < len; i++)
		{
			start.first = start.first + dr[direct];
			start.second = start.second + dc[direct];
			spread(start.first, start.second, direct);

			//cout << "row: " << start.first << " col: " << start.second << " len: " << len << "\n";
			if (start.first == 1 && start.second == 1)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			break;

		cnt++;
		direct = (direct + 1) % 4;

		if (cnt == 2)
		{
			cnt = 0;
			len++;
		}
	}

	cout << answer << "\n";
}