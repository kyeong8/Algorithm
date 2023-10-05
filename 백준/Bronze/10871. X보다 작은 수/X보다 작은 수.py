import sys
#sys.stdin = open('bj14235.txt', 'r')

#N = int(sys.stdin.readline().rstrip())
A, B = map(int, sys.stdin.readline().split())
C = list(map(int, sys.stdin.readline().split()))

for i in range(A):
    if C[i] < B:
        print(C[i], end = ' ')