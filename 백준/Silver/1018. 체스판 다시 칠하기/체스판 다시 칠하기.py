import sys
import copy
#sys.stdin = open('input.txt', 'r')

N, M = map(int, sys.stdin.readline().split())
move = [[1, 0], [0, 1], [-1, 0], [0, -1]]
arr = []
total = []
width = 0
height = 0

for _ in range(N):
    arr.append(list(sys.stdin.readline().rstrip()))

for i in range(N-7):
    for j in range(M-7):
        width = j
        height = i
        copyarr = copy.deepcopy(arr)

        total1 = 0
        for n in range(8):
            for m in range(8):
                for x, y in move:
                    if width <= m + width + y < width + 8 and height <= n + height + x < height + 8:
                        if copyarr[n + height][m + width] == copyarr[n + height + x][m + width + y] == 'W':
                            copyarr[n + height + x][m + width + y] = 'B'
                            total1 += 1
                        elif copyarr[n + height][m + width] == copyarr[n + height + x][m + width + y] == 'B':
                            copyarr[n + height + x][m + width + y] = 'W'
                            total1 += 1

        copyarr = copy.deepcopy(arr)
        if copyarr[height][width] == 'W':
            copyarr[height][width] = 'B'
        else:
            copyarr[height][width] = 'W'

        total2 = 1

        for n in range(8):
            for m in range(8):
                for x, y in move:
                    if width <= m + width + y < width + 8 and height <= n + height + x < height + 8:
                        if copyarr[n + height][m + width] == copyarr[n + height + x][m + width + y] == 'W':
                            copyarr[n + height + x][m + width + y] = 'B'
                            total2 += 1
                        elif copyarr[n + height][m + width] == copyarr[n + height + x][m + width + y] == 'B':
                            copyarr[n + height + x][m + width + y] = 'W'
                            total2 += 1
        if total1 < total2:
            total.append(total1)
        else:
            total.append(total2)

print(min(total))
