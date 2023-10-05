import sys

# sys.stdin = open('test.txt', 'r')

M = int(sys.stdin.readline().rstrip())
N = int(sys.stdin.readline().rstrip())
arr = []

for i in range(M, N + 1):
    flag = 0
    if i == 1:
        pass
    else:
        for j in range(2, i):
            if i % j == 0:
                flag += 1
        if flag == 0:
            arr.append(i)

if len(arr) == 0:
    print(-1)
else:
    print(sum(arr))
    print(min(arr))
