import sys
#sys.stdin = open('bj14235.txt', 'r')

N = int(sys.stdin.readline().rstrip())

for i in range(1, N+1):
    A, B = map(int, sys.stdin.readline().split())
    print('Case #{}: {}'.format(i, A+B))