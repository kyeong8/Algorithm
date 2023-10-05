import sys
#sys.stdin = open('bj14235.txt', 'r')

N = int(input())
K = 0
for i in range(1, N+1):
    K = K + i

print(K)