import sys
from collections import deque
sys.setrecursionlimit(10**6)
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def bfs(graph, root):
    bfs_visited[root] = True
    path = []
    queue = deque([root])

    while queue:
        node = queue.popleft()
        path.append(node)
        for i in range(1, N+1):
            if not bfs_visited[i] and i in graph[node]:
                bfs_visited[i] = True
                queue.append(i)
    
    return path

def dfs(graph, root):
    visited = []
    stack = [root]
    
    while(stack):
        node = stack.pop()
        if node not in visited :
            visited.append(node)
            stack.extend(sorted(graph[node], reverse=True))
    return visited

N, M, V = map(int, input().split())
graph = [[] for _ in range(N+1)]
dfs_visited = [False] * (N+1)
bfs_visited = [False] * (N+1)

for _ in range(M):
    i, j = map(int, input().split())
    graph[i].append(j)
    graph[j].append(i)

print(*dfs(graph, V))
print(*bfs(graph, V))