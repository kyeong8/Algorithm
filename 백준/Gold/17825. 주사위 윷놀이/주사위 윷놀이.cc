// 게임판을 어떻게 구현
// 파란색 칸과 빨간색 칸을 어떻게 구분
// 4개의 말에 따른 경우의 수


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct Player {
	int pos;
	int type;
	int moveCnt;
	bool exit;
};

Player player[4];
vector<int> arr[4];
int maxPoint;
int dice[10];
vector<pair<int, int>> temp;

void dfs(int point, int index)
{
	if (index == 10)
	{
		if (point > maxPoint)
		{
			maxPoint = point;
			//cout << "maxPoint: " << maxPoint << "\n";
			//for (int num = 0; num < 4; num++)
			//	cout << "num: " << num << " Pos: " << player[num].pos << "\n";

			//for (auto t : temp)
			//	cout << t.first << " ";
			//cout << "\n";
			//for (auto t : temp)
			//	cout << t.second << " ";
			//cout << "\n";
		}
		return;
	}

	for (int num = 0; num < 4; num++)
	{
		if (player[num].exit)
			continue;
		Player mem = player[num];
		int nPos = player[num].pos;

		if (player[num].type == 0 && (nPos == 10 || nPos == 20 || nPos == 30))
			player[num].type = nPos / 10;

		// 13, 
		if (arr[player[num].type].size() - 1 <= player[num].moveCnt + dice[index])
		{
			player[num].exit = true;
			player[num].moveCnt = arr[player[num].type].size() - 1;
			nPos = 0;
		}
		else
		{
			player[num].moveCnt += dice[index];
			nPos = arr[player[num].type][player[num].moveCnt];
		}

		//cout << "num: " << num << " nPos: " << nPos << "\n";

		bool flag = false;
		for (int i = 0; i < 4; i++)
		{
			if (i == num)
				continue;
			if (!player[num].exit && (player[i].type == player[num].type && player[i].moveCnt == player[num].moveCnt))
			{
				/*cout << "player[num].type: " << player[num].type << "\n";
				cout << "num: " << num << " i: " << i << " nPos: " << nPos << "\n";*/
				flag = true;
				break;
			}
			else if (player[i].pos == nPos && nPos == 40)
			{
				/*cout << "player[num].type: " << player[num].type << "\n";
				cout << "num: " << num << " i: " << i << " nPos: " << nPos << "\n";*/
				flag = true;
				break;
			}
			else if ((player[i].type > 0 && player[num].type > 0 && player[i].pos == nPos) && (nPos == 25 || nPos == 30 || nPos == 35))
			{
				/*cout << "player[num].type: " << player[num].type << "\n";
				cout << "num: " << num << " i: " << i << " nPos: " << nPos << "\n";*/
				flag = true;
				break;
			}
		}

		if (flag)
		{
			player[num] = mem;
			continue;
		}

		player[num].pos = nPos;

		//
		//cout << "num: " << num << " player[num].pos: " << player[num].pos << "\n";
		//temp.push_back(make_pair(player[num].pos, player[num].moveCnt));
		dfs(point + player[num].pos, index + 1);
		//temp.pop_back();

		player[num] = mem;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < 10; i++)
		cin >> dice[i];

	maxPoint = 0;
	for (int i = 0; i < 4; i++)
	{
		player[i] = { 0, 0, 0, false };
		arr[i].push_back(0);
	}

	for (int i = 0; i <= 40; i += 2)
		arr[0].push_back(i + 2);

	for (int i = 1; i < 4; i++)
	{
		for (int j = 2; j <= i * 10; j += 2)
			arr[i].push_back(j);
	}
		
	arr[1].push_back(13);
	arr[1].push_back(16);
	arr[1].push_back(19);
	
	arr[2].push_back(22);
	arr[2].push_back(24);

	arr[3].push_back(28);
	arr[3].push_back(27);
	arr[3].push_back(26);

	for (int i = 1; i < 4; i++)
	{
		for (int j = 25; j <= 40; j += 5)
			arr[i].push_back(j);
		arr[i].push_back(42);
	}


	//for (int i = 0; i < 4; i++)
	//{
	//	for (auto a : arr[i])
	//		cout << a << " ";
	//	cout << "\n";
	//}

	dfs(0, 0);

	cout << maxPoint << "\n";
}