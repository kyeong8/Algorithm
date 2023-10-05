import sys
from collections import deque
# sys.setrecursionlimit(10**6)
# sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def bfs(start):
    q = deque([start])

    while q:
        node = q.popleft()
        visited[node] = 1

        for i in edge[node]:
            if not visited[i]:
                q.append(i)
                visited[i] = 1
                children[node].append(i)        

N = int(input().rstrip())
edge = [[] for _ in range(N+1)]
visited = [0 for _ in range(N+1)]
children = [[] for _ in range(N+1)]

for _ in range(N-1):
    i, j = map(int, input().split())
    edge[i].append(j)
    edge[j].append(i)

path = list(map(int, input().split()))

bfs(1)
idx = 1

if path[0] != 1:
    print(0)
    exit()
else:
    for i in path:
        if set(children[i]) != set(path[idx:idx+len(children[i])]):
            print(0)
            exit()
        else:
            idx += len(children[i])
print(1)