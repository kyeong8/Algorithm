import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))
dp = [0] * N
total = 0

for i in range(N):
    total += arr[i]
    dp[i] = total
    if total < 0:
        total = 0

print(max(dp))