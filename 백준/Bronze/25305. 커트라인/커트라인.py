import sys
#sys.stdin = open('input.txt', 'r')

N, k = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
arr.sort(reverse=True)

print(arr[k-1])
