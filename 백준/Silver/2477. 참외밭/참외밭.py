import sys
#sys.stdin = open('input.txt', 'r')

K = int(sys.stdin.readline().rstrip())
arr = [[], [], [], []]
d1 = [[1, 3, 1, 4, 2, 3], [3, 2, 3, 1, 4, 2], [2, 4, 2, 3, 1, 4], [4, 1, 4, 2, 3, 1]]
direction1 = []
direction2 = []

mem = []
for i in range(6):
    num, length = map(int, sys.stdin.readline().split())
    arr[num - 1].extend([length])
    direction1.extend([num])
    direction2.extend([length])


index = 0
add = 0
flag = 0
escape = 0
for i in range(len(d1)):
    for k in range(6):
        for j in range(len(d1[i])):
            if d1[i][j] == direction1[(j + k) % 6]:
                flag += 1
            else:
                flag = 0
                break
        if flag == 6:
            index = i
            add = k
            escape = 1
            break
    if escape == 1:
        break

x = [add, add + 1]

area = 1
for i in range(4):
    if len(arr[i]) == 1:
        area = area * arr[i][0]

print(K * (area - (direction2[(x[0]) % 6] * direction2[(x[1]) % 6])))
