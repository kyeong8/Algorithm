import sys
#sys.stdin = open("bj-solve\input.txt", 'r')

n = int(sys.stdin.readline().rstrip())
arr = []
for _ in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))    

for i in arr:
    result = -1
    M, N, x, y = i[0], i[1], i[2], i[3]
    temp = x 
    for i in range(1, 40001):
        if y % N == temp % N:
            result = temp
            break
        temp = x + M * i
    print(result)