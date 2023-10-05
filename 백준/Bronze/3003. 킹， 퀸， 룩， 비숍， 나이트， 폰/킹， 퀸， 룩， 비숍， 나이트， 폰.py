import sys
#sys.stdin = open('input.txt', 'r')

arr = [1, 1, 2, 2, 2, 8]
num = list(map(int, sys.stdin.readline().split()))

for i, j in enumerate(arr):
    print(j - num[i], end=' ')