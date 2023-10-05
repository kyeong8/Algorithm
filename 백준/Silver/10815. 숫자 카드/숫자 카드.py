import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))
d = {}
for i in range(N):
    d[arr[i]] = i

M = int(sys.stdin.readline().rstrip())
find = list(map(int, sys.stdin.readline().split()))

for j in find:
    if d.get(j) is None:
        print(0, end=' ')
    else:
        print(1, end=' ')