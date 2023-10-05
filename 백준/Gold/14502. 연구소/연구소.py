import sys
import copy
from collections import deque
#sys.stdin = open('input.txt', 'r')


def bfs(rec, loc):
    q = deque(loc)
    while len(q) > 0:
        r, c = q.popleft()
        rec[r][c] = '2'
        for t in move:
            row, col = t
            if 0 <= r+row < N and 0 <= c+col < M:
                if rec[r+row][c+col] == '0':
                    q.append([r+row, c+col])

    total = 0
    for h in rec:
        total += h.count('0')
    return total


def combination(num, mem, _visited):
    if len(mem) == 3:
        change.append(mem[:])
        return

    for a in range(num, len(zero)):
        if not _visited[a]:
            _visited[a] = 1
            mem.append(zero[a])
            combination(a+1, mem, _visited)
            mem.pop()
            _visited[a] = 0


move = [[-1, 0], [1, 0], [0, -1], [0, 1]]
N, M = map(int, input().split())
arr = []
for _ in range(N):
    arr.append(list(input().split()))

zero = []
poison = []
for i in range(N):
    for j in range(M):
        if arr[i][j] == '0':
            zero.append([i, j])
        elif arr[i][j] == '2':
            poison.append([i, j])

visited = [0 for _ in range(len(zero))]
change = []

combination(0, [], visited)
answer = []

for k in change:
    temp = copy.deepcopy(arr)
    for a in k:
        temp[a[0]][a[1]] = '1'
    answer.append(bfs(temp, poison))

print(max(answer))