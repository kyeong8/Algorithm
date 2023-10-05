import sys

#sys.stdin = open('bj-solve\input.txt', 'r')

n = int(sys.stdin.readline().rstrip())
a = list(map(int, sys.stdin.readline().split()))
dp = [[0] * n for _ in range(2)]

dp[0][0] = a[0]
result = -1001

if n == 1:
    print(a[0])
    exit()

for i in range(1, n):
    dp[0][i] = max(dp[0][i-1]+a[i], a[i])
    dp[1][i] = max(dp[0][i-1], dp[1][i-1]+a[i])
    result = max(result, dp[0][i], dp[1][i])
print(result)