// 달팽이, 폭발, 그룹 및 변환, 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct Snail {
	int rest;
	int length;
	int iter;
	int direct;
};

int N, M;
int map[50][50];
int point;
// 좌 하 우 상
int dr[] = { 0, 1, 0, -1 };
int dc[] = { -1, 0, 1, 0 };

int ar[] = { 0, -1, 1, 0, 0 };
int ac[] = { 0, 0, 0, -1, 1 };

//void snailSearch()
//{
//	int mem[50][50];
//	int row = N / 2 + 1;
//	int col = N / 2 + 1;
//	int rest = 1;
//	int length = 1;
//	int iter = 2;
//	int direct = 0;
//	
//
//	for (int i = 1; i < N * N; i++)
//	{
//		int nrow = row + dr[direct];
//		int ncol = col + dc[direct];
//
//		row = nrow;
//		col = ncol;
//
//		mem[row][col] = i;
//
//		--rest;
//
//		if (rest == 0)
//		{
//			--iter;
//			if (iter == 0)
//			{
//				iter = 2;
//				++length;
//			}
//			rest = length;
//			direct = (direct + 1) % 4;
//		}
//
//	}
//
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			cout << mem[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}

void move()
{
	int mem[50][50] = { 0 };
	Snail first = Snail{ 1, 1, 2, 0 };
	Snail second = Snail{ 1, 1, 2, 0 };

	int frow = N / 2 + 1;
	int fcol = frow;
	int srow = frow;
	int scol = frow;
	for (int i = 1; i < N * N; i++)
	{
		int nfrow = frow + dr[first.direct];
		int nfcol = fcol + dc[first.direct];

		frow = nfrow;
		fcol = nfcol;

		--first.rest;

		if (first.rest == 0)
		{
			--first.iter;
			if (first.iter == 0)
			{
				first.iter = 2;
				++first.length;
			}
			first.rest = first.length;
			first.direct = (first.direct + 1) % 4;
		}

		if (map[frow][fcol] != 0)
		{
			int nsrow = srow + dr[second.direct];
			int nscol = scol + dc[second.direct];

			srow = nsrow;
			scol = nscol;

			--second.rest;

			if (second.rest == 0)
			{
				--second.iter;
				if (second.iter == 0)
				{
					second.iter = 2;
					++second.length;
				}
				second.rest = second.length;
				second.direct = (second.direct + 1) % 4;
			}

			mem[srow][scol] = map[frow][fcol];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			map[i][j] = mem[i][j];
		}
	}
}

void explore()
{
	while (true)
	{
		vector<pair<int, int>> v;
		Snail head = Snail{ 1, 1, 2, 0 };

		int row = N / 2 + 1;
		int col = row;
		int last = 0;
		int lastPoint = point;
		int cnt = 1;
		for (int i = 1; i < N * N; i++)
		{
			int nrow = row + dr[head.direct];
			int ncol = col + dc[head.direct];
			
			if (last == map[nrow][ncol])
				++cnt;
			else
			{
				if (cnt >= 4)
				{
					point += last * cnt;
					for (int j = 0; j < cnt; j++)
					{
						pair<int, int> pos = v[v.size() - 1 - j];
						map[pos.first][pos.second] = 0;
					}
				}
				last = map[nrow][ncol];
				cnt = 1;
			}
			v.push_back(make_pair(nrow, ncol));

			row = nrow;
			col = ncol;

			--head.rest;

			if (head.rest == 0)
			{
				--head.iter;
				if (head.iter == 0)
				{
					head.iter = 2;
					++head.length;
				}
				head.rest = head.length;
				head.direct = (head.direct + 1) % 4;
			}
		}

		if (lastPoint == point)
			break;

		move();
	}
}

void transform()
{
	vector<pair<int, int>> v;
	Snail head = Snail{ 1, 1, 2, 0 };

	int row = N / 2 + 1;
	int col = row;
	int last = 0;
	int cnt = 1;
	for (int i = 1; i < N * N; i++)
	{
		int nrow = row + dr[head.direct];
		int ncol = col + dc[head.direct];

		if (map[nrow][ncol] == 0)
		{
			v.push_back(make_pair(cnt, last));
			break;
		}
		else if (v.size() > (N * N - 1) / 2)
			break;

		if (last == map[nrow][ncol])
			++cnt;
		else
		{
			v.push_back(make_pair(cnt, last));
			last = map[nrow][ncol];
			cnt = 1;
		}

		row = nrow;
		col = ncol;

		--head.rest;

		if (head.rest == 0)
		{
			--head.iter;
			if (head.iter == 0)
			{
				head.iter = 2;
				++head.length;
			}
			head.rest = head.length;
			head.direct = (head.direct + 1) % 4;
		}
	}

	head = Snail{ 1, 1, 2, 0 };

	row = N / 2 + 1;
	col = row;
	for (int i = 1; i < v.size(); i++)
	{
		int num = v[i].first;
		int count = v[i].second;

		for (int j = 0; j < 2; j++)
		{
			int nrow = row + dr[head.direct];
			int ncol = col + dc[head.direct];

			row = nrow;
			col = ncol;

			if (col < 1)
				break;

			if (j == 0)
				map[row][col] = num;
			else
				map[row][col] = count;

			--head.rest;

			if (head.rest == 0)
			{
				--head.iter;
				if (head.iter == 0)
				{
					head.iter = 2;
					++head.length;
				}
				head.rest = head.length;
				head.direct = (head.direct + 1) % 4;
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
	
	point = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	
	int d, s;
	int row = N / 2 + 1;
	int col = N / 2 + 1;
	for (int round = 1; round <= M; round++)
	{
		cin >> d >> s;
		int nrow = row;
		int ncol = col;

		for (int i = 0; i < s; i++)
		{
			nrow = nrow + ar[d];
			ncol = ncol + ac[d];

			map[nrow][ncol] = 0;
		}

		move();

		explore();

		transform();

		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		cout << map[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
	}

	cout << point << "\n";
}