import sys
#sys.stdin = open('input.txt', 'r')

arr = list(map(int, sys.stdin.readline().split()))
total = 0

for i in range(len(arr)):
    total += arr[i] ** 2

print(total % 10)