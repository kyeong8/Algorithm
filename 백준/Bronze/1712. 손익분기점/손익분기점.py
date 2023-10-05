import sys
#sys.stdin = open('test.txt', 'r')

A, B, C = map(int, sys.stdin.readline().split())

diff = C - B
if diff <= 0:
    print('-1')
else:
    print( A//diff + 1)