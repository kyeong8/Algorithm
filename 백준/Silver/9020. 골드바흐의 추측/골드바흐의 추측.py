import sys
#sys.stdin = open('test.txt', 'r')

N = int(sys.stdin.readline().rstrip())

arr = []
partition = [0, 0]

for k in range(2, 10001):
    for i in range(2, int(k ** 0.5) + 1):
        if k % i == 0:
            break
    else:
        arr.append(k)

for j in range(N):
    M = int(sys.stdin.readline().rstrip())
    i = M // 2
    while True:
        if i in arr and (M - i) in arr:
            partition[0] = i
            partition[1] = M - i
            break
        i -= 1

    print('{} {}'.format(partition[0], partition[1]))
