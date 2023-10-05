import sys
from collections import deque
# sys.setrecursionlimit(10**6)
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

move = [[1, 0], [0, -1], [-1, 0], [0, 1]]

def dfs(i, j):
    alpha = graph[i][j]
    stack = [(-1, -1, i, j)]
    cnt = 0

    while stack:
        cnt += 1
        s, t, y, x = stack.pop()
        visited[y][x] = 1

        if cnt >= 4:
            for i, j in move:
                row = y + i
                col = x + j
                if 0 <= row < N and 0 <= col < M and graph[row][col] == alpha and visited[row][col] == 1 and (row != s or col != t):
                    print('Yes')
                    exit()
        for i, j in move:
            row = y + i
            col = x + j
            if 0 <= row < N and 0 <= col < M and graph[row][col] == alpha and visited[row][col] == 0:
                stack.append((y, x, row, col))

N, M = map(int, input().split())
graph = []
visited = [[0 for _ in range(M)] for _ in range(N)]

for _ in range(N):
    graph.append(list(input().rstrip()))

for i in range(N):
    for j in range(M):
        if visited[i][j] == 0:
            dfs(i, j)

print('No')