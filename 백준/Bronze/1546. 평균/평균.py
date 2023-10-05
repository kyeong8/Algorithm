import sys
#sys.stdin = open('test.txt', 'r')

N = int(sys.stdin.readline().rstrip())
total = 0
arr = list(map(int, sys.stdin.readline().split()))
m = max(arr)
for i in range(N):
    total = total + arr[i] / m * 100


print(total / N)
