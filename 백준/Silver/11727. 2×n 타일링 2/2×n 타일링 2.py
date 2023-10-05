import sys
sys.setrecursionlimit(10**7)
#sys.stdin = open('input.txt', 'r')

def factorial(num):
    if num == 0:
        return 1
    if num == 1:
        return 1
    return num * factorial(num - 1)


n = int(sys.stdin.readline().rstrip())
cnt = 1
for i in range(1, n//2 + 1):
    temp = 2 ** i * (factorial(n-i) // (factorial(n - 2*i) * factorial(i)))
    cnt += temp
print(cnt%10007)