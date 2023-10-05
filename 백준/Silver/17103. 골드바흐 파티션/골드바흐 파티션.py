import sys
#sys.stdin = open('input.txt', 'r')


arr = [False, False] + [True] * 1000000
for i in range(1, 1001):
    if arr[i]:
        for j in range(2*i, 1000001, i):
            arr[j] = False

n = int(sys.stdin.readline().rstrip())
for _ in range(n):
    cnt = 0
    num = int(sys.stdin.readline().rstrip())
    for i in range(2, num//2 + 1):
        if arr[i] and arr[num - i]:
            cnt += 1
    print(cnt)