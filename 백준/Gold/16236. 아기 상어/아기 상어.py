import sys
from collections import deque
#sys.stdin = open('input.txt', 'r')


def eat(p, depth):
    visited = [[0 for _ in range(N)] for _ in range(N)]
    q = deque([[p[0], p[1], depth]])
    compare = []
    mind = 401
    visited[p[0]][p[1]] = 1
    while len(q) > 0:
        r, c, d = q.popleft()
        if mind < d:
            break
        if 0 < arr[r][c] <= size-1:
            if len(compare) == 0:
                mind = d
            compare.append([r, c])

        for dr, dc in move:
            if 0 <= r+dr < N and 0 <= c+dc < N:
                if arr[r+dr][c+dc] <= size and not visited[r+dr][c+dc]:
                    visited[r+dr][c+dc] = 1
                    q.append([r+dr, c+dc, d+1])

    if len(compare) == 0:
        return 0

    compare.sort(key=lambda x: (x[0], x[1]))
    fish[arr[compare[0][0]][compare[0][1]]] -= 1
    position[0], position[1] = compare[0][0], compare[0][1]
    arr[compare[0][0]][compare[0][1]] = 0

    return mind


def shark():
    global answer
    global hungry
    global size

    while sum(fish[:min(size, 7)]) > 0:
        distance = eat(position, 0)
        if distance == 0:
            break
        answer += distance
        hungry += 1

        if hungry == size:
            hungry = 0
            size += 1


move = [[-1, 0], [0, -1], [1, 0], [0, 1]]
fish = [0 for i in range(7)]
position = [-1, -1]
size = 2
hungry = 0
answer = 0
arr = []
N = int(input().rstrip())
for i in range(N):
    temp = list(map(int, input().split()))
    arr.append(temp)
    for idx, j in enumerate(temp):
        if j != 0 and j != 9:
            fish[j] += 1
        if j == 9:
            position[0], position[1] = i, idx

arr[position[0]][position[1]] = 0
shark()
print(answer)

