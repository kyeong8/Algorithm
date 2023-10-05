import sys
#sys.stdin = open('bj14235.txt', 'r')

N = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))

print('{} {}'.format(min(arr), max(arr)))