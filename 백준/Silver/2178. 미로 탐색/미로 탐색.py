import sys
from collections import deque
# sys.setrecursionlimit(10**6)
# sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def bfs(graph, y, x):
    q = deque([(y, x)])
    move = [[-1, 0], [1, 0], [0, -1], [0, 1]]

    while q:
        y, x = q.popleft()
        for i, j in move:
            row = y + i
            col = x + j
            if check(graph, row, col):
                q.append((row, col))
                graph[row][col] = graph[y][x] + 1


def check(graph, row, col):
    if row < 0 or row >= N:
        return False
    elif col < 0 or col >= M:
        return False
    elif graph[row][col] == 1:
        return True

N, M = map(int, input().split())
graph = []
for _ in range(N):
    graph.append(list(map(int, input().rstrip())))

bfs(graph, 0, 0)
print(graph[N-1][M-1])