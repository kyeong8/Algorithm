import sys
#sys.stdin = open('input.txt', 'r')


def dragon(gen, curve, cur, ex):
    if gen > ex:
        return

    index = len(curve) - 1
    while index >= 0:
        pre = curve[index]
        temp = (pre + 1) % 4
        curve.append(temp)
        cur[0], cur[1] = cur[0] + move[temp][0], cur[1] + move[temp][1]
        if 0 <= cur[0] <= 100 and 0 <= cur[1] <= 100:
            arr[cur[0]][cur[1]] = 1
        index -= 1

    dragon(gen+1, curve, cur, ex)


check = [[0, 0], [0, 1], [1, 1], [1, 0]]
move = [[0, 1], [-1, 0], [0, -1], [1, 0]]
arr = [[0 for _ in range(101)] for _ in range(101)]

N = int(input().rstrip())
for _ in range(N):
    x, y, d, g = map(int, input().split())
    arr[y][x] = 1
    if 0 <= y + move[d][0] <= 100 and 0 <= x + move[d][1] <= 100:
        arr[y + move[d][0]][x + move[d][1]] = 1
    dragon(1, [d], [y + move[d][0], x + move[d][1]], g)

answer = 0
for i in range(100):
    for j in range(100):
        for k in check:
            if 0 <= i+k[0] <= 100 and 0 <= j+k[1] <= 100:
                if arr[i+k[0]][j+k[1]] != 1:
                    break
        else:
            answer += 1

print(answer)