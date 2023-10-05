import sys
#sys.stdin = open('input.txt', 'r')

N, M = map(int, sys.stdin.readline().split())
A = []
B = []
result = [[0] * M for _ in range(N)]
for _ in range(N):
    A.append(list(map(int, sys.stdin.readline().split())))

for _ in range(N):
    B.append(list(map(int, sys.stdin.readline().split())))

for i in range(N):
    for j in range(M):
        result[i][j] = A[i][j] + B[i][j]

for i in range(N):
    print(*result[i])