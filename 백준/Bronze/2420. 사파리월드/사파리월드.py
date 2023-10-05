import sys
#sys.stdin = open('input.txt', 'r')

N, M = map(int, sys.stdin.readline().split())
print(abs(N-M))