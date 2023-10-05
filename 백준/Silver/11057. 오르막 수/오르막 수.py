import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
dp = [[0]*10 for i in range(1001)]

for i in range(10):
    dp[1][i] = 1

for i in range(2, N+1):
    temp = sum(dp[i-1])
    dp[i][0] = temp
    for j in range(1, 10):
        temp -= dp[i-1][j-1]
        dp[i][j] = temp

print(sum(dp[N])%10007)