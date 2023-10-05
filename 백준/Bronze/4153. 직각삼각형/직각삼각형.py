import sys
#sys.stdin = open('input.txt', 'r')

while True:
    x, y, z = map(int, sys.stdin.readline().split())
    arr = [x, y, z]
    H = max(arr)
    arr.pop(arr.index(H))
    if x == y == z == 0:
        break
    if (H ** 2) == (arr[0] ** 2) + (arr[1] ** 2):
        print('right')
    else:
        print('wrong')