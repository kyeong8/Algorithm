import sys
#sys.stdin = open('input.txt', 'r')

arr = list(map(int, sys.stdin.readline().split()))
r = arr[1]/2
cnt = 0

for i in range(arr[-1]):
    x, y = map(int, sys.stdin.readline().split())
    if (arr[2] - x) ** 2 + (arr[3] + r - y) ** 2 <= r ** 2 or (arr[2] + arr[0] - x) ** 2 + (arr[3] + r - y) ** 2 <= r ** 2:
        cnt += 1
    elif arr[2] <= x <= arr[2] + arr[0] and arr[3] <= y <= arr[3] + arr[1]:
        cnt += 1

print(cnt)