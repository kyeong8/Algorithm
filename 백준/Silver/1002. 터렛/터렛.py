import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())

for i in range(N):
    arr = list(map(int, sys.stdin.readline().split()))
    length = ((arr[0] - arr[3]) ** 2 + (arr[1] - arr[4]) ** 2) ** 0.5

    if arr[0] == arr[3] and arr[1] == arr[4]:
        if arr[2] == arr[5]:
            print(-1)
        else:
            print(0)
    else:
        if length == (arr[2] + arr[5]) or length == abs(arr[2] - arr[5]):
            print(1)
        elif abs(arr[2] - arr[5]) < length < (arr[2] + arr[5]):
            print(2)
        else:
            print(0)