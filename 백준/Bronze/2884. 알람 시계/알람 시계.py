import sys
#sys.stdin = open('bj14235.txt', 'r')

A, B = map(int, input().split())

if (B - 45) < 0:
    B = 60 + (B - 45)
    A = A - 1

elif (B - 45) >= 0:
    B = B - 45

if A < 0:
    A = 24 + A

print('{0} {1}'.format(A, B))