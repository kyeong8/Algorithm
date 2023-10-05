import sys
#sys.stdin = open('input.txt', 'r')

arr = list(map(str, sys.stdin.readline().strip()))
arr.sort(reverse=True)
print(''.join(arr))