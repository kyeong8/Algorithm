import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
dp = []

for _ in range(N):
    dp.append(list(map(int, sys.stdin.readline().split())))

for i in range(1, N):
    dp[i][0] = dp[i][0] + min(dp[i-1][1], dp[i-1][2])
    dp[i][1] = dp[i][1] + min(dp[i - 1][0], dp[i - 1][2])
    dp[i][2] = dp[i][2] + min(dp[i - 1][1], dp[i - 1][0])

print(min(dp[-1]))