import sys

#sys.stdin = open('bj-solve\input.txt', 'r')

n = int(sys.stdin.readline().rstrip())
a = list(map(int, sys.stdin.readline().split()))
dp = [1] * n

for i in range(0, n):
    for j in range(i, n):
        if a[i] > a[j]:
            dp[j] = max(dp[i] + 1, dp[j])

print(max(dp))