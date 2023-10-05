import sys
from collections import deque
# sys.setrecursionlimit(10**6)
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def bfs(graph, start, arrive):
    q = deque([start])
    move = [[-2, 1], [-1, 2], [1, 2], [2, 1], [2, -1], [1, -2], [-1, -2], [-2, -1]]
    while q:
        y, x = q.popleft()
        if y == arrive[0] and x == arrive[1]:
            print(graph[y][x])
            break
        for i, j in move:
            row = y+i
            col = x+j
            if 0 <= row < L and 0 <= col < L and graph[row][col] == 0:
                q.append((row, col))
                graph[row][col] = graph[y][x] + 1


k = int(input())

for _ in range(k):
    L = int(input())
    graph = [[0 for _ in range(L)] for _ in range(L)]
    start = tuple(map(int, input().split()))
    arrive = tuple(map(int, input().split()))
    bfs(graph, start, arrive)