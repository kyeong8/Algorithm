import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
arr = []
for i in range(N):
    x, y = map(int, sys.stdin.readline().split())
    arr.append([x, y])

arr.sort(key=lambda x:(x[1], x[0]))

for i in range(N):
    print('{} {}'.format(arr[i][0], arr[i][1]))
