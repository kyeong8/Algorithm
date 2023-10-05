import sys
#sys.stdin = open('bj1932.txt', 'r')


def max_path(row, col):
    if row == _size - 1:
        return _triangle[row][col]

    if memo[row][col] == -1:
        path_left = _triangle[row][col] + max_path(row+1, col)
        path_right = _triangle[row][col] + max_path(row+1, col+1)

        memo[row][col] = max(path_left, path_right)

    return memo[row][col]

_triangle = []
memo = []
_size = int(input())
for i in range(_size):
    _triangle.append(list(map(int, input().split())))
    #memo.append([0 for _ in range(i+1)])
    memo.append([-1] * (i+1))

print(max_path(0, 0))
