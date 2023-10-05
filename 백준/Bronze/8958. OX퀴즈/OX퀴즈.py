import sys
#sys.stdin = open('test.txt', 'r')

N = int(sys.stdin.readline().rstrip())
total = 0
flag = 0
point = 1

for i in range(N):
    arr = list(map(str, sys.stdin.readline().strip()))
    for j in range(len(arr)):
        if arr[j] == 'O':
            if flag == 1:
                point = point + 1
            total = total + point
            flag = 1
        else:
            point = 1
            flag = 0

    print(total)
    total = 0
    flag = 0
    point = 1
