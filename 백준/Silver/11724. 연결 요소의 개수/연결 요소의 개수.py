import sys
from collections import deque
sys.setrecursionlimit(10**6)
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def bfs(graph, root):
    visited = []
    discovered = [root]
    q = deque([root])

    while len(q) > 0:
        node = q.popleft()
        visited.append(node)
        undiscovered = set(graph[node]).difference(set(discovered))

        if len(undiscovered) > 0:
            for elem in sorted(undiscovered):
                q.append(elem)
                discovered.append(elem)

    return visited

N, M = map(int, input().split())
graph = [[] for _ in range(N+1)]
s = set()

for _ in range(M):
    i, j = map(int, input().split())
    graph[i].append(j)
    graph[j].append(i)

cnt = 0
for i in range(1, N+1):
    if i not in s:
        temp = bfs(graph, i)
        s.update(temp)
        cnt += 1
print(cnt)