import sys
#sys.stdin = open('input.txt', 'r')

d = {}
N = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))
for i in range(N):
    if d.get(arr[i]):
        d[arr[i]] = d.get(arr[i]) + 1
    else:
        d[arr[i]] = 1

M = int(sys.stdin.readline().rstrip())
num = list(map(int, sys.stdin.readline().split()))

for i in range(M):
    if d.get(num[i]):
        print(d.get(num[i]), end=' ')
    else:
        print(0, end=' ')