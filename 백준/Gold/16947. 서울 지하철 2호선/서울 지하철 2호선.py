import sys
from collections import deque
# sys.setrecursionlimit(10**6)
# sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def dfs(start):
    stack = [start]

    while stack:
        node = stack.pop()
        dfs_visited[node] = 1

        for i in edge[node]:
            if not dfs_visited[i]:
                stack.append(i)
                prev[i] = node
            else:
                if i != prev[node]:
                    prev[i] = node
                    k = node
                    while k != i:
                        cycle[k] = 1
                        k = prev[k]
                    cycle[i] = 1
                    return

def bfs(start):
    bfs_visited = [0 for _ in range(N+1)]
    q = deque([(start, 0)])
    mem = 3000

    while q:
        node, k = q.popleft()
        bfs_visited[node] = 1
        for i in edge[node]:
            if not bfs_visited[i]:
                if cycle[i] or mem <= k+1:
                    if mem <= k+1:
                        return mem
                    return k+1
                elif bfs_mem[i]:
                    mem = min(mem, bfs_mem[i] + k + 1)
                q.append((i, k+1))
            

N = int(input().rstrip())

edge = [[] for _ in range(N+1)]
dfs_visited = [0 for _ in range(N+1)]
bfs_mem = [0 for _ in range(N+1)]
prev = [-1 for _ in range(N+1)]
cycle = [0 for _ in range(N+1)]

for _ in range(N):
    s, e = map(int, input().split())
    edge[s].append(e)
    edge[e].append(s)

dfs(1)
for i in range(1, N+1):
    if cycle[i]:
        print(0, end=' ')
    else:
        bfs_mem[i] = bfs(i)
        print(bfs_mem[i], end=' ')