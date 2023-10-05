import sys
#sys.stdin = open('test.txt', 'r')

def factorial(N):
    if N == 0:
        return 1

    return N * factorial(N - 1)

N = int(sys.stdin.readline().rstrip())

print(factorial(N))