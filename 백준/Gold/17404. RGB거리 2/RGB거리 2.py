import sys
import copy
#sys.stdin = open("bj-solve\input.txt", 'r')
n = int(sys.stdin.readline().rstrip())

dp1 = [[0, 0, 0]]
dp2 = [[0, 0, 0]]
dp3 = [[0, 0, 0]]

for i in range(n):
    dp1.append(list(map(int, sys.stdin.readline().split())))
    
dp2 = copy.deepcopy(dp1)
dp3 = copy.deepcopy(dp1)

dp1[1] = [dp1[1][0], 10000, 10000]
dp1[n] = [10000, dp1[n][1], dp1[n][2]]

dp2[1] = [10000, dp2[1][1], 10000]
dp2[n] = [dp2[n][0], 10000, dp2[n][2]]

dp3[1] = [10000, 10000, dp3[1][2]]
dp3[n] = [dp3[n][0], dp3[n][1], 10000]


for i in range(2, n+1):
    for j in range(3):
        dp1[i][j] += min(dp1[i-1][(j+1)%3], dp1[i-1][(j+2)%3])
        dp2[i][j] += min(dp2[i-1][(j+1)%3], dp2[i-1][(j+2)%3])
        dp3[i][j] += min(dp3[i-1][(j+1)%3], dp3[i-1][(j+2)%3])

print(min(min(dp1[n]), min(dp2[n]), min(dp3[n])))