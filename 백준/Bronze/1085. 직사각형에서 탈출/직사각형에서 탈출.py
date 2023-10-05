import sys
#sys.stdin = open('input.txt', 'r')

arr = list(map(int, sys.stdin.readline().split()))
result = []
result.append([arr[0], arr[1], arr[2]-arr[0], arr[3]-arr[1]])
print(min(result[0]))