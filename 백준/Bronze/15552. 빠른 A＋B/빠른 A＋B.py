import sys
#sys.stdin = open('bj14235.txt', 'r')

N = int(sys.stdin.readline().rstrip())

for i in range(N
               ):
    A, B = map(int, sys.stdin.readline().split())
    print(A + B)