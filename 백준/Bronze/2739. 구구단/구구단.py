import sys
#sys.stdin = open('bj14235.txt', 'r')

A = int(input())

for i in range(1, 10):
    print ('{0} * {1} = {2}'.format(A, i, i*A))

