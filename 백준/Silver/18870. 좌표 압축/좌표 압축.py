import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))
num = set(arr)
sorting = list(num)
sorting.sort()
d = {}

for i, j in enumerate(sorting):
    d[j] = i

for i in arr:
    print(d[i], end=' ')