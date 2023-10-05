import sys
#sys.stdin = open('test.txt', 'r')

N = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))

cnt = N
for i in range(N):
    if arr[i] == 1:
        cnt -= 1
    else:
        for j in range(2, arr[i]):
            if arr[i] % j == 0:
                cnt -= 1
                break

print(cnt)
