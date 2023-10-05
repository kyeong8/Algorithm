import sys
#sys.stdin = open('test.txt', 'r')

def fibonacci(N):
    if N < 2:
        return N

    return fibonacci(N - 1) + fibonacci(N - 2)


N = int(sys.stdin.readline().rstrip())

print(fibonacci(N))