import sys
#sys.stdin = open('test.txt', 'r')

C = int(sys.stdin.readline().rstrip())

for i in range(C):
    total = 0
    cnt = 0
    arr = list(map(int, sys.stdin.readline().split()))

    for j in range(1, arr[0]+1):
        total = total + arr[j]

    total = total / arr[0]

    for j in range(1, arr[0]+1):
        if arr[j] > total:
            cnt = cnt + 1

    print('{:.3f}%'.format(cnt / arr[0] * 100))

