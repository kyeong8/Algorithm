import sys
#sys.stdin = open('bj14235.txt', 'r')

A, B = map(int, input().split())
C = int(input())

C = C + A * 60 + B
A = C // 60
B = C % 60

if A > 23:
    A = A - 24

print('{0} {1}'.format(A, B))