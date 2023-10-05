import sys
#sys.stdin = open('input.txt', 'r')

const = 1000000009
T = int(sys.stdin.readline().rstrip())
dp = [1] * (1000001)
for i in range(2, 1000001):
    if i - 3 > 0:
        dp[i] = (dp[i - 1] * 2 - dp[i - 4]) % const
    else:
        dp[i] = (dp[i - 1] * 2) % const

for _ in range(T):
    N = int(sys.stdin.readline().rstrip())
    print(dp[N])