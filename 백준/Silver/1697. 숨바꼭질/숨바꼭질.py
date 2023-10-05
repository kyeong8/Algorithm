import sys
from collections import deque
# sys.setrecursionlimit(10**6)
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

n, m = map(int, input().split())
MAX = 10 ** 5 + 1
move = [-1, 1, 0]
q = deque([n])
visited = [0] * MAX

while q:
    s = q.popleft()
    if s == m:
        print(visited[s])
        break
    for i in (s-1, s+1, 2*s):
        if 0 <= i < MAX and not visited[i]: 
                q.append(i)
                visited[i] = visited[s] + 1