import sys
#sys.stdin = open('test.txt', 'r')

M = int(sys.stdin.readline().rstrip())
N = sys.stdin.readline().rstrip()

arr = list(N)
total = 0

for i in range(len(arr)):
    total = total + int(arr[i])

print(total)


