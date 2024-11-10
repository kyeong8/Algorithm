#include <stdio.h>

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		scanf("%d", &N);
		scanf("%d", &M);

		int arr[15][15];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		int maxNum = 0;
		for (int i = 0; i <= N - M; i++)
		{
			for (int j = 0; j <= N - M; j++)
			{
				int sum = 0;
				for (int r = 0; r < M; r++)
				{
					for (int c = 0; c < M; c++)
					{
						sum += arr[i + r][j + c];
					}
				}

				if (maxNum < sum)
					maxNum = sum;
			}
		}

		printf("#%d %d\n", test_case, maxNum);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}