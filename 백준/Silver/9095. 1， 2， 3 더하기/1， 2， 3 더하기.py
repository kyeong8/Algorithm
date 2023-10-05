import sys
sys.setrecursionlimit(10**7)
#sys.stdin = open('input.txt', 'r')

def factorial(num):
    if num == 0:
        return 1
    if num == 1:
        return 1
    return num * factorial(num - 1)

T = int(sys.stdin.readline().rstrip())

for i in range(T):
    n = int(sys.stdin.readline().rstrip())
    cnt = 0
    for j in range(n // 2 + 1):
        for k in range((n - 2 * j) // 3 + 1):
            temp = factorial(n - j - 2 * k) // (factorial(n - 2 * j - 3 * k) * factorial(j) * factorial(k))
            cnt += temp
    print(cnt)