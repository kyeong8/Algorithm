import sys

#sys.stdin = open('bj-solve\input.txt', 'r')

n = int(sys.stdin.readline().rstrip())
a = list(map(int, sys.stdin.readline().split()))
dp1 = [1] * n
dp2 = [1] * n
dp = [0] * n

for i in range(0, n):
    for j in range(i):
        if a[i] > a[j]:
            dp1[i] = max(dp1[i], dp1[j] + 1)
for i in range(n-1, -1, -1):
    for j in range(n-1, i-1, -1):
        if a[i] > a[j]:
            dp2[i] = max(dp2[i], dp2[j] + 1)

for i in range(0, n):    
    dp[i] = dp1[i] + dp2[i] - 1

print(max(dp))