import sys
sys.setrecursionlimit(10**6)
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def factorial(n):
    if n == 0 or n == 1:
        return 1

    return factorial(n - 1) * n

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    print(int(factorial(m) / (factorial(n) * factorial(m-n))))