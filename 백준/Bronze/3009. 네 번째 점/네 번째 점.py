import sys
#sys.stdin = open('input.txt', 'r')

d = [[], []]

for i in range(3):
    x, y = map(int, sys.stdin.readline().split())
    d[0].extend([x])
    d[1].extend([y])

for i in range(3):
    if d[0].count(d[0][i]) == 1:
        x = d[0][i]
    if d[1].count(d[1][i]) == 1:
        y = d[1][i]

print(x, y)