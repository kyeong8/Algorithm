import sys
from collections import deque
# sys.setrecursionlimit(10**6)
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline


M, N = map(int, input().split())
graph = []

for _ in range(N):
    graph.append(list(map(int, input().split())))

start = deque()
for i in range(N):
    for j in range(M):
        if graph[i][j] == 1:
            start.append((i, j, 0))

move = [[-1, 0], [1, 0], [0, -1], [0, 1]]
while start:
    y, x, v = start.popleft()
    answer = v
    for row, col in move:
        new_row = row + y
        new_col = col + x
        if 0 <= new_row < N and 0 <= new_col < M and graph[new_row][new_col] == 0:
            start.append((new_row, new_col, v+1))
            graph[new_row][new_col] = v+1

for i in range(N):
    if 0 in graph[i]:
        print(-1)
        exit()

print(answer)