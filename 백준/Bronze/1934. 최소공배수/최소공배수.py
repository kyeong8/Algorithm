import sys
#sys.stdin = open('input.txt', 'r')


def GCD(a, b):
    while b != 0:
        a, b = b, a%b
    return a


def LCM(a, b, c):
    return (a*b)//c

N = int(sys.stdin.readline().rstrip())

for i in range(N):
    A, B = map(int, sys.stdin.readline().split())
    C = GCD(A, B)
    print(LCM(A, B, C))