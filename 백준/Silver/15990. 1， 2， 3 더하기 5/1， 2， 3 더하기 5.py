import sys
#sys.stdin = open('input.txt', 'r')

M = 100000
r = 1000000009
T = int(sys.stdin.readline().rstrip())

dp = [[0 for _ in range(3)] for i in range(M+1)]
dp[1] = [1, 0, 0]
dp[2] = [0, 1, 0]
dp[3] = [1, 1, 1]

for i in range(4, M+1):
    dp[i][0] = dp[i-1][1] % r + dp[i-1][2] % r
    dp[i][1] = dp[i-2][0] % r + dp[i-2][2] % r
    dp[i][2] = dp[i-3][0] % r + dp[i-3][1] % r

for i in range(T):
    N = int(sys.stdin.readline().rstrip())
    print(sum(dp[N]) % r)