import sys
#sys.stdin = open('input.txt', 'r')

T = int(sys.stdin.readline().rstrip())
arr = []

for i in range(T):
    point = list(map(int, sys.stdin.readline().split()))
    n = int(sys.stdin.readline().rstrip())
    cnt = 0
    for j in range(n):
        arr = list(map(int, sys.stdin.readline().split()))
        if ((arr[0] - point[0]) ** 2 + (arr[1] - point[1]) ** 2) < arr[2] ** 2 and ((arr[0] - point[2]) ** 2 + (arr[1] - point[3]) ** 2) < arr[2] ** 2:
            pass
        elif ((arr[0] - point[0]) ** 2 + (arr[1] - point[1]) ** 2) < arr[2] ** 2:
            cnt += 1
        elif ((arr[0] - point[2]) ** 2 + (arr[1] - point[3]) ** 2) < arr[2] ** 2:
            cnt += 1

    print(cnt)