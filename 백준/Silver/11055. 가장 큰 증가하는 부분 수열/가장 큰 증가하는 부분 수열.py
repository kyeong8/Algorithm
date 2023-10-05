import sys

#sys.stdin = open('bj-solve\input.txt', 'r')

n = int(sys.stdin.readline().rstrip())
a = list(map(int, sys.stdin.readline().split()))
dp = a[:]

for i in range(1, n):
    for j in range(i):
        if a[i] > a[j]:
            dp[i] = max(dp[i], dp[j] + a[i])

print(max(dp))