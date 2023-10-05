import sys
#sys.stdin = open('test.txt', 'r')

M, N = map(int, sys.stdin.readline().split())

for k in range(M, N+1):
    if k == 1:
        continue
    for i in range(2, int(k**0.5)+1):
        if k % i == 0:
            break
    else:
        print(k)
