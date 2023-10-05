import sys
import copy
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
A = list(map(int, sys.stdin.readline().split()))
dp = [[i] for i in A]

for i in range(1, N):
    for j in range(i):
        if A[i] > A[j]:
            if len(dp[i]) < len(dp[j]) + 1:
                temp = copy.deepcopy(dp[j])
                temp.append(A[i])
                dp[i] = temp

a = max(len(dp[i]) for i in range(N))
for i in range(N):
    if len(dp[i]) == a:
        print(a)
        print(*dp[i])
        break
