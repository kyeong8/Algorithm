import sys
#sys.stdin = open('input.txt', 'r')

M = [list(map(int, sys.stdin.readline().split())) for _ in range(9)]
max = -1
max_i = 0
max_j = 0
for i in range(9):
    for j in range(9):
        if (M[i][j] > max):
            max = M[i][j]
            max_i = i+1;
            max_j = j+1;
print(max)
print(max_i, max_j)