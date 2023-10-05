import sys
#sys.stdin = open('input.txt', 'r')

N, M = map(int, sys.stdin.readline().split())
arr = []
d = {}
for i in range(N):
    temp = sys.stdin.readline().rstrip()
    d[temp] = i + 1
for i in range(M):
    temp = sys.stdin.readline().rstrip()
    arr.append(temp)

cnt = 0
for j in range(M):
    if d.get(arr[j]):
        cnt += 1

print(cnt)