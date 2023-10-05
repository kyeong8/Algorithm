import sys
from collections import deque
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def bfs(graph, root):
    visited[root] = True
    q = deque([(root, 0)])
    check[root].append(0)

    while q:
        node, color = q.popleft()
        color += 1
        for i in graph[node]:
            if not visited[i]:
                visited[i] = True
                q.append((i, color % 2))
                check[i].append(color % 2)
            else:
                if check[i][0] == color-1:
                    return False
    return True

K = int(input().rstrip())

for _ in range(K):
    V, E = map(int, input().split())
    graph = [[] for _ in range(V+1)]
    check = [[] for _ in range(V+1)] 
    visited = [False] * (V+1)

    for _ in range(E):
        i, j = map(int, input().split())
        graph[i].append(j)
        graph[j].append(i)

    for i in range(1, V+1):
        if not visited[i]:
            if not bfs(graph, i):
                print('NO')
                break
    else:
        print('YES')