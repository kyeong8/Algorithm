import sys

#sys.stdin = open('input.txt', 'r')


def direction(_d):
    if _d == 0:
        return 3
    else:
        return _d - 1


def boundary(_r, _c):
    if arr[_r][_c] == 1:
        return False
    if 0 <= _r <= N-1 and 0 <= _c <= M-1:
        return True

    return False


def check(_arr, _r, _c):
    for x in range(4):
        _i, _j = move[x]
        if boundary(_i + _r, _j + _c):
            if _arr[_i + _r][_j + _c] == 0:
                return True
    return False


move = [[-1, 0], [0, 1], [1, 0], [0, -1]]
N, M = map(int, input().split())
r, c, d = map(int, input().split())

arr = []
cnt = 0

for _ in range(N):
    arr.append(list(map(int, input().split())))

while True:
    if arr[r][c] == 0:
        arr[r][c] = 2
        cnt += 1

    if check(arr, r, c):
        d = direction(d)
        i, j = move[d]
        if boundary(i + r, j + c):
            if arr[i + r][j + c] == 0:
                r += i
                c += j

    else:
        i, j = move[d]
        r -= i
        c -= j
        if not boundary(r, c):
            break

print(cnt)