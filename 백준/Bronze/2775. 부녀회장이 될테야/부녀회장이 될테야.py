import sys
#sys.stdin = open('test.txt', 'r')

T = int(sys.stdin.readline().rstrip())

for _ in range(T):
    k = int(sys.stdin.readline().rstrip())
    n = int(sys.stdin.readline().rstrip())

    num = [j for j in range(1, n+1)]
    if k > 1:
        for i in range(k-1):
            total = 0
            for m in range(n):
                total = total + num[m]
                num[m] = total
    print(sum(num))