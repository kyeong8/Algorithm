import sys
sys.setrecursionlimit(10**6)
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline 

def dfs(graph, v, number):
    if number >= 4:
        print(1)
        exit()
    for i in graph[v]:
        if not visited[i]:
            visited[i] = True
            dfs(graph, i, number+1)
            visited[i] = False


N, M = map(int, input().split())
graph = [[] for _ in range(N)]
visited = [False] * N

for _ in range(M):
    i, j = map(int, input().split())
    graph[i].append(j)
    graph[j].append(i)

for i in range(N):
    visited[i] = True
    dfs(graph, i, 0)
    visited[i] = False
print(0)