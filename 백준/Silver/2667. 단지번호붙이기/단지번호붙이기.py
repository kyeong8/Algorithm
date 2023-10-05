import sys
from collections import deque
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def bfs(graph, i, j):
    visited = []
    graph[i][j] = '0'
    q = deque([(i, j)])
    move = [[-1, 0], [1, 0], [0, -1], [0, 1]]

    while q:
        i, j = q.popleft()
        visited.append((i, j))

        for row, col in move:
            new_row = row + i
            new_col = col + j
            if check(graph, new_row, new_col):
                graph[new_row][new_col] = '0'
                q.append((new_row, new_col))
    
    return visited

def check(graph, row, col):
    if row < 0 or row >= n:
        return False
    elif col < 0 or col >= n:
        return False
    elif graph[row][col] == '0':
        return False
    
    if graph[row][col] == '1':
        return True

n = int(input().rstrip())
graph = []
for _ in range(n):
    graph.append(list(input()))

answer = []

for i in range(n):
    for j in range(n):
        if graph[i][j] == '1':
            answer.append(bfs(graph, i, j))

print(len(answer))
answer.sort(key= lambda x : len(x))

for i in range(len(answer)):
    print(len(answer[i]))