import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))
V = int(sys.stdin.readline().rstrip())

print(arr.count(V))