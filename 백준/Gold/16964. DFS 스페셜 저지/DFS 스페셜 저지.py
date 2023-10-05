import sys
sys.setrecursionlimit(10**6)
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def dfs(start, result = []):
    result.append(start)
    visited[start] = 1

    for i in edge[start]:
        if not visited[i]:
            dfs(i, result)
    return result

N = int(input().rstrip())
edge = [[] for _ in range(N+1)]

for _ in range(N-1):
    a, b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)

order = [0 for _ in range(N+1)]
path = list(map(int, input().split()))
visited = [0 for _ in range(N+1)]


for idx, i in enumerate(path):
    order[i] = idx

for i in range(1, len(edge)):
    edge[i].sort(key = lambda x : order[x])

res = dfs(1)

if res == path:
    print(1)
else:
    print(0)