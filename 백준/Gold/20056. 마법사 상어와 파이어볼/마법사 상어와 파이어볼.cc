#include <iostream>
#include <vector>

using namespace std;

struct Fire {
	int mass;
	int speed;
	int direct;
};

int N, M, K;

int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

vector<Fire> fire[51][51];

void move()
{
	vector<Fire> temp[51][51];
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = fire[i][j].size() - 1; k >= 0 ; k--)
			{
				int nrow = i + fire[i][j][k].speed * dr[fire[i][j][k].direct];
				int ncol = j + fire[i][j][k].speed * dc[fire[i][j][k].direct];

				if (nrow > 0)
					nrow = (nrow - 1) % N + 1;
				else
					nrow = N - abs(nrow) % N;
				if (ncol > 0)
					ncol = (ncol - 1) % N + 1;
				else
					ncol = N - abs(ncol) % N;
				temp[nrow][ncol].push_back(Fire{ fire[i][j][k].mass, fire[i][j][k].speed, fire[i][j][k].direct });
				fire[i][j].pop_back();
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (temp[i][j].size() > 1)
			{
				int even = 0;
				int odd = 0;
				int nmass = 0;
				int nspeed = 0;
				for (int k = 0; k < temp[i][j].size(); k++)
				{
					if (temp[i][j][k].direct % 2 == 0)
						even++;
					else
						odd++;
					nmass += temp[i][j][k].mass;
					nspeed += temp[i][j][k].speed;
				}
				nmass /= 5;
				nspeed /= temp[i][j].size();

				if (nmass == 0)
					continue;

				if (even == temp[i][j].size() || odd == temp[i][j].size())
				{
					for (int k = 0; k < 8; k += 2)
						fire[i][j].push_back(Fire{ nmass, nspeed, k });
				}
				else
				{
					for (int k = 1; k < 8; k += 2)
						fire[i][j].push_back(Fire{ nmass, nspeed, k });
				}
			}
			else if (temp[i][j].size() == 1)
				fire[i][j].push_back(Fire{ temp[i][j][0].mass, temp[i][j][0].speed, temp[i][j][0].direct });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fire[r][c].push_back(Fire{ m, s, d });
	}
	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= N; j++)
	//	{
	//		if (!fire[i][j].empty())
	//			cout << fire[i][j][0].mass << " ";
	//		else
	//			cout << "0 ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	for (int i = 0; i < K; i++)
	{
		move();
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 1; j <= N; j++)
		//	{
		//		if (!fire[i][j].empty())
		//			cout << fire[i][j][0].mass << " ";
		//		else
		//			cout << "0 ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
	}
		
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < fire[i][j].size(); k++)
				answer += fire[i][j][k].mass;
		}
	}
	cout << answer << "\n";
}