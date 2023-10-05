import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
arr = []

for i in range(N):
    temp = list(sys.stdin.readline().split())
    if temp[0] == 'push':
        arr.append(temp[1])
    elif temp[0] == 'pop':
        if len(arr) == 0:
            print(-1)
        else:
            print(arr.pop(0))
    elif temp[0] == 'size':
        print(len(arr))
    elif temp[0] == 'empty':
        if len(arr) == 0:
            print(1)
        else:
            print(0)
    elif temp[0] == 'front':
        if len(arr) == 0:
            print(-1)
        else:
            print(arr[0])
    elif temp[0] == 'back':
        if len(arr) == 0:
            print(-1)
        else:
            print(arr[-1])
