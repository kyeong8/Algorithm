import sys
# sys.stdin = open("bj-solve\input.txt", 'r')

from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
indegree = [0 for _ in range(N)]
graph = [[] for _ in range(N)]
answer = []

for _ in range(M):
    A, B = map(int, input().split())
    graph[A-1].append(B)
    indegree[B-1] += 1

q = deque()

for i in range(len(indegree)):
    if indegree[i] == 0:
        q.append(i+1)

while len(q) > 0:
    i = q.popleft()
    answer.append(i)

    for j in graph[i-1]:
        indegree[j-1] -= 1
        if indegree[j-1] == 0:
            q.append(j)

print(*answer)