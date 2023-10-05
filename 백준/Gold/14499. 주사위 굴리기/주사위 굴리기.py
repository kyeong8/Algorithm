import sys

#sys.stdin = open('input.txt', 'r')

dice = [0, 0, 0, 0, 0, 0]
move = [[], [0, 1], [0, -1], [-1, 0], [1, 0]]
arr = []


def rotate(func):
    a, b, c, d, e, f = dice[0], dice[1], dice[2], dice[3], dice[4], dice[5]

    if func == 1:
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] = d, b, a, f, e, c
    elif func == 2:
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] = c, b, f, a, e, d
    elif func == 3:
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] = e, a, c, d, f, b
    elif func == 4:
        dice[0], dice[1], dice[2], dice[3], dice[4], dice[5] = b, f, c, d, a, e


N, M, x, y, k = map(int, input().split())

for i in range(N):
    arr.append(list(map(int, input().split())))

command = list(map(int, input().split()))

for i in range(k):
    op = command[i]
    row, col = move[op]

    if 0 <= x + row < N and 0 <= y + col < M:
        x += row
        y += col
        rotate(op)

        if arr[x][y] == 0:
            arr[x][y] = dice[5]
        else:
            dice[5] = arr[x][y]
            arr[x][y] = 0

        print(dice[0])