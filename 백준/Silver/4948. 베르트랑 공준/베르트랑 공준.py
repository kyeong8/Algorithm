import sys
#sys.stdin = open('test.txt', 'r')

arr = []
for k in range(2, 2 * 123456 + 1):
    for i in range(2, int(k ** 0.5) + 1):
        if k % i == 0:
            break
    else:
        arr.append(k)

N = int(sys.stdin.readline().rstrip())
while N != 0:
    cnt = 0
    for j in arr:
        if N < j <= 2 * N:
           cnt += 1
    print(cnt)
    N = int(sys.stdin.readline().rstrip())
